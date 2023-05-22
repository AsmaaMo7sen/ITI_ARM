/*
 * NVIC_program.c
 *
 *  Created on: 15May,2023
 *      Author: osama
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"


/*to enable Interrupt for peripheral  */
void MNVIC_voidEnableInt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber<31)
	{
		ISR->ISR0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 63)
	{
		Copy_u8IntNumber -=32;
		ISR->ISR1 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 83)
	{
		Copy_u8IntNumber -=64;
		ISR->ISR2 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return Error state invalid Interrupt number  */
	}

	/*return error  */
}


/*this function is to disable interrupt  */
void MNVIC_voidDisableInt(u8 Copy_u8IntNumber)
{
	/*another way to put ID and register number
	 *
	 * NVIC->ISER[Copy_u8IntNumber/32] = 1 <<(Copy_u8IntNumber % 32) ;
	 * this is equal to all code down
	 *  */
	if(Copy_u8IntNumber<31)
	{
		ICER->ICER0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 63)
	{
		Copy_u8IntNumber -=32;
		ICER->ICER1 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 83)
	{
		Copy_u8IntNumber -=64;
		ICER->ICER2 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return Error state invalid Interrupt number  */
	}

	/*return error  */
}
/*this function is to disable interrupt  */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber){
	/*another way to put ID and register number
	 *
	 * NVIC->ISPR[Copy_u8IntNumber/32] = 1 <<(Copy_u8IntNumber % 32) ;
	 * this is equal to all code down
	 *  */
	if(Copy_u8IntNumber<31)
	{
		ISPR->ISPR0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 63)
	{
		Copy_u8IntNumber -=32;
		ISPR->ISPR1 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 83)
	{
		Copy_u8IntNumber -=64;
		ISPR->ISPR2 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return Error state invalid Interrupt number  */
	}

	/*return error  */
}

/*this function is to disable interrupt  */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	/*another way to put ID and register number
	 *
	 * NVIC->ICPR[Copy_u8IntNumber/32] = 1 <<(Copy_u8IntNumber % 32) ;
	 * this is equal to all code down
	 *  */
	if(Copy_u8IntNumber<31)
	{
		ICPR->ICPR0 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 63)
	{
		Copy_u8IntNumber -=32;
		ICPR->ICPR1 = (1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber < 83)
	{
		Copy_u8IntNumber -=64;
		ICPR->ICPR2 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*return Error state invalid Interrupt number  */
	}

	/*return error  */
}
u8 MVIC_u8ReadingPending(u8 Copy_u8IntNumber)
{
	/*another way to put ID and register number
	 *	GET_bit(NVIC->IABR[Copy_u8IntNumber/32] ,(Copy_u8IntNumber % 32))
	 * NVIC->IABR[Copy_u8IntNumber/32] = 1 <<(Copy_u8IntNumber % 32) ;
	 * this is equal to all code down
	 *  */
	u8 Local_reading =0;
	if(Copy_u8IntNumber<31)
	{
		Local_reading = GET_BIT( IABR-> IABR0 , Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber < 63)
	{
		Copy_u8IntNumber -=32;
		Local_reading = GET_BIT( IABR-> IABR1 , Copy_u8IntNumber) ;
	}
	else if (Copy_u8IntNumber < 83)
	{
		Copy_u8IntNumber -=64;
		Local_reading = GET_BIT( IABR-> IABR2 , Copy_u8IntNumber) ;
	}
	else
	{
		/*return Error state invalid Interrupt number  */
	}

	return Local_reading;
}
void MNVIC_voidSetPriorty(s8 Copy_s8priorty , u8 Copy_u8GropyPriorty,u8 Copy_u8SubGroup , u32 Copy_u8Grop)
{
	/* Localvariable = VECT_KEY |(periorty_config <<8)*/
	u8 Local_u8Reg = (Copy_u8SubGroup|(Copy_u8GropyPriorty<<((Copy_u8Grop- 0x05FA0300)/256)));
	/*check if i core peripheral or external peripheral  */
	if(Copy_s8priorty >= 0)
	{
		IPR[Copy_s8priorty] = (Local_u8Reg << 4 );
//		AIRCR = Copy_u8Grop  ;
	}
	else if(Copy_s8priorty <0 )
	{

	}
}
