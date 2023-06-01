/****************************************************************************/
/*Author      : Saad Mohamed Saad									        */
/*File Name   : LEDMTRX_interface.h                                         */
/*Layer       : HAL									 	        	        */
/*Description : This file contains Interfacing parameters of LEDMTRX module */
/*Date        : 27 May 2023                                                 */
/****************************************************************************/


#ifndef HAL_LEDMTRX_LEDMTRX_INTERFACE_H_
#define HAL_LEDMTRX_LEDMTRX_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
/********************************Functions' Prototypes******************************/

/*This function shall initialize the Led Matrix*/
void LEDMTRX_voidInit(void);

/*This function is to display a specific pattern over Led Matrix*/
void LEDMTRX_voidDisplayPattern(u8 Copy_au8PaterrnArray[],u16 time);

/*This function is to deactivate all columns and set all leds to be OFF*/
void LEDMTRX_voidTurnOff(void);

#endif /* HAL_LEDMTRX_LEDMTRX_INTERFACE_H_ */
