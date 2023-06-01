#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "GPIO_private.h"

/*microcontroller's ports*/
#define GPIO_PORTA            1
#define GPIO_PORTB            2
#define GPIO_PORTC            3

/*Output pin types*/
#define GPIO_PUSH_PULL         0
#define GPIO_OPEN_DRAIN        1

/*Output pin speed*/
#define GPIO_LOW_SPEED               0
#define GPIO_MED_SPEED               1
#define GPIO_HIGH_SPEED              2
#define GPIO_VERY_HIGH_SPEED         3

/*Output pin value*/
#define GPIO_OUTPUT_HIGH             1
#define GPIO_OUTPUT_LOW              0

/*PINS*/
#define GPIO_PIN_0          0			
#define GPIO_PIN_1          1
#define GPIO_PIN_2          2
#define GPIO_PIN_3          3
#define GPIO_PIN_4          4
#define GPIO_PIN_5          5
#define GPIO_PIN_6          6
#define GPIO_PIN_7          7
#define GPIO_PIN_8          8
#define GPIO_PIN_9          9
#define GPIO_PIN_10          10
#define GPIO_PIN_11          11
#define GPIO_PIN_12          12
#define GPIO_PIN_13          13
#define GPIO_PIN_14          14
#define GPIO_PIN_15          15

/*This function is to initialize any pin to be an output pin*/
void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID
							,u8 Copy_u8PinType , u8 Copy_u8PinSpeed );

/*This function is to initialize any pin to be an input pin*/
void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID
							,u8 Copy_u8PullMode );

/*This function is to set the value of any output pin[high-low]*/
void GPIO_voidSetOutPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID
							, u8 Copy_u8Value);

/*This function is to get the value of ant input pin*/
u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

void GPIO_voidSetOutPinValueFast(u8 Copy_u8PortID , u8 Copy_u8PinID
								, u8 Copy_u8Value);


/*TODO*/
void GPIO_voidInitOutputPort(u8 Copy_u8PortID,u8 Copy_u8PortType , u8 Copy_u8PortSpeed);
void GPIO_voidSetOutPortValue(u8 Copy_u8PortID  , u16 Copy_u16PortValue);

/*TODO*/
void GPIO_voidSetAlterativeFunction(u8 Copy_u8PortID , u8 Copy_u8PinID
									, u8 Copy_u8AlternativeFunction);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */