#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Cfg.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"


/*this funcution enable peripheral based on bus and the name of peripheral */
void RCC_voidEnablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID)
{

}
/*this funcution disable peripheral based on bus and the name of peripheral */
void RCC_voidDisablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID)
{

}
/*this funcution determine system clock */
void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_CRC ==  HSI
	SET_BIT(RCC_CR,0);    //enable HSI clock (16MHz)

	CLR_BIT(RCC_CFGR,0);  //select HSI as system clock source
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_CRC ==  HSE_RC
	SET_BIT(RCC_CR,16);    //enable HSE_RC clock
	SET_BIT(RCC_CR,18);    //choose Rc external (enable by pass mode)

	SET_BIT(RCC_CFGR,0);  //select HSE_RC as system clock source
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLK_CRC ==  HSE_CRYSTAL
	SET_BIT(RCC_CR,16);    //enable HSE_RC clock
	CLR_BIT(RCC_CR,18);    ////choose crystal external (disable by pass mode)

	SET_BIT(RCC_CFGR,0);  //select HSE_CRYSTAL as system clock source
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLK_CRC ==  PLL

#else
#error ("wrong system clock configration")
#endif
}


