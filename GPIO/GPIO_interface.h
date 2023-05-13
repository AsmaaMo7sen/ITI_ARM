/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
/*turn to enums*/
#define GPIO_PORTA	1
#define GPIO_PORTB	2
#define GPIO_PORTC	3
/*turn to enums*/
#define GPIO_PUSH_PULL	0
#define GPIO_OPEN_DRAIN	1
/*turn to enums*/
#define GPIO_SPEED_LOW			1
#define GPIO_SPEED_MED			2
#define GPIO_SPEED_HIGH			3
#define GPIO_SPEED_VERY_HIGH	4
/*turn to enums*/
#define GPIO_OUTPUT_HIGH	1
#define GPIO_OUTPUT_LOW		0
/*turn to enums*/
#define GPIO_INPUT_NONE		0
#define GPIO_INPUT_PULLUP	1
#define GPIO_INPUT_PULLDOWN	2
/*turn to enums*/
void GPIO_Init_Pin_Output(u8 port_id,u8 pin_id,u8 pin_type,u8 pin_speed);
void GPIO_Init_Pin_Input (u8 port_id,u8 pin_id,u8 pin_mode);
void GPIO_Set_Pin_Value	 (u8 port_id,u8 pin_id,u8 pin_value);
u8 GPIO_Get_Pin_Value 	 (u8 port_id,u8 pin_id);
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
