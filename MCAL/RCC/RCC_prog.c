#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STD_TYPES.h"
#include "RCC_Cfg.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

Error_t RCC_voidEnablePeripheralClock(u8 copy_u8BusID, s8 copy_u8PeripheralID)
{
	if((copy_u8PeripheralID>=0) && (copy_u8PeripheralID<=32))
	{
		switch(copy_u8BusID)
		{
		case RCC_AHB1:
			SET_BIT(RCC_AHB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_AHB2:
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
	return OK;
}

Error_t RCC_voidDisablePeripheralClock(u8 copy_u8BusID, s8 copy_u8PeripheralID)
{
	if((copy_u8PeripheralID>=0) && (copy_u8PeripheralID<=32))
	{
		switch(copy_u8BusID)
		{
		case RCC_AHB1:
			CLR_BIT(RCC_AHB1ENR, copy_u8PeripheralID);
			return OK;
			break;

		case RCC_AHB2:
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
	return OK;
}

void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC == HSI
	SET_BIT(RCC_CR, 0);    //Enable HSI Clock(16MHZ)
	CLR_BIT(RCC_CFGR, 0);  //select HSI as system clock
	CLR_BIT(RCC_CFGR, 1);

#elif SYSTEM_CLK_SRC == HSE_RC
	SET_BIT(RCC_CR, 16);   //enable HSE clock
	SET_BIT(RCC_CR, 18);   //Choose RC external (enable BY pass mode)
	SET_BIT(RCC_CFGR, 0);  //select HSE as system clock
	CLR_BIT(RCC_CFGR, 1);


#elif SYSTEM_CLK_SRC == HSE_CRYSTAL
	SET_BIT(RCC_CR, 16);   //enable HSE clock
	CLR_BIT(RCC_CR, 18);   //Choose crystal external (Disable BY pass mode)
	SET_BIT(RCC_CFGR, 0);  //select HSE as system clock
	CLR_BIT(RCC_CFGR, 1);

#elif SYSTEM_CLK_SRC == PLL
	/*configurable from RCC_PLLCFGR*/

#else
#error ("Wrong system clock configuration")


#endif

}
