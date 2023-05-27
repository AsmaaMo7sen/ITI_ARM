/*****************************************/
/* Author:    Mena Ghobrial              */
/* Date:      22 SEP 2022                */
/* Version:   V01                        */
/*****************************************/

/* Include LIB */
#include "STD_TYPES.h"
#include "MATH.h"


/* Include MCAL */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC->ISER[0] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC->ISER[1] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC->ISER[2] = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC->ICER[0] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC->ICER[1] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC->ICER[2] = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC->ISPR[0] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC->ISPR[1] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC->ISPR[2] = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC->ICPR[0] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		NVIC->ICPR[1] = (1 << Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		NVIC->ICPR[2] = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ActiveFlag;
	if(Copy_u8IntNumber <= 31)
	{
		Local_u8Flag = GET_BIT(NVIC->IABR[0], Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 63)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Flag = GET_BIT(NVIC->IABR[1], Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 84)
	{
		Copy_u8IntNumber -= 64;
		Local_u8Flag = GET_BIT(NVIC->IABR[2], Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
	return Local_u8ActiveFlag;
}


void MNVIC_voidSetPriorityGrouping(u8 Copy_u8GroupSub)
{
	SCB_AICR =  VECTKEY;       //Reset the register first
	SCB_AICR |= VECTKEY (Copy_u8GroupSub << 8);
}

void MNVIC_voidSetInterruptPriority(u8 Copy_u8IntId, u8 Copy_u8Group, u8 Copy_u8Sub, u8 Copy_u8GroupSub)
{
	switch(Copy_u8GroupSub)
	{
		case NVIC_G16_S0 : NVIC->IP[Copy_u8IntId] = Copy_u8Group<<4                  ; break;
		case NVIC_G8_S2  : NVIC->IP[Copy_u8IntId] = ((Copy_u8Group<<1)|Copy_u8Sub)<<4; break;
		case NVIC_G4_S4  : NVIC->IP[Copy_u8IntId] = ((Copy_u8Group<<2)|Copy_u8Sub)<<4; break;
		case NVIC_G2_S8  : NVIC->IP[Copy_u8IntId] = ((Copy_u8Group<<3)|Copy_u8Sub)<<4; break;
		case NVIC_G0_S16 : NVIC->IP[Copy_u8IntId] = Copy_u8Sub<<4                    ; break;
		default:                                                                       break;
	}
}