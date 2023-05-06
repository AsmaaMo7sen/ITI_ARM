/*
 * RCC_prog.c
 *
 *  Created on: May 4, 2023
 *      Author: 20115
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_inteface.h"
#include "RCC_private.h"
#include "RCC_cfg.h"

void RCC_voidSetSystemClock(void)
{
#if SYSYTEM_CLK_SRC == HSI  

SET_BIT(RCC_CR ,   0); // enable HSI clk(16MHZ)
CLR_BIT(RCC_CFGR , 0); // select HSI clk source 
CLR_BIT(RCC_CFGR , 1); 

#elif SYSYTEM_CLK_SRC == HSE_RC 


SET_BIT(RCC_CR ,  16); // enable HSE clk 
SET_BIT(RCC_CR ,  18); // choose RC ext (enable By pass mode)
SET_BIT(RCC_CFGR , 0); // select HSE RC clk source   
CLR_BIT(RCC_CFGR , 1); 

#elif SYSYTEM_CLK_SRC == HSE_CRYSTAL 

SET_BIT(RCC_CR ,  16); // enable HSE clk 
CLR_BIT(RCC_CR ,  18); // choose Crystal ext (disable By pass mode)
SET_BIT(RCC_CFGR , 0); // select HSE Crystal clk source   
CLR_BIT(RCC_CFGR , 1); 

#elif SYSYTEM_CLK_SRC == PLL

/**
 * TODO: "Complete PLL From DATASHEETS"
*/
#else 
    #error "Invalid Clock Configration"
#endif

}

void RCC_voidEnablePeripheralClock(u8 BusID, u8 PeripheralID)
{
            
}
void RCC_voidDisablePeripheralClock(u8 BusID, u8 PeripheralID);