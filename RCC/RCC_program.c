/***************************************************************************/
/*Author      : Mohamed Ashraf Abdelhamid							       */
/*File Name   : RCC_program.c                                              */
/*Bus 	      : AHB1									  		           */
/*Description : This file contains functions' implementation of RCC module */
/*Date        : 5 May 2023	                                               */
/***************************************************************************/

#include "STD_LIB.h"
#include "BIT_MATHS.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

RCC_ErrorState_t RCC_EnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	RCC_ErrorState_t Local_ErrorState = Ok;

	switch(Copy_u8BusID)
	{
		case RCC_AHB1 :
			SET_BIT(RCC_AHB1ENR , Copy_u8PeripheralID);
			break;

		case RCC_AHB2 :
			SET_BIT(RCC_AHB2ENR , Copy_u8PeripheralID);
			break;

		case RCC_APB1 :
			SET_BIT(RCC_APB1ENR , Copy_u8PeripheralID);
			break;

		case RCC_APB2 :
			SET_BIT(RCC_APB2ENR , Copy_u8PeripheralID);
			break;

		default :
			// Return Error State
			Local_ErrorState = InvalidBusID;
			break;
	}

	return Local_ErrorState;
}

RCC_ErrorState_t RCC_DisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	RCC_ErrorState_t Local_ErrorState = Ok;

	switch(Copy_u8BusID)
	{
		case RCC_AHB1 :
			CLR_BIT(RCC_AHB1ENR , Copy_u8PeripheralID);
			break;

		case RCC_AHB2 :
			CLR_BIT(RCC_AHB2ENR , Copy_u8PeripheralID);
			break;

		case RCC_APB1 :
			CLR_BIT(RCC_APB1ENR , Copy_u8PeripheralID);
			break;

		case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR , Copy_u8PeripheralID);
			break;

		default :
			// Return Error State
			Local_ErrorState = InvalidBusID;
			break;
	}

	return Local_ErrorState;
}

void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI
	SET_BIT(RCC_CR , 0);			//Enable HSI Clock (16MHz)
	CLR_BIT(RCC_CFGR , 0);			//Select HSI as System Clock Source
	CLR_BIT(RCC_CFGR , 1);

#elif SYSTEM_CLK_SRC == HSE_RC
	SET_BIT(RCC_CR , 16)			//Enable HSE Clock
	SET_BIT(RCC_CR , 18)			//Choose RC External (Enable Bypass Mode)
	SET_BIT(RCC_CFGR , 0);			//Select HSE RC as System Clock Source
	CLR_BIT(RCC_CFGR , 1);

#elif SYSTEM_CLK_SRC  == HSE_CRYSTAL
	SET_BIT(RCC_CR , 16)			//Enable HSE Clock
	CLR_BIT(RCC_CR , 18)			//Choose Crystal External (Disable Bypass Mode)
	SET_BIT(RCC_CFGR , 0);			//Select HSE Crystal as System Clock Source
	CLR_BIT(RCC_CFGR , 1);

#elif SYSTEM_CLK_SRC == PLL

#else
	#error ("Wrong System Clock Configuration")

#endif
}
