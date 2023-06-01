#include "HAL/LEDMTRX/LEDMTRX_interface.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "HAL/LEDMTRX/LEDMTRX_interface.h"
#include "HAL/SERinPARout/SinPout_interface.h"
#include "song.h" 


/**
 * DONE: AUDIO 
 * DONE: Display name LEDMATTRIX
 * TODO: 3-bit LEDMATRIX
 * TODO: DELAY_ASYNC periodic song
 * TODO: RTOS
 * 
*/

void main(void)
{

	/***************************/
	/*  RCC Peripheral */

	/* Set System Clock */
	RCC_voidSetSystemClock();      // High Speed External

	/*enable clock over GPIOA */
	RCC_voidEnablePeripheralClock(RCC_AHB1,AHB1_GPIOAEN);   // GPIOA_Enable

	/*enable clock over GPIOA */
	// RCC_voidEnablePeripheralClock(RCC_AHB1,AHB1_GPIOBEN);   // GPIOB_Enable

	
	/*  SYSTICK Peripheral */
	STK_voidInit();

	/*  NVIC Peripheral */

		SIN_enable_output(SinPout1);
		SIN_enable_output(SinPout2);
	while(1)
	{	
		for(u8 i = 0 ; i < 200 ; i++)
		{

		SIN_shift_out(i,SinPout2);
		SIN_shift_out(i,SinPout1);
		SIN_latch_data(SinPout1);
		SIN_latch_data(SinPout2);
		STK_voidDelaySync(10000);
		} 
		

	}




}

