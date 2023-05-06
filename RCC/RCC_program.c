/*
 * RCC_program.c
 *
 *  Created on: May 4, 2023
 *      Author: ziads
 */


#include "STD_LIB.h"
#include "BIT_MATHS.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_cfg.h"


void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	/* enum inistially ok */
	switch(Copy_u8BusID)
	{
	case RCC_AHB1 :
		SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_AHB2 :
		SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);
			break;
	case RCC_APB1 :
		SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);
			break;
	case RCC_APB2 :
		SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);
			break;

	//default : /*return error state */break;
	}



}


void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID)
{
	/* Invalid Peripheral id*/
	/* Wrong bus */

		switch(Copy_u8BusID)
		{
		case RCC_AHB1 :
			CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);
			break;
		case RCC_AHB2 :
			CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);
				break;
		case RCC_APB1 :
			CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);
				break;
		case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);
				break;

		//default : /*return error state */break;
		}



}


void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLOCK_SRC == HSI
	SET_BIT(RCC_CR,0);      /* Enable HSI Clock (16 MHZ)*/
	CLR_BIT(RCC_CFGR,0);    /* Select HSI as System Clock Source */
	CLR_BIT(RCC_CFGR,1);


#elif SYSTEM_CLOCK_SRC == HSE_RC
	SET_BIT(RCC_CR,16);   /* Enable HSE clock */
	SET_BIT(RCC_CR,18);    /* choose RC external (enable by pass mode)*/
	SET_BIT(RCC_CFGR,0);   /* select HSE RC as System clock source */
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLOCK_SRC == HSE_CRYSTAL
	SET_BIT(RCC_CR,16);   /* Enable HSE clock */
	CLR_BIT(RCC_CR,18);   /* choose crystal external (disable by pass mode)*/
	SET_BIT(RCC_CFGR,0);  /* select HSE crystal as System clock source */
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLOCK_SRC == PLL


#else
	#error ("Wrong System Clock Configuration ")
#endif

}
