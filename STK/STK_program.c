#include "../../LIB/STD_LIB.h"
#include "../../LIB/BIT_MATHS.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"



/*****************************Global variables****************************/

/* Array of global pointers to functions to set call back of SYSTICK*/
void (*Global_PtrToFunc)(void) = NULL ;

/*************************Functions' implementation***********************/

void STK_voidInit(void)
{
	/*Disable Interrupt , clock source = AHB/8 */
	/*System clock = HSI -> tick time = 0.5 microsecond*/
	STK->CTRL = 0 ;

	/*Reset LOAD and VAL registers*/
	STK->LOAD = 0 ;
	STK->VAL  = 0 ;

}

void STK_voidDelaySync(u32 Copy_u32Delay_us)
{
	/*(1)Disable interrupt*/
	CLR_BIT(STK->CTRL , 1 ) ;

	/*(2)Set lOAD register value to get the target delay*/
	STK->LOAD = (Copy_u32Delay_us*2) ;

	/*(3)Run systick*/
	SET_BIT(STK->CTRL , 0) ;

	/*(4)Polling till the end of target time*/
	/*(5)Clear flag*/
	while((GET_BIT(STK->CTRL,16))==0);

	/*(6)Stop timer*/
	CLR_BIT(STK->CTRL , 0) ;

	/*(7)Reset LOAD and VAL registers*/
	STK->LOAD = 0 ;
	STK->VAL  = 0 ;
}

void STK_voidDelayAsync(u32 Copy_u32Delay_us , void(*Copy_ptrToFunc)(void))
{
	/*(1)Enaable interrupt*/
	SET_BIT(STK->CTRL , 1 ) ;

	/*(2)Set lOAD register value to get the target delay*/
	STK->LOAD = Copy_u32Delay_us / 2 ;

	/*(3)Set call back*/
	if(Copy_ptrToFunc != NULL)
	{
		Global_PtrToFunc = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}

	/*(4)Run systick*/
	SET_BIT(STK->CTRL , 0) ;
}

/***********************************ISRs implementation********************************/

/*systick ISR*/
void Systick_Handler(void)
{
	/*Calling application function*/
	Global_PtrToFunc();
}




