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
 * \file YACSWL_label.h
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
#ifndef INC_YACSWL_LABEL_H_
#define INC_YACSWL_LABEL_H_

#ifdef __cplusplus
extern "C" {
#endif


/******************** INCLUDES ***********************************************/
#include <stdint.h>
#include <YACSGL_font.h>
/******************** CONSTANTS OF MODULE ************************************/

/******************** MACROS DEFINITION **************************************/

/******************** TYPE DEFINITION ****************************************/
typedef struct
{
    char* text;
    const YACSGL_font_t* font;
    uint16_t x;
    uint16_t y;
    uint8_t nb_char_line_max;    
}YACSWL_wdgt_spcfc_label_t;


/******************** GLOBAL VARIABLES OF MODULE *****************************/

/******************** API FUNCTION PROTOTYPE *********************************/
void draw_label(const YACSWL_wdgt_spcfc_label_t* const label);
#ifdef __cplusplus
}
#endif

#endif /* INC_YACSWL_LABEL_H_ */

/**\} */
/**\} */

/* EOF */