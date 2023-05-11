/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Zyad Ahmed	   		******************/
/******************			File Name: RCC_program.c        ******************/
/******************								     	    ******************/
/*****************************************************************************/
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidSetSysClock(void) {

	/*enable HSI clock(16MHz)*/
#if SYSTEM_CLK_SRC == HSI
	/*select HSI as system clock source*/
	SET_BIT(RCC_CR, HSION);
	CLEAR_BIT(RCC_CFGR, SW0);
	CLEAR_BIT(RCC_CFGR, SW1);

	/*enable HSE_RC clock(16MHz)*/
#elif SYSTEM_CLK_SRC == HSE_RC

	/*select HSE_RC as system clock source*/
	SET_BIT(RCC_CR, HSEON);
	SET_BIT(RCC_CR, HSEBYP);
	CLEAR_BIT(RCC_CFGR, SW0);
	SET_BIT(RCC_CFGR, SW1);

	/*enable HSE_CRYSTAL clock(16MHz)*/
#elif SYSTEM_CLK_SRC == HSE_CRYSTAL

	/*select HSE_CRYSTAL as system clock source*/
	SET_BIT(RCC_CR, HSEON);
	CLEAR_BIT(RCC_CR, HSEBYP);
	CLEAR_BIT(RCC_CFGR, SW0);
	SET_BIT(RCC_CFGR, SW1);
#elif SYSTEM_CLK_SRC == PLL

#else
#error ("wrong system clock configuration")

#endif
}

RCC_ErrorStatus RCC_voidEnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID)
{
	/*setting local variable for returning an error*/
	RCC_ErrorStatus Local_u8ErrorStatus = NoError;

	/*checking if the user entered number more than 31*/
	if (Copy_PeripheralID <= MAX_PERIPHIRAL)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB1 :
			/*Enable the peripheral on RCC_AHB1ENR*/
			SET_BIT(RCC_AHB1ENR, Copy_PeripheralID);
			break;

		case RCC_AHB2 :
			/*Enable the peripheral on RCC_AHB1ENR*/
			SET_BIT(RCC_AHB2ENR, Copy_PeripheralID);
			break;

		case RCC_APB1 :
			/*Enable the peripheral on RCC_AHB1ENR*/
			SET_BIT(RCC_APB1ENR, Copy_PeripheralID);
			break;

		case RCC_APB2 :
			/*Enable the peripheral on RCC_AHB1ENR*/
			SET_BIT(RCC_APB2ENR, Copy_PeripheralID);
			break;

		default :
			/*error for wrong bus*/
			Local_u8ErrorStatus = WrongBus;
			break;
		}
	}
	else
	{
		/*error for wrong peripheral*/
		Local_u8ErrorStatus = WrongPeripheral;
	}
	/*returning error status*/
	return Local_u8ErrorStatus;
}


RCC_ErrorStatus RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID)
{
	/*setting local variable for returning an error*/
	RCC_ErrorStatus Local_u8ErrorStatus = NoError;

	/*checking if the user entered number more than 31*/
	if (Copy_PeripheralID <= MAX_PERIPHIRAL)
	{
		switch(Copy_u8BusID)
		{
		case RCC_AHB1 :
			/*Disable the peripheral on RCC_AHB1ENR*/
			ClEAR_BIT(RCC_AHB1ENR, Copy_PeripheralID);
			break;

		case RCC_AHB2 :
			/*Disable the peripheral on RCC_AHB1ENR*/
			CLEAR_BIT(RCC_AHB2ENR, Copy_PeripheralID);
			break;

		case RCC_APB1 :
			/*Disable the peripheral on RCC_AHB1ENR*/
			CLEAR_BIT(RCC_APB1ENR, Copy_PeripheralID);
			break;

		case RCC_APB2 :
			/*Disable the peripheral on RCC_AHB1ENR*/
			CLEAR_BIT(RCC_APB2ENR, Copy_PeripheralID);
			break;

		default :
			/*Disable for wrong bus*/
			Local_u8ErrorStatus = WrongBus;
			break;
		}
	}
	else
	{
		/*error for wrong peripheral*/
		Local_u8ErrorStatus = WrongPeripheral;
	}
	/*returning error status*/
	return Local_u8ErrorStatus;
}

