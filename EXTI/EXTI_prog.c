/*
 * EXTI_prog.c
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_Cfg.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void))
{
    SET_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidDisableInt(u8 Copy_u8IntId)
{
    CLR_BIT(EXTI->IMR , Copy_u8IntId);

}

void EXTI_voidSetSenceSignal(u8 Copy_u8SenceSignal,u8 Copy_u8IntId)
{
    switch(Copy_u8SenceSignal)
	{
	case RISING_EDGE:
		CLR_BIT(EXTI->FTSR, Copy_u8IntId);
		SET_BIT(EXTI->RTSR, Copy_u8IntId);
		break;
	case FALLING_EDGE:
		CLR_BIT(EXTI->RTSR, Copy_u8IntId);
		SET_BIT(EXTI->FTSR, Copy_u8IntId);
		break;
	case ON_CHANGE:
		SET_BIT(EXTI->RTSR, Copy_u8IntId);
		SET_BIT(EXTI->FTSR, Copy_u8IntId);
		break;
	}

}


