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
 * \file YACSWL_widget.h
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 03 oct. 2022
 */

/**
 * \cond EXTERNAL_DOC
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

/* Prevent multiple inclusions */
#ifndef INC_YACSWL_CHECKABLE_H_
#define INC_YACSWL_CHECKABLE_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdint.h>
#include <stdbool.h>

#include <YACSGL.h>


/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

#define YACSWL_WDGT(w) (&(w.widget))

/******************** TYPE DEFINITION ****************************************/
    
typedef enum
{
    YACSWL_WDGT_NONE = 0,
    YACSWL_WDGT_LABEL,
    YACSWL_WDGT_RADIO_BTN
    //YACSWL_WDGT_CHECKBOX,
    //YACSWL_WDGT_TOGGLE_BTN,
    //YACSWL_WDGT_TXT_INPUT,
    //YACSWL_WDGT_BUTTON,
    //YACSWL_WDGT_DROP_DOWN_LIST
} YACSWL_Type_t;

typedef struct _YACSWL_widget YACSWL_widget_t;

typedef void (*YACSWL_widget_resize_func_t)(YACSWL_widget_t*);
typedef void (*YACSWL_widget_draw_func_t)(YACSWL_widget_t*, YACSGL_frame_t*);

typedef struct _YACSWL_widget
{
    uint16_t x_top_width;
    uint16_t y_top_heigth;
    uint16_t x_bottom_width;
    uint16_t y_bottom_heigth;
    uint16_t width;
    uint16_t height;
    uint16_t margin_left;
    uint16_t margin_top;
    uint16_t margin_right;
    uint16_t margin_bottom;
    uint8_t border_width;
    uint8_t z_order;
    YACSGL_pixel_t pixel_background;
    YACSGL_pixel_t pixel_foreground;
    YACSWL_Type_t widget_type;
    bool is_displayed;
    bool is_transparent_background;
    bool skip_generic_draw_func;
    YACSWL_widget_draw_func_t draw_func;
    YACSWL_widget_resize_func_t resize_func;
    YACSWL_widget_t* parent;
    YACSWL_widget_t* childrens;
    YACSWL_widget_t* next;
}YACSWL_widget_t;


/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/

void YACSWL_widget_init(YACSWL_widget_t* widget);

void YACSWL_widget_draw(YACSWL_widget_t* widget, YACSGL_frame_t* frame);

void YACSWL_widget_add_child(YACSWL_widget_t* widget, YACSWL_widget_t* child);

void YACSWL_widget_remove_child(YACSWL_widget_t* widget, YACSWL_widget_t* child);

void YACSWL_widget_set_pos(YACSWL_widget_t* widget, uint16_t x, uint16_t y);

uint16_t YACSWL_widget_get_pos_x(YACSWL_widget_t* widget);

uint16_t YACSWL_widget_get_pos_y(YACSWL_widget_t* widget);

void YACSWL_widget_set_size(YACSWL_widget_t* widget, uint16_t width, uint16_t height);

void YACSWL_widget_set_margins(YACSWL_widget_t* widget, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom);

void YACSWL_widget_set_z_order(YACSWL_widget_t* widget, uint8_t z_order);

void YACSWL_widget_set_border_width(YACSWL_widget_t* widget, uint8_t width);

void YACSWL_widget_set_displayed(YACSWL_widget_t* widget, bool is_displayed);

void YACSWL_widget_set_foreground_color(YACSWL_widget_t* widget, YACSGL_pixel_t pixel);

void YACSWL_widget_set_background_color(YACSWL_widget_t* widget, YACSGL_pixel_t pixel);

void YACSWL_widget_set_transparent_background(YACSWL_widget_t* widget, bool is_transparent_background);


#ifdef __cplusplus
}
#endif

#endif /* INC_YACSWL_CHECKABLE_H_ */

/**\} */
/**\} */

/* EOF */