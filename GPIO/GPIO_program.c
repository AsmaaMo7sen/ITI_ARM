#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidInitOutputPin(u8 Copy_u8PortID ,u8 Copy_u8PinID,u8 Copy_u8PinType , u8 Copy_u8PinSpeed)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :
			/*Set direction of the pin to be output*/
			/*bit masking*/
			GPIOA->MODER &= ~(0b11<<(Copy_u8PinID*2));
			GPIOA->MODER |= (0b01<<(Copy_u8PinID*2));

			/*Set speed of the output pin*/
			/*bit masking*/
			GPIOA->OSPEEDR &= ~(0b11<<(Copy_u8PinID*2));
			GPIOA->OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2));

			/*Set type of output pin*/
			WRT_BIT(GPIOA->OTYPER , Copy_u8PinID ,Copy_u8PinType);
			break ;

		case GPIO_PORTB :

			break ;

		case GPIO_PORTC :

			break ;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID,u8 Copy_u8PullMode )
{

}
void GPIO_voidSetOutPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID,u8 Copy_u8Value)
{
	switch(Copy_u8PortID)
	{
		case GPIO_PORTA :
			WRT_BIT(GPIOA->ODR , Copy_u8PinID , Copy_u8Value);
			break ;

		case GPIO_PORTB :
			WRT_BIT(GPIOB->ODR , Copy_u8PinID , Copy_u8Value);
			break ;

		case GPIO_PORTC :
			WRT_BIT(GPIOC->ODR , Copy_u8PinID , Copy_u8Value);
			break ;
	}
}

u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{

}


