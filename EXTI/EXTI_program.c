#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_LIB.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/*****************************Global variables****************************/

/* Array of global pointers to functions to set call back of EXTI sources*/
void (*Global_PtrToFunc_EXTI[16])(void) = NULL ;

/*************************Functions' implementation***********************/

void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void))
{
	/*Set call back function*/
	if(Copy_ptrToFunc != NULL)
	{
		Global_PtrToFunc_EXTI[Copy_u8IntId] = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}
	/*Enable interrupt*/
	SET_BIT(EXTI->IMR , Copy_u8IntId);

}

void EXTI_voidDisableInt(u8 Copy_u8IntId)
{
	CLR_BIT(EXTI->IMR , Copy_u8IntId);
}

void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8IntId)
{
	switch(Copy_u8SenseSignal)
	{
	case RISING_EDGE :
		CLR_BIT(EXTI->FTSR , Copy_u8IntId);
		SET_BIT(EXTI->RTSR , Copy_u8IntId);
		break ;

	case FALLING_EDGE :
		CLR_BIT(EXTI->RTSR , Copy_u8IntId);
		SET_BIT(EXTI->FTSR , Copy_u8IntId);
		break ;

	case ON_CHANGE :
		SET_BIT(EXTI->RTSR , Copy_u8IntId);
		SET_BIT(EXTI->FTSR , Copy_u8IntId);
		break ;

	}
}

void EXTI_voidSetLinePort(u8 Copy_u8IntId , u8 Copy_u8PortId)
{
	/*system configuration peripheral*/

	/*1)Clear target bits to set the new configurations (bit masking)*/
	SYSCFG->EXTICR[Copy_u8IntId/4] &= ~(0b1111 << ((Copy_u8IntId%4)*4)) ;

	/*2)Set the new configurations*/
	SYSCFG->EXTICR[Copy_u8IntId/4] |= Copy_u8PortId <<((Copy_u8IntId%4)*4) ;
}

static void EXTI_voidClearPendingFlag(u8 Copy_u8IntId)
{
	/*clear the interrupt flag after executing the interrupt ISR*/
	SET_BIT(EXTI->PR , Copy_u8IntId);
}



/***********************************ISRs implementation********************************/

/*ISR for external interrupt 0*/
void EXTI0_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[0]();
	EXTI_voidClearPendingFlag(EXTI_LINE0);
}

/*ISR for external interrupt 1*/
void EXTI1_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[1]();
	EXTI_voidClearPendingFlag(EXTI_LINE1);
}






