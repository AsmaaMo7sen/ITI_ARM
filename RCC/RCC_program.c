/*************************************************************/
/*************************************************************/
/************     Author    : Mostafa Mahmoud     ************/
/************     file name : RCC_program.c       ************/
/************     Date      : 5/5/2023            ************/
/*************************************************************/
/*************************************************************/

#include "STD_LIB.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

Error_t RCC_voidEnablePeripheralClock(u8 copy_u8BusID, u8 copy_u8PeripheralID)
{
	if((copy_u8PeripheralID>=0) && (copy_u8PeripheralID<=32))
	{
		switch(copy_u8BusID)
		{
		case RCC_ABH1:
			SET_BIT(RCC_AHB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_ABH2:
			SET_BIT(RCC_AHB2ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, copy_u8PeripheralID);
			return OK;
			break;

		default:
			return InvalidBusID;
			break;
		}
	}
}

Error_t RCC_voidDisablePeripheralClock(u8 copy_u8BusID, u8 copy_u8PeripheralID)
{
	if((copy_u8PeripheralID>=0) && (copy_u8PeripheralID<=32))
	{
		switch(copy_u8BusID)
		{
		case RCC_ABH1:
			CLR_BIT(RCC_AHB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_ABH2:
			CLR_BIT(RCC_AHB2ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, copy_u8PeripheralID);
			return OK;
			break;

		default:
			return InvalidBusID;
			break;
		}
	}
}

void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SOURCE == HSI
	SET_BIT(RCC_CR, 0);    //Enable HSI Clock(16MHZ)
	CLR_BIT(RCC_CFGR, 0);  //select HSI as system clock
	CLR_BIT(RCC_CFGR, 1);

#elif SYSTEM_CLK_SOURCE == HSE_RC
	SET_BIT(RCC_CR, 16);   //enable HSE clock
	SET_BIT(RCC_CR, 18);   //Choose RC external (enable BY pass mode)
	SET_BIT(RCC_CFGR, 0);  //select HSE as system clock
	CLR_BIT(RCC_CFGR, 1);


#elif SYSTEM_CLK_SOURCE == HSE_CRYSTAL
	SET_BIT(RCC_CR, 16);   //enable HSE clock
	CLR_BIT(RCC_CR, 18);   //Choose crystal external (Disable BY pass mode)
	SET_BIT(RCC_CFGR, 0);  //select HSE as system clock
	CLR_BIT(RCC_CFGR, 1);

#elif SYSTEM_CLK_SOURCE == PLL
	/*configurable from RCC_PLLCFGR*/

#else
#error ("Wrong system clock configuration")

#endif

}
