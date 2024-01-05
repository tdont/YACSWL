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
   * \file YACSWL_label.c
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

#include "YACSWL_label.h"

#include <YACSGL_font_8x16.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

static void YACSWL_label_draw(YACSWL_label_t* label, YACSGL_frame_t* frame);
static void YACSWL_label_resize(YACSWL_label_t* label);
static void YACSWL_label_compute_size(YACSWL_label_t* label);

/******************** API FUNCTIONS ******************************************/

void YACSWL_label_init(YACSWL_label_t* label)
{
    if (label != NULL)
    {
        // Generic init
        YACSWL_widget_init(&label->widget);
        label->widget.widget_type = YACSWL_WDGT_LABEL;
        label->widget.draw_func = (YACSWL_widget_draw_func_t)YACSWL_label_draw;
        label->widget.resize_func = (YACSWL_widget_resize_func_t)YACSWL_label_resize;

        // Specific init
        label->font = &YACSGL_font_8x16;
        label->is_autosized = true;
        YACSWL_label_set_text(label, "");
        YACSWL_label_compute_size(label);
    }
}

void YACSWL_label_set_text(YACSWL_label_t* label, const char* text)
{
    if ((label != NULL) && (text != NULL))
    {
        label->text = text;
        label->text_size = (uint16_t)strlen(label->text);

        if (label->is_autosized)
        {
            YACSWL_label_compute_size(label);
        }
    }
}

void YACSWL_label_set_autosized(YACSWL_label_t* label, bool is_autosized)
{
    if (label != NULL)
    {
        label->is_autosized = is_autosized;

        if (label->is_autosized)
        {
            YACSWL_label_compute_size(label);
        }
    }
}

/******************** LOCAL FUNCTIONS ****************************************/

static void YACSWL_label_draw(YACSWL_label_t* label, YACSGL_frame_t* frame)
{
    YACSGL_font_txt_disp(frame, label->widget.x_top_width + label->widget.margin_left + label->widget.border_width, 
                            label->widget.y_top_heigth + label->widget.margin_top + label->widget.border_width,
                            label->widget.pixel_foreground,
                            label->font, label->text, YACSGL_NEWLINE_DISABLED);
}

static void YACSWL_label_resize(YACSWL_label_t* label)
{
    if (label->is_autosized)
    {
        YACSWL_label_compute_size(label);
    }
}

static void YACSWL_label_compute_size(YACSWL_label_t* label)
{
    uint16_t new_width = label->text_size * label->font->width + label->widget.margin_left + label->widget.margin_right + label->widget.border_width * 2u;
    uint16_t new_height = label->font->height + label->widget.margin_top + label->widget.margin_bottom + label->widget.border_width * 2u;
    if ((new_height != label->widget.height) || (new_width != label->widget.width))
    {
        YACSWL_widget_set_size(&label->widget, new_width, new_height);
    }
}


/**\} */
/**\} */

/* EOF */
