#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI
	SET_BIT(RCC_CR , 0);   //enable HSI clock(16MHz)
	CLR_BIT(RCC_CFGR,0);   //select HSI as system clock source
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC == HSE_RC
	SET_BIT(RCC_CR , 16);   //enable HSE clock
	SET_BIT(RCC_CR , 18);   //choose RC external(enable By Pass mode)
	SET_BIT(RCC_CFGR,0);   //select HSE RC as system clock source
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC == HSE_CRYSTAL
	SET_BIT(RCC_CR , 16);   //enable HSE clock
	CLR_BIT(RCC_CR , 18);   //choose Crystal external(disable By Pass mode)
	SET_BIT(RCC_CFGR,0);   //select HSE Crystal as system clock source
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC == PLL

#else
	#error ("Wrong system clock configuration")

#endif
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_PeripheralID)
{
	switch(Copy_u8BusID)
	{
		case RCC_AHB1 :
			SET_BIT(RCC_AHB1ENR , Copy_PeripheralID);
			break;

		case RCC_AHB2 :
			SET_BIT(RCC_AHB2ENR , Copy_PeripheralID);
				break;


		case RCC_APB1 :
			SET_BIT(RCC_APB1ENR , Copy_PeripheralID);
				break;

		case RCC_APB2 :
			SET_BIT(RCC_APB2ENR , Copy_PeripheralID);
				break;

		default : /*return error state*/	break ;
	}
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_PeripheralID)
{
	switch(Copy_u8BusID)
	{
		case RCC_AHB1 :
			CLR_BIT(RCC_AHB1ENR , Copy_PeripheralID);
			break;

		case RCC_AHB2 :
			CLR_BIT(RCC_AHB2ENR , Copy_PeripheralID);
				break;


		case RCC_APB1 :
			CLR_BIT(RCC_APB1ENR , Copy_PeripheralID);
				break;

		case RCC_APB2 :
			CLR_BIT(RCC_APB2ENR , Copy_PeripheralID);
				break;

		default : /*return error state*/	break ;
	}
}




