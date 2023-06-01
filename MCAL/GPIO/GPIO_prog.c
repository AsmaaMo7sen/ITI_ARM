/*
 * GPIO_prog.c
 *
 *  Created on: May 11, 2023
 *      Author: 20115
 */

#include "GPIO_interface.h"
#include "..\..\LIB\BIT_MATH.h"

void GPIO_voidInitOutputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinType, u8 Copy_u8PinSpeed)
{
	switch (Copy_u8PortID)
	{
	case GPIO_PORTA:
		/*Set direction of the pin to be output*/
		/*bit masking*/
		GPIOA->MODER &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOA->MODER |= (0b01 << (Copy_u8PinID * 2));

		/*Set speed of the output pin*/
		/*bit masking*/
		GPIOA->OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOA->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

		/*Set type of output pin*/
		WRT_BIT(GPIOA->OTYPER, Copy_u8PinID, Copy_u8PinType);
		break;

	case GPIO_PORTB:
		/*Set direction o f the pin to be output*/
		/*bit masking*/
		GPIOB->MODER &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOB->MODER |=  (0b01 << (Copy_u8PinID * 2));

		/*Set speed of the output pin*/
		/*bit masking*/
		GPIOB->OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOB->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

		/*Set type of output pin*/
		WRT_BIT(GPIOB->OTYPER, Copy_u8PinID, Copy_u8PinType);

		break;

	case GPIO_PORTC:
		/*Set direction of the pin to be output*/
		/*bit masking*/
		GPIOC->MODER &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOC->MODER |= (0b01 << (Copy_u8PinID * 2));

		/*Set speed of the output pin*/
		/*bit masking*/
		GPIOC->OSPEEDR &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOC->OSPEEDR |= (Copy_u8PinSpeed << (Copy_u8PinID * 2));

		/*Set type of output pin*/
		WRT_BIT(GPIOC->OTYPER, Copy_u8PinID, Copy_u8PinType);

		break;
	}
}

void GPIO_voidInitInputPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PullMode)
{
	switch (Copy_u8PortID)
	{
	case GPIO_PORTA:
		/*configure the pin to be input*/
		/*mode register*/
		GPIOA->MODER &= ~(0b11 << (Copy_u8PinID * 2));

		/*configure pull type*/
		GPIOA->PUPDR &= ~(0b11 << (Copy_u8PinID * 2));
		GPIOA->PUPDR |= (Copy_u8PullMode << (Copy_u8PinID * 2));
		break;

	case GPIO_PORTB:
		break;

	case GPIO_PORTC:
		break;
	}
}
void GPIO_voidSetOutPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	switch (Copy_u8PortID)
	{
	case GPIO_PORTA:
		WRT_BIT(GPIOA->ODR, Copy_u8PinID, Copy_u8Value);
		break;

	case GPIO_PORTB:
		WRT_BIT(GPIOB->ODR, Copy_u8PinID, Copy_u8Value);
		break;

	case GPIO_PORTC:
		WRT_BIT(GPIOC->ODR, Copy_u8PinID, Copy_u8Value);
		break;
	}
}

u8 GPIO_u8GetInputPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	/*local variable to store the value of input pin*/
	u8 Local_u8InputPinValue=0;

	switch (Copy_u8PortID)
	{
	case GPIO_PORTA:
		Local_u8InputPinValue = GET_BIT(GPIOA->IDR, Copy_u8PinID);
		break;

	case GPIO_PORTB:
		break;

	case GPIO_PORTC:
		break;
	}

	return Local_u8InputPinValue;
}

void GPIO_voidSetOutPinValueFast(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
	u32 Local_u32RegisterValue=0;

	switch (Copy_u8PortID)
	{
	case GPIO_PORTA:
		switch (Copy_u8Value)
		{
		/*Set the pin value*/
		/*access bits from 0 to 15*/
		case GPIO_OUTPUT_HIGH:
			Local_u32RegisterValue = 1 << Copy_u8PinID;
			break;

		/*Reset the pin value*/
		/*access bits from 16 to 31*/
		case GPIO_OUTPUT_LOW:
			Local_u32RegisterValue = 1 << (Copy_u8PinID + 16);
			break;
		}

		GPIOA->BSRR = Local_u32RegisterValue;
		break;

	case GPIO_PORTB:
		break;

	case GPIO_PORTC:
		break;
	}
}


