/*
 * SSD_interface.h
 *
 *  Created on: May 13, 2023
 *      Author: mohnd
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#define SSD_PORT GPIO_PORTA
#define SSD_PINS_START    0
#define SSD_PINS_END      7
#define SSD_COM_CATHOD    1
#define SSD_COM_ANODE     2
void SSD_voidInit(u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins);
void SSD_voidDisplay(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDStartPins,u8 Copy_u8SSDEndPins,u8 Copy_u8Value);
void SSD_voidOF(u8 Copy_COM,u8 Copy_SSDPort,u8 Copy_u8SSDEndPins);
#endif /* HAL_SSD_SSD_INTERFACE_H_ */
