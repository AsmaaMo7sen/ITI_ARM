/*****************************************/
/* Author:    Mena Ghobrial              */
/* Date:      23 SEP 2022                */
/* Version:   V01                        */
/*****************************************/

/* Include LIB */
#include "STD_TYPES.h"
#include "MATH.h"


/* Include MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit(void)
{
	#if EXTI_MODE == EXTI_RISING_EGDE
	SET_BIT(EXTI->RTSR, EXTI_LINE);
	#elif EXTI_MODE == EXTI_FALLING_EGDE
	SET_BIT(EXTI->FTSR, EXTI_LINE);
	#elif EXTI_MODE == EXTI_ON_CHANGE
	SET_BIT(EXTI->RTSR, EXTI_LINE);
	SET_BIT(EXTI->FTSR, EXTI_LINE);
	#else 
		#error "Wrong Mode choice"
	#endif
	CLR_BIT(EXTI->IMR, EXTI_LINE);
}

void MEXTI_voidEnableLine(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR, Copy_u8Line);
}

void MEXTI_voidDisableLine(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR, Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER, Copy_u8Line);
}
	
void MEXTI_voidEnableLine(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case EXTI_RISING_EGDE : SET_BIT(EXTI->RTSR, Copy_u8Line); break;
		case EXTI_FALLING_EGDE: SET_BIT(EXTI->FTSR, EXTI_LINE)  ; break;
		case EXTI_ON_CHANGE   : SET_BIT(EXTI->RTSR, EXTI_LINE)  ;
							    SET_BIT(EXTI->FTSR, EXTI_LINE)  ; break;
		default:                                                  break;
	}
}

void EXTI_voidSetInterruptPort(u8 Copy_u8Line, u8 Copy_u8PortSelect)
{
	if(Copy_u8Line <= 3)
	{
		SYSCFG_EXTI[0] &= ~(0b1111<<(4*Copy_u8Line));
		SYSCFG_EXTI[0] |= (Copy_u8PortSelect<<(4*Copy_u8Line));
	}
	else if(Copy_u8Line <= 7)
	{
		Copy_u8Line -= 4;
		SYSCFG_EXTI[1] &= ~(0b1111<<(4*Copy_u8Line));
		SYSCFG_EXTI[1] |= (Copy_u8PortSelect<<(4*Copy_u8Line));
	}
	else if(Copy_u8Line <= 11)
	{
		Copy_u8Line -= 8;
		SYSCFG_EXTI[2] &= ~(0b1111<<(4*Copy_u8Line));
		SYSCFG_EXTI[2] |= (Copy_u8PortSelect<<(4*Copy_u8Line));
	}
	else if(Copy_u8Line <= 15)
	{
		Copy_u8Line -= 12;
		SYSCFG_EXTI[3] &= ~(0b1111<<(4*Copy_u8Line));
		SYSCFG_EXTI[3] |= (Copy_u8PortSelect<<(4*Copy_u8Line));
	}
	else
	{
		/* Return Error */
	}
}