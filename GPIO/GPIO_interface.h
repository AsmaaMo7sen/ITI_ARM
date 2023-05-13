/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_


/*micro's ports*/
#define GPIO_PORTA             1
#define GPIO_PORTB             2
#define GPIO_PORTC             3

/*output pin modes*/
#define GPIO_PUSH_PULL         0
#define GPIO_OPEN_DRAIN        1

/*output pin speed*/
#define GPIO_LOW_SPEED         0
#define GPIO_MED_SPEED         1
#define GPIO_HIGH_SPEED        2
#define GPIO_VERY_HIGH_SPEED   3

/*output pin value*/
#define GPIO_OUTPUT_HIGH       1
#define GPIO_OUTPUT_LOW        0



/*initialize any pin to be output pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed);

void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode);

/*output pin(high or low)*/
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

/*get the value of any input pin*/
u8 GPIO_voidSetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

/*TO-DO*/
void GPIO_voidInitOutputPort(u8 Copy_u8PortID ,u8 Copy_u8PortType , u8 Copy_u8PortSpeed);

void GPIO_voidSetOutPortValue(u8 Copy_u8PortID , u16 Copy_u16PoetValue);

void GPIO_voidSetAlternativeFunction(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value , u8 Copy_u8AlternativeFunction);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
