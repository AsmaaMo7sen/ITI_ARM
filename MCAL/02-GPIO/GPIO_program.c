/*******************************************/
/* Author: Mena Ghobrial                   */
/* Date:   18 SEP 2022                     */
/* Version: V01                            */
/*******************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA_PORT:
			GPIOA->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOA->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		case GPIOB_PORT:
			GPIOB->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOB->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		case GPIOC_PORT:
			GPIOC->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOC->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		case GPIOD_PORT:
			GPIOD->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOD->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		case GPIOE_PORT:
			GPIOE->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOE->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		case GPIOH_PORT:
			GPIOH->MODER &=~(0b11 << (Copy_u8Pin*2));
			GPIOH->MODER |=(Copy_u8Mode << (Copy_u8Pin*2));
			break;
		default:
			break;
	}
}


void MGPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputType)
{
	switch(Copy_u8OutputType)
	{
		case GPIO_PUSH_PULL:
				switch(Copy_u8Port)
				{
					case GPIOA_PORT: CLR_BIT(GPIOA->OTYPER, Copy_u8Pin); break;
					case GPIOB_PORT: CLR_BIT(GPIOB->OTYPER, Copy_u8Pin); break;
					case GPIOC_PORT: CLR_BIT(GPIOC->OTYPER, Copy_u8Pin); break;
					case GPIOD_PORT: CLR_BIT(GPIOD->OTYPER, Copy_u8Pin); break;
					case GPIOE_PORT: CLR_BIT(GPIOE->OTYPER, Copy_u8Pin); break;
					case GPIOH_PORT: CLR_BIT(GPIOH->OTYPER, Copy_u8Pin); break;
					default:                                             break;
				}
				break;
		case GPIO_OPEN_DRAIN:
				switch(Copy_u8Port)
				{
					case GPIOA_PORT: SET_BIT(GPIOA->OTYPER, Copy_u8Pin); break;
					case GPIOB_PORT: SET_BIT(GPIOB->OTYPER, Copy_u8Pin); break;
					case GPIOC_PORT: SET_BIT(GPIOC->OTYPER, Copy_u8Pin); break;
					case GPIOD_PORT: SET_BIT(GPIOD->OTYPER, Copy_u8Pin); break;
					case GPIOE_PORT: SET_BIT(GPIOE->OTYPER, Copy_u8Pin); break;
					case GPIOH_PORT: SET_BIT(GPIOH->OTYPER, Copy_u8Pin); break;
					default:                                             break;
				}
				break;
		default:
				break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputSpeed)
{
	switch(Copy_u8Port)
	{
		case GPIOA_PORT:
			GPIOA->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOA->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		case GPIOB_PORT:
			GPIOB->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOB->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		case GPIOC_PORT:
			GPIOC->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOC->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		case GPIOD_PORT:
			GPIOD->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOD->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		case GPIOE_PORT:
			GPIOE->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOE->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		case GPIOH_PORT:
			GPIOH->OSPEEDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOH->OSPEEDR |=(Copy_u8OutputSpeed << (Copy_u8Pin*2));
			break;
		default:
			break;
	}
}

void MGPIO_voidSetPinPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType)
{
	switch(Copy_u8Port)
	{
		case GPIOA_PORT:
			GPIOA->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOA->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		case GPIOB_PORT:
			GPIOB->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOB->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		case GPIOC_PORT:
			GPIOC->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOC->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		case GPIOD_PORT:
			GPIOD->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOD->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		case GPIOE_PORT:
			GPIOE->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOE->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		case GPIOH_PORT:
			GPIOH->PUPDR &=~(0b11 << (Copy_u8Pin*2));
			GPIOH->PUPDR |=(Copy_u8PullType << (Copy_u8Pin*2));
			break;
		default:
			break;
	}
}


u8 MGPIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 u8_LocalPinValue = 0;
	switch(Copy_u8Port)
	{
		case GPIOA_PORT: u8_LocalPinValue = GET_BIT(GPIOA->IDR, Copy_u8Pin); break;
		case GPIOB_PORT: u8_LocalPinValue = GET_BIT(GPIOB->IDR, Copy_u8Pin); break;
		case GPIOC_PORT: u8_LocalPinValue = GET_BIT(GPIOC->IDR, Copy_u8Pin); break;
		case GPIOD_PORT: u8_LocalPinValue = GET_BIT(GPIOD->IDR, Copy_u8Pin); break;
		case GPIOE_PORT: u8_LocalPinValue = GET_BIT(GPIOE->IDR, Copy_u8Pin); break;
		case GPIOH_PORT: u8_LocalPinValue = GET_BIT(GPIOH->IDR, Copy_u8Pin); break;
		default:                                                             break;
	}
	return u8_LocalPinValue;
}

void MGPIO_voidWritePinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
	switch(Copy_u8PinValue)
	{
		case GPIO_LOW:
				switch(Copy_u8Port)
				{
					case GPIOA_PORT: CLR_BIT(GPIOA->ODR, Copy_u8Pin); break;
					case GPIOB_PORT: CLR_BIT(GPIOB->ODR, Copy_u8Pin); break;
					case GPIOC_PORT: CLR_BIT(GPIOC->ODR, Copy_u8Pin); break;
					case GPIOD_PORT: CLR_BIT(GPIOD->ODR, Copy_u8Pin); break;
					case GPIOE_PORT: CLR_BIT(GPIOE->ODR, Copy_u8Pin); break;
					case GPIOH_PORT: CLR_BIT(GPIOH->ODR, Copy_u8Pin); break;
					default:                                          break;
				}
				break;
		case GPIO_HIGH:
				switch(Copy_u8Port)
				{
					case GPIOA_PORT: SET_BIT(GPIOA->ODR, Copy_u8Pin); break;
					case GPIOB_PORT: SET_BIT(GPIOB->ODR, Copy_u8Pin); break;
					case GPIOC_PORT: SET_BIT(GPIOC->ODR, Copy_u8Pin); break;
					case GPIOD_PORT: SET_BIT(GPIOD->ODR, Copy_u8Pin); break;
					case GPIOE_PORT: SET_BIT(GPIOE->ODR, Copy_u8Pin); break;
					case GPIOH_PORT: SET_BIT(GPIOH->ODR, Copy_u8Pin); break;
					default:                                          break;
				}
				break;
		default:
				break;
	}
}

void MGPIO_voidSetPinAltFn(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ALF)
{
	if(Copy_u8Pin < 8)
	{
		switch(Copy_u8Port)
		{
			case GPIOA_PORT:
				GPIOA->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOA->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOB_PORT:
				GPIOB->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOB->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOC_PORT:
				GPIOC->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOC->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOD_PORT:
				GPIOD->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOD->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOE_PORT:
				GPIOE->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOE->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOH_PORT:
				GPIOH->AFRL &=~(0b1111 << (Copy_u8Pin*4));
				GPIOH->AFRL |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			default:
				break;
		}
	}
	else if(Copy_u8Pin < 16)
	{
		Copy_u8Pin -= 8;
		switch(Copy_u8Port)
		{
			case GPIOA_PORT:
				GPIOA->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOA->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOB_PORT:
				GPIOB->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOB->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOC_PORT:
				GPIOC->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOC->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOD_PORT:
				GPIOD->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOD->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOE_PORT:
				GPIOE->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOE->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			case GPIOH_PORT:
				GPIOH->AFRH &=~(0b1111 << (Copy_u8Pin*4));
				GPIOH->AFRH |=(Copy_u8ALF << (Copy_u8Pin*4));
				break;
			default:
				break;
		}
	}
	else
	{
		/* Return Error */
	}
}


void MGPIO_voidTogglePinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
	switch(copy_u8Port)
	{
		case GPIOA_PORT: TOG_BIT(GPIOA->ODR, copy_u8Pin); break;
		case GPIOB_PORT: TOG_BIT(GPIOB->ODR, copy_u8Pin); break;
		case GPIOC_PORT: TOG_BIT(GPIOC->ODR, copy_u8Pin); break;
		case GPIOD_PORT: TOG_BIT(GPIOD->ODR, copy_u8Pin); break;
		case GPIOE_PORT: TOG_BIT(GPIOE->ODR, copy_u8Pin); break;
		case GPIOH_PORT: TOG_BIT(GPIOH->ODR, copy_u8Pin); break;
		default:                                          break;
	}
}