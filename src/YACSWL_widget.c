/******************************************************************************
* Copyright(c) 2022 Thibaut DONTAIL
*
* This file is part of YACSWL.
*
* YACSWL is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* YACSWL is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with YACSWL.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

/******************** FILE HEADER ********************************************/
/**\addtogroup ModuleName_External_Documentation
 * \{ */
 /**\addtogroup SubModuleName
  * \{ */

  /**
   * \file YACSWL_widget.c
   *
   * File description
   * \author Thibaut DONTAIL
   * \date 12 Aug. 2022
   */

   /**
    * \cond INTERNAL_DOC
    *
    * \mainpage External documentation of module
    *
    * \section Description
    * This module does what you want him to do....
    *
    * \section Features
    * The main features of the module are described here.
    *
    * \endcond
    */

    /******************** INCLUDES ***********************************************/

#include <string.h>

#include "YACSWL_widget.h"


/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

static YACSWL_widget_update_sizes(YACSWL_widget_t* widge, bool is_resized);

/******************** API FUNCTIONS ******************************************/

void YACSWL_widget_init(YACSWL_widget_t* widget)
{
    if (widget != NULL)
    {
        memset(widget, 0, sizeof(widget));
        widget->pixel_foreground = YACSGL_P_BLACK;
        widget->pixel_background = YACSGL_P_WHITE;
        widget->border_width = 1u;
        widget->margin_left = 2u;
        widget->margin_top = 2u;
        widget->margin_right = 2u;
        widget->margin_bottom = 2u;
        widget->is_displayed = true;
    }
}

void YACSWL_widget_draw(YACSWL_widget_t* widget, YACSGL_frame_t* frame)
{
    if ((widget != NULL) && (frame != NULL))
    {
        if (widget->is_displayed)
        {
            if (!widget->skip_generic_draw_func)
            {
                // Generic draw :
                // - draw background
                // - draw borders
                // - draw childrens
                if (!widget->is_transparent_background)
                {
                    YACSGL_rect_fill(frame, widget->x_top_width, widget->y_top_heigth, widget->x_bottom_width, widget->y_bottom_heigth, widget->pixel_background);
                }
                for (uint8_t i = 1; i <= widget->border_width; i++)
                {
                    YACSGL_rect_line(frame, 
                                     widget->x_top_width + (i - 1u), 
                                     widget->y_top_heigth + (i - 1u),
                                     widget->x_bottom_width - (i + 1u), 
                                     widget->y_bottom_heigth - (i + 1u),
                                     widget->pixel_foreground);
                }

                YACSWL_widget_t* current = widget->childrens;
                if (current != NULL)
                {
                    // Save frame offset before drawing childrens
                    uint16_t saved_offset_x = frame->offset_x;
                    uint16_t saved_offset_y = frame->offset_y;

                    // Compute new offsets
                    frame->offset_x += widget->x_top_width;
                    frame->offset_y += widget->y_top_heigth;

                    // Draw childrens
                    while (current != NULL)
                    {
                        YACSWL_widget_draw(current, frame);
                        current = current->next;
                    }

                    // Restore offset
                    frame->offset_x = saved_offset_x;
                    frame->offset_y = saved_offset_y;
                }
            }

            // Specific draw
            if (widget->draw_func != NULL)
            {
                widget->draw_func(widget, frame);
            }
        }
    }
}

void YACSWL_widget_add_child(YACSWL_widget_t* widget, YACSWL_widget_t* child)
{
    if ((widget != NULL) && (child != NULL) && (child->parent == NULL))
    {
        YACSWL_widget_t* previous = NULL;
        YACSWL_widget_t* current = widget->childrens;
        while (current != NULL)
        {
            if (child->z_order > current->z_order)
            {
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (previous == NULL)
        {
            widget->childrens = child;
        }
        else
        {
            previous->next = child;
        }
        child->next = current;
        child->parent = widget;
    }
}

void YACSWL_widget_remove_child(YACSWL_widget_t* widget, YACSWL_widget_t* child)
{
    if ((widget != NULL) && (child != NULL) && (child->parent == widget))
    {
        YACSWL_widget_t* current = widget->childrens;
        if (current == child)
        {
            widget->childrens = current->next;
        }
        else
        {
            while (current->next != NULL)
            {
                if (current->next == child)
                {
                    current->next = child->next;
                    break;
                }
                else
                {
                    current = current->next;
                }
            }
        }
        child->parent = NULL;
        child->next = NULL;
    }
}

void YACSWL_widget_set_pos(YACSWL_widget_t* widget, uint16_t x, uint16_t y)
{
    if (widget != NULL)
    {
        widget->x_top_width = x;
        widget->y_top_heigth = y;

        YACSWL_widget_update_sizes(widget, false);
    }
}

uint16_t YACSWL_widget_get_pos_x(YACSWL_widget_t* widget)
{
    uint16_t x = 0;
    if (widget != NULL)
    {
        x = widget->x_top_width;
    }
    return x;
}

uint16_t YACSWL_widget_get_pos_y(YACSWL_widget_t* widget)
{
    uint16_t y = 0;
    if (widget != NULL)
    {
        y = widget->y_top_heigth;
    }
    return y;
}

void YACSWL_widget_set_size(YACSWL_widget_t* widget, uint16_t width, uint16_t height)
{
    if (widget != NULL)
    {
        widget->width = width;
        widget->height = height;
            
        YACSWL_widget_update_sizes(widget, true);
    }
}

void YACSWL_widget_set_margins(YACSWL_widget_t* widget, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom)
{
    if (widget != NULL)
    {
        widget->margin_left = left;
        widget->margin_top = top;
        widget->margin_right = right;
        widget->margin_bottom = bottom;

        YACSWL_widget_update_sizes(widget, true);
    }
}

void YACSWL_widget_set_border_width(YACSWL_widget_t* widget, uint8_t width)
{
    if (widget != NULL)
    {
        widget->border_width = width;

        YACSWL_widget_update_sizes(widget, true);
    }
}

void YACSWL_widget_set_z_order(YACSWL_widget_t* widget, uint8_t z_order)
{
    if (widget != NULL)
    {
        widget->z_order = z_order;

        if (widget->parent != NULL)
        {
            YACSWL_widget_remove_child(widget->parent, widget);
            YACSWL_widget_add_child(widget->parent, widget);
        }
    }
}

void YACSWL_widget_set_displayed(YACSWL_widget_t* widget, bool is_displayed)
{
    if (widget != NULL)
    {
        widget->is_displayed = is_displayed;
    }
}

void YACSWL_widget_set_foreground_color(YACSWL_widget_t* widget, YACSGL_pixel_t pixel)
{
    if (widget != NULL)
    {
        widget->pixel_foreground = pixel;        
    }
}

void YACSWL_widget_set_background_color(YACSWL_widget_t* widget, YACSGL_pixel_t pixel)
{
    if (widget != NULL)
    {
        widget->pixel_background = pixel;
    }
}

void YACSWL_widget_set_transparent_background(YACSWL_widget_t* widget, bool is_transparent_background)
{
    if (widget != NULL)
    {
        widget->is_transparent_background = is_transparent_background;
    }
}

/******************** LOCAL FUNCTIONS ****************************************/

static YACSWL_widget_update_sizes(YACSWL_widget_t* widget, bool is_resized)
{
    widget->x_bottom_width = widget->x_top_width + widget->width;
    widget->y_bottom_heigth = widget->y_top_heigth + widget->height;

    if (is_resized && (widget->resize_func != NULL))
    {
        widget->resize_func(widget);
    }
}

/**\} */
/**\} */

/* EOF */
