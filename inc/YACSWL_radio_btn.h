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
 * \file YACSWL_radiobtn.h
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
#ifndef INC_YACSWL_RADIOBTN_H_
#define INC_YACSWL_RADIOBTN_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include "YACSWL_label.h"
#include <YACSGL_font.h>

/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef struct
{
    YACSWL_widget_t widget;
    YACSWL_label_t label;
    uint16_t radius;
    uint16_t center_x;
    uint16_t center_y;
    bool is_autosized;
    bool is_checked;
}YACSWL_radio_btn_t;
/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/

void YACSWL_radio_btn_init(YACSWL_radio_btn_t* radio_btn);

void YACSWL_radio_btn_set_text(YACSWL_radio_btn_t* radio_btn, const char* text);

void YACSWL_radio_btn_set_autosized(YACSWL_radio_btn_t* radio_btn, bool is_autosized);

void YACSWL_radio_btn_set_checked(YACSWL_radio_btn_t* radio_btn, bool is_checked);

#ifdef __cplusplus
}
#endif

#endif /* INC_YACSWL_RADIOBTN_H_ */

/**\} */
/**\} */

/* EOF */