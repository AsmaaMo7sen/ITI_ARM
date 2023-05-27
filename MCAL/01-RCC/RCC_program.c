/**********************************************/
/* Author:  Mena Ghobrial                     */
/* Date:    16 SEP 2022                       */
/* Version: V01                               */
/* Description: Cortex-M4                     */
/**********************************************/

/* LIB includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"


/* RCC Driver includes */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSystemClock(void)
{
	#if   CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC->CR   = 0x00010000; /* Enable HSE without HSE Bypass */
		RCC->CFGR = 0x00000001;
	#elif CLOCK_TYPE == RCC_HSE_RC
		RCC->CR = 0x00050000; /* Enable HSE + HSE Bypass */
		RCC->CFGR = 0x00000001;
	#elif CLOCK_TYPE == RCC_HSI 
		RCC->CR = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC->CFGR = 0x00000000;
	#elif CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_INPUT   == RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		
		#endif
	#else
		#error ("You chose Wrong Clock type")
	#endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1: SET_BIT(RCC->AHB1ENR, Copy_u8PerId); break;
			case RCC_AHB2: SET_BIT(RCC->AHB2ENR, Copy_u8PerId); break;
			case RCC_APB1: SET_BIT(RCC->APB1ENR, Copy_u8PerId); break;
			case RCC_APB2: SET_BIT(RCC->APB2ENR, Copy_u8PerId); break;
			default      :   /* Return Error */                 break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1: CLR_BIT(RCC->AHB1ENR, Copy_u8PerId); break;
			case RCC_AHB2: CLR_BIT(RCC->AHB2ENR, Copy_u8PerId); break;
			case RCC_APB1: CLR_BIT(RCC->APB1ENR, Copy_u8PerId); break;
			case RCC_APB2: CLR_BIT(RCC->APB2ENR, Copy_u8PerId); break;
			default      :   /* Return Error */                 break;
		}
	}
	else
	{
		/* Return Error */
	}
}