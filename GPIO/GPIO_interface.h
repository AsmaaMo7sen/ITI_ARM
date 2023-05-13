/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: mohnd
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_
/*Microcontroller's Port*/
#define GPIO_PORTA       1
#define GPIO_PORTB       2
#define GPIO_PORTC       3



/*output PIN Modes*/
#define GPIO_PUSH_PULL   0
#define GPIO_OPEN_DRAIN  1
/*input Pin Modes */
#define GPIO_float      0
#define GPIO_PULL_UP    1
#define GPIO_PULL_DOWN  2


/*Output pin speed Mode*/
#define GPIO_LOW_SPEED          0
#define GPIO_MED_SPEED          1
#define GPIO_HIGH_SPEED         2
#define GPIO_VERY_HIGH_SPEED    3
/**output pin value**/
#define GPIO_OUTPUT_HIGH      1
#define GPIO_OUTPUT_LOW       0


/******************************************Function Prototype**************************************/
/*this fin is to initialize any pin to be an Out pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinTYPES,u8 Copy_u8PinSpeed);

/*ths fun is to initialize and pin to be in pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copt_u8PinID,u8 Copy_u8PinMode);
/*this fun is to set the value of any output pin[high/low]*/
void GPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8value);
/*this function set 8 bit value*/
void GPIO_void_8_PinValue(u8 Copy_u8PortID,u8 Copy_u8PinsEnd,u8 Copy_u8value);
/*this fun is to read the value of any input pin[high/low]*/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
/* this fun to tgl GPIO out PIN*/
void GPIO_voidTGLPin(u8 Copy_u8PortID,u8 Copy_u8PinID);
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
