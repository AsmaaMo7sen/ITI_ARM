#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


/************************** Enum to Return Error_State *****************************/



/************************** Interfacing Macros ********************************************/

/*MC'S PORTS*/
#define GPIO_PORTA				1
#define GPIO_PORTB				2
#define GPIO_PORTC				3

/*output pin modes*/
#define GPIO_PUSH_PULL			0
#define GPIO_OPEN_DRAIN			1

/*out put pin speed*/
#define GPIO_LOW_SPEED			0
#define GPIO_MID_SPEED			1
#define GPIO_HIGH_SPEED			2
#define GPIO_VERY_HIGH_SPEED	3

/*output pin value*/
#define GPIO_OUTPUT_HIGH		1
#define GPIO_OUTPUT_LOW			0

/* Input Pin Pull Type */
#define GPIO_INPUT_PULLUP       1
#define GPIO_INPUT_PULLDOWN     2
/**************************** Function Prototypes ****************************************/
/* this function is to set initialize any pin to be an output pin */
void GPIO_voidInitOutputPin(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8PinType
		, u8 Copy_u8PinSpeed);

/* this function is to set initialize any pin to be an input pin */
void GPIO_voidInitInputPin(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8PullMode);

/* this function is to set the value of any output pin[high/low ] */
void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value);

/* this function is to get the value of any input pin   */
u8 GPIO_voidGetInputPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

/******************************************************************************************/


#endif
