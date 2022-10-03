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
 * \file YACSWL.h
 *
 * File description
 * \author Thibaut DONTAIL
 * \date 21 Sep. 2022
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
#ifndef INC_YACSWL_H_
#define INC_YACSWL_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdint.h>

#include <YACSGL_pixel.h>

#include "YACSWL_label.h"
#include "YACSWL_radio_btn.h"
#include "YACSWL_checkable.h"

/******************** CONSTANTS OF MODULE ************************************/
#define YACSWL_WIDGET_ACTIVE    (1)
#define YACSWL_WIDGET_INACTIVE  (0)

#define YACSWL_WIDGET_SELECTED  (1)
#define YACSWL_WIDGET_NOT_SLCTD (0)

#define YACSWL_WIDGET_DISPLAYED (1)
#define YACSWL_WIDGET_NOT_DSPLD (0)

/******************** MACROS DEFINITION **************************************/

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
}YACSWL_Type_t;

typedef union 
{
    char raw_ptr[1];
    YACSWL_wdgt_checkable_t checkable;
    YACSWL_wdgt_spcfc_radiobtn_t radiobtn;
    YACSWL_wdgt_spcfc_label_t   label;
}YACSWL_wdgt_spcfc_t;

typedef struct _YACSWL_widget
{
    uint16_t x_top_width;  
    uint16_t y_top_heigth;
    uint16_t width;
    uint16_t height;
    YACSGL_pixel_t pixel_background;
    YACSGL_pixel_t pixel_forground;
    YACSWL_Type_t widget_type;
    //struct _YACSWL_widget* subwidget;
    //uint8_t subwidget_count;
    uint8_t is_selected;
    uint8_t is_active;
    uint8_t is_displayed;
    YACSWL_wdgt_spcfc_t specific_member;    
}YACSWL_widget_t;

/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE ********************************/

void YACSWL_set_display(YACSWL_widget_t* widget, uint8_t display);

void YACSWL_set_activate(YACSWL_widget_t* widget, uint8_t state);

void YACSWL_set_selected(YACSWL_widget_t* widget, uint8_t selected)

#ifdef __cplusplus
}
#endif


#endif /* INC_YACSWL_H_ */

/**\} */
/**\} */

/* EOF */