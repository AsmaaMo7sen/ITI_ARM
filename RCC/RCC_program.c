/*
 * RCC_program.c
 *
 *  Created on: May 6, 2023
 *      Author: Mohamed
 */

#include "STD_LIB.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI

	SET_BIT(RCC_CR,0); //Enable RCC HSI clock (16MHz)
	CLR_BIT(RCC_CFGR,0);//Select HSI as a clock system
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLK_SRC == HSE_RC

	SET_BIT(RCC_CR,16); //Enable RCC HSE clock
	SET_BIT(RCC_CR,18); //Choose RC external (Enable by pass mode)
	SET_BIT(RCC_CFGR,0);//Select HSE as a clock system
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC == HSE_CRYSTAL

	SET_BIT(RCC_CR,16); //Enable RCC HSE clock
	CLR_BIT(RCC_CR,18); //Choose RC Crystal
	SET_BIT(RCC_CFGR,0);//Select HSE as a clock system
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC == PLL
/*
	SET_BIT(RCC_CR,24); //Enable RCC PLL clock
	CLR_BIT(RCC_CFGR,0);//Select PLL as a clock system
	SET_BIT(RCC_CFGR,1);
*/
#elif

	#error ("Wrong System Clock Configurations")

#endif


u8 RCC_u8EnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	switch(Copy_u8BusID)
	{
	case RCC_AHB1:
		SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_AHB2:
		SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB1:
		SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB2:
		SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);
		break;
	default: /*Return error state*/
		break;
	}
}
}
