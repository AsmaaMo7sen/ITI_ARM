/***************************************/
/* Author: Mena Ghobrial               */
/* Date: 26 SEP 2022                   */
/* Version: V01                        */
/***************************************/

/* Include LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include MCAL */
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (*STK_Callback) (void);
static u8 MSTK_u8ModeOfInterval;


void MSTK_voidInit(void)
{
	#if STK_CLK_SRC     ==     STK_SRC_AHB_8
	STK->CTRL = 0;
	#elif STK_CLK_SRC   ==     STK_SRC_AHB
	STK->CTRL = 0x00000004;
	#else 
		#error "Wrong Choice"
	#endif
}




void MSTK_voidSetBusyWait(u32 Copy_u8Ticks)
{
	STK->LOAD = Copy_u8Ticks*2;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Wait for the flag */
	while(GET_BIT(STK->CTRL, 16) == 0);
	
	/* Stop timer */
	CLR_BIT(STK->CTRL, 0);
	STK->LOAD = 0;
	STK->VAL = 0;
}


void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	STK->LOAD = Copy_u32Ticks*2;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Set Callback */
	STK_Callback = Copy_ptr;
	
	/* Set Interval type */
	MSTK_u8ModeOfInterval = SINGLE_INTERVAL;
	
	/* Enable Interrupt */
	SET_BIT(STK->CTRL, 1);
}


void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	STK->LOAD = Copy_u32Ticks*2;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Set Callback */
	STK_Callback = Copy_ptr;
	
	/* Set Interval type */
	MSTK_u8ModeOfInterval = PERIODIC_INTERVAL;
	
	/* Enable Interrupt */
	SET_BIT(STK->CTRL, 1);
}



void MSTK_voidStopInterval(void)
{
	/* Disable Interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Stop timer */
	CLR_BIT(STK->CTRL, 0);
	
	STK->LOAD = 0;
	STK->VAL = 0;
}



u32 MSTK_u32GetElapsedTime(void)
{
	u8 Local_u8ElapsedTime = 0;
	Local_u8ElapsedTime = (STK->LOAD)-(STK->VAL);
	return Local_u8ElapsedTime;
}


u32 MSTK_u32GetRemainingTime(void)
{
	u8 Local_u8RemainingTime = 0;
	Local_u8RemainingTime = STK->VAL;
	return Local_u8RemainingTime;
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0;
	if(MSTK_u8ModeOfInterval = SINGLE_INTERVAL)
	{
		/* Disable Interrupt */
		CLR_BIT(STK->CTRL, 1);
		
		/* Stop Timer */
		CLR_BIT(STK->CTRL, 0);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	
	STK_Callback();
	
	/* Clear Interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL, 16);
}