#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Cfg.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"


/*this funcution enable peripheral based on bus and the name of peripheral */
ERROR_STAT_type RCC_voidEnablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID)
{
	ERROR_STAT_type error_state_local= OK;
    switch(copy_u8BusID)
    {
    case RCC_AHB1:
    	SET_BIT(RCC_AHB1ENR,copy_u8PeripheralID);
        return error_state_local;
    	break;
    case RCC_AHB2:
    	SET_BIT(RCC_AHB2ENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
    case RCC_APB1:
    	SET_BIT(RCC_APB1LPENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
    case RCC_APB2:
    	SET_BIT(RCC_APB2LPENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
	 default:
     error_state_local= WRONG_BusID;
	 return  error_state_local;	
    }

}
/*this funcution disable peripheral based on bus and the name of peripheral */
ERROR_STAT_type RCC_voidDisablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID)
{
   	ERROR_STAT_type error_state_local= OK;
    switch(copy_u8BusID)
    {
    case RCC_AHB1:
    	CLR_BIT(RCC_AHB1ENR,copy_u8PeripheralID);
        return error_state_local;
    	break;
    case RCC_AHB2:
    	CLR_BIT(RCC_AHB2ENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
    case RCC_APB1:
    	CLR_BIT(RCC_APB1LPENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
    case RCC_APB2:
    	CLR_BIT(RCC_APB2LPENR,copy_u8PeripheralID);
		return error_state_local;
    	break;
	 default:
     error_state_local= WRONG_BusID;
	 return  error_state_local;	
    }
}
/*this funcution determine system clock */
void RCC_voidSetSystemClock(void)
{
#if SYSTEM_CLK_SRC ==  HSI
	SET_BIT(RCC_CR,0);    //enable HSI clock (16MHz)

	CLR_BIT(RCC_CFGR,0);  //select HSI as system clock source
	CLR_BIT(RCC_CFGR,1);

#elif SYSTEM_CLK_SRC ==  HSE_RC
	SET_BIT(RCC_CR,16);    //enable HSE_RC clock
	SET_BIT(RCC_CR,18);    //choose Rc external (enable by pass mode)

	SET_BIT(RCC_CFGR,0);  //select HSE_RC as system clock source
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLK_SRC ==  HSE_CRYSTAL
	SET_BIT(RCC_CR,16);    //enable HSE_RC clock
	CLR_BIT(RCC_CR,18);    ////choose crystal external (disable by pass mode)

	SET_BIT(RCC_CFGR,0);  //select HSE_CRYSTAL as system clock source
	CLR_BIT(RCC_CFGR,1);
#elif SYSTEM_CLK_SRC ==  PLL

#else
#error ("wrong system clock configration")
#endif
}


