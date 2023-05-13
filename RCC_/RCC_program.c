/**************************************************************************/
/*Author      : Nourhan Osama										      */
/*File Name   : RCC_program.c                                             */
/*Description : This file contains functions' implementation of RCC module*/
/*Date        : 7 May 2023                                                */
/**************************************************************************/
#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI

	SET_BIT(RCC_CR , RCC_CR_CSS_ON);    //Enable RCC HSI clock (16MHz)
	CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);   //Select HSI as a clock system
	CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);

#elif SYSTEM_CLK_SRC == HSE_RC

	SET_BIT(RCC_CR , RCC_CR_HSE_ON);    //enable HSE clock
	SET_BIT(RCC_CR , RCC_CR_HSE_BYP);   //choose RC external(enable By Pass mode)
	SET_BIT(RCC_CFGR , RCC_CFGR_SW0);   //select HSE RC as system clock source
	CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);

#elif SYSTEM_CLK_SRC == HSE_CRYSTAL

	SET_BIT(RCC_CR , RCC_CR_HSE_ON);    //Enable RCC HSE clock
	CLR_BIT(RCC_CR , RCC_CR_HSE_BYP);   //Choose RC Crystal
	SET_BIT(RCC_CFGR,RCC_CFGR_SW0);     //Select HSE as a clock system
	CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);

#elif SYSTEM_CLK_SRC == PLL

	SET_BIT(RCC_CR , RCC_CR_PLL_ON);    //Enable RCC PLL clock
	CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);   //Select PLL as a clock system
	SET_BIT(RCC_CFGR , RCC_CFGR_SW1);

#elif

	#error ("Wrong System Clock Configurations")

#endif
}



RCC_ErrorState_t RCC_u8EnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	RCC_ErrorState_t Local_RCCErrorState = RightData;

	if(Copy_u8PeripheralID>31)
	{
		Local_RCCErrorState=WrongPeripheralID ;
	}

	else
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB1:
			SET_BIT(RCC_AHB1ENR , Copy_u8PeripheralID); //Enable specific peripheral on AHB1 protocol
			break;

		case RCC_AHB2:
			SET_BIT(RCC_AHB2ENR , Copy_u8PeripheralID); //Enable specific peripheral on AHB2 protocol
			break;

		case RCC_APB1:
			SET_BIT(RCC_APB1ENR , Copy_u8PeripheralID); //Enable specific peripheral on APB1 protocol
			break;

		case RCC_APB2:
			SET_BIT(RCC_APB2ENR , Copy_u8PeripheralID); //Enable specific peripheral on APB2 protocol
			break;

		default: /*Return error state*/
			Local_RCCErrorState = WrongBusID ; //change error state to error bus id
			break;
		}
	}
	return Local_RCCErrorState;
}



RCC_ErrorState_t RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	RCC_ErrorState_t Local_RCCErrorState = RightData;

	if(Copy_u8PeripheralID>31)
	{
		Local_RCCErrorState=WrongPeripheralID;
	}

	else
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB1:
			CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID); //Disable specific peripheral on AHB1 protocol
			break;

		case RCC_AHB2:
			CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID); //Disable specific peripheral on AHB2 protocol
			break;

		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID); //Disable specific peripheral on APB1 protocol
			break;

		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID); //Disable specific peripheral on APB2 protocol
			break;

		default: /*Return error state*/
			Local_RCCErrorState = WrongBusID; //change error state to error bus id
			break;
		}
	}
	return Local_RCCErrorState;
}

