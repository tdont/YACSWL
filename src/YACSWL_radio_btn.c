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
   * \file YACSWL_radio_btn.c
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

#include "YACSWL_radio_btn.h"

#include <YACSGL_font_8x16.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

static void YACSWL_radio_btn_draw(YACSWL_radio_btn_t* radio_btn, YACSGL_frame_t* frame);
static void YACSWL_radio_btn_resize(YACSWL_radio_btn_t* radio_btn);
static void YACSWL_radio_btn_compute_size(YACSWL_radio_btn_t* radio_btn);

/******************** API FUNCTIONS ******************************************/

void YACSWL_radio_btn_init(YACSWL_radio_btn_t* radio_btn)
{
    if (radio_btn != NULL)
    {
        // Generic init
        YACSWL_widget_init(&radio_btn->widget);
        radio_btn->widget.widget_type = YACSWL_WDGT_RADIO_BTN;
        radio_btn->widget.draw_func = (YACSWL_widget_draw_func_t)YACSWL_radio_btn_draw;
        radio_btn->widget.resize_func = (YACSWL_widget_resize_func_t)YACSWL_radio_btn_resize;

        // Specific init
        YACSWL_label_init(&radio_btn->label);
        YACSWL_widget_set_border_width(YACSWL_WDGT(radio_btn->label), 0);
        YACSWL_widget_set_transparent_background(YACSWL_WDGT(radio_btn->label), true);
        YACSWL_widget_add_child(&radio_btn->widget, YACSWL_WDGT(radio_btn->label));
        radio_btn->is_autosized = true;
        YACSWL_radio_btn_compute_size(radio_btn);
    }
}

void YACSWL_radio_btn_set_text(YACSWL_radio_btn_t* radio_btn, const char* text)
{
    if (radio_btn != NULL)
    {
        YACSWL_label_set_text(&radio_btn->label, text);

        if (radio_btn->is_autosized)
        {
            YACSWL_radio_btn_compute_size(radio_btn);
        }
    }
}

void YACSWL_radio_btn_set_autosized(YACSWL_radio_btn_t* radio_btn, bool is_autosized)
{
    if (radio_btn != NULL)
    {
        radio_btn->is_autosized = is_autosized;

        if (radio_btn->is_autosized)
        {
            YACSWL_radio_btn_compute_size(radio_btn);
        }
    }
}

void YACSWL_radio_btn_set_checked(YACSWL_radio_btn_t* radio_btn, bool is_checked)
{
    if (radio_btn != NULL)
    {
        radio_btn->is_checked = is_checked;
    }
}

/******************** LOCAL FUNCTIONS ****************************************/

static void YACSWL_radio_btn_draw(YACSWL_radio_btn_t* radio_btn, YACSGL_frame_t* frame)
{
    uint16_t center_x = radio_btn->widget.x_top_width + radio_btn->center_x;
    uint16_t center_y = radio_btn->widget.y_top_heigth + radio_btn->center_y;

    YACSGL_circle_line(frame, center_x, center_y, radio_btn->radius, radio_btn->widget.pixel_foreground);

    if (radio_btn->is_checked)
    {
        if (radio_btn->radius > 3u)
        {
            YACSGL_circle_fill(frame, center_x, center_y, radio_btn->radius - 3u, radio_btn->widget.pixel_foreground);
        }
        else
        {
            YACSGL_set_pixel(frame, center_x, center_y, radio_btn->widget.pixel_foreground);
        }
    }
}

static void YACSWL_radio_btn_resize(YACSWL_radio_btn_t* radio_btn)
{
    YACSWL_radio_btn_compute_size(radio_btn);
}

static void YACSWL_radio_btn_compute_size(YACSWL_radio_btn_t* radio_btn)
{
    radio_btn->radius = radio_btn->label.font->height / 2u;
    radio_btn->center_x = radio_btn->widget.border_width + radio_btn->widget.margin_left + radio_btn->radius;
    radio_btn->center_y = radio_btn->widget.border_width + radio_btn->widget.margin_top + radio_btn->radius;

    if (radio_btn->is_autosized)
    {
        uint16_t new_width = radio_btn->radius * 2u + radio_btn->label.widget.width + radio_btn->widget.margin_left * 2u + radio_btn->widget.margin_right + radio_btn->widget.border_width * 2u;
        uint16_t new_height = radio_btn->label.widget.height + radio_btn->widget.margin_top + radio_btn->widget.margin_bottom + radio_btn->widget.border_width * 2u;
        if ((new_height != radio_btn->widget.height) || (new_width != radio_btn->widget.width))
        {
            YACSWL_widget_set_size(&radio_btn->widget, new_width, new_height);
        }
    }

    YACSWL_widget_set_pos(YACSWL_WDGT(radio_btn->label), 
                          radio_btn->radius * 2u + radio_btn->widget.margin_left * 2u + radio_btn->widget.border_width,
                          radio_btn->widget.margin_top + radio_btn->widget.border_width);
}


/**\} */
/**\} */

/* EOF */
