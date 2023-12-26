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
   * \file YACSWL_progress_bar.c
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

#include "YACSWL_progress_bar.h"

#include <YACSGL_font_5x7.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** LOCAL FUNCTION PROTOTYPE *******************************/

static void YACSWL_progress_bar_draw(YACSWL_progress_bar_t* progress_bar, YACSGL_frame_t* frame);

/******************** API FUNCTIONS ******************************************/

void YACSWL_progress_bar_init(YACSWL_progress_bar_t* progress_bar)
{
    if (progress_bar != NULL)
    {
        // Generic init
        YACSWL_widget_init(&progress_bar->widget);
        progress_bar->widget.widget_type = YACSWL_WDGT_PROGRESS_BAR;
        progress_bar->widget.draw_func = (YACSWL_widget_draw_func_t)YACSWL_progress_bar_draw;

        // Specific init
        progress_bar->progress = 0;
    }
}

void YACSWL_progress_bar_set_progress(YACSWL_progress_bar_t* progress_bar, uint8_t progress)
{
    if ((progress_bar != NULL) && (progress <= 100u))
    {
        progress_bar->progress = progress;
    }
}

/******************** LOCAL FUNCTIONS ****************************************/

static void YACSWL_progress_bar_draw(YACSWL_progress_bar_t* progress_bar, YACSGL_frame_t* frame)
{
    if (progress_bar->progress != 0)
    {
        uint16_t width = (progress_bar->widget.width * progress_bar->progress / 100u);
        YACSGL_rect_fill(frame, progress_bar->widget.x_top_width, progress_bar->widget.y_top_heigth, 
                     progress_bar->widget.x_top_width + width, progress_bar->widget.y_bottom_heigth, 
                     progress_bar->widget.pixel_foreground);
    }

}

/**\} */
/**\} */

/* EOF */
