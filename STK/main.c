#include "LIB/BIT_MATHS.h"
#include "LIB/STD_LIB.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/STK/STK_interface.h"


void app(void)
{
	GPIO_voidSetOutPinValueFast(GPIO_PORTA , 0 , GPIO_OUTPUT_HIGH);
}

void main(void)
{
	STK_voidInit();

	/*****************************(1)RCC peripheral****************************/
	/*(1.1)set system clock*/
	RCC_voidSetSystemClock();      //high speed Internal

	/*(1.2)enable clock over GPIOA*/
	RCC_voidEnablePeripheralClock(RCC_AHB1 , 0) ;    //GPIOA enable


	/****************************(2)GPIO peripheral****************************/
	/*(2.1)set Pin A0 to be connected to the led - initially OFF*/
	GPIO_voidInitOutputPin(GPIO_PORTA , 0 ,GPIO_PUSH_PULL ,GPIO_LOW_SPEED);
	GPIO_voidSetOutPinValueFast(GPIO_PORTA , 0 , GPIO_OUTPUT_LOW);


	/****************************(3)NVIC peripheral****************************/
//	/*(3.1)set software priority distribution*/
//	NVIC_voidInit();
//
//	/*(3.2)set software priority*/
//	NVIC_voidSetSWPriority(0 ,7 ); //set software priority = 0 for exti1
//
//	/*(3.3)enable NVIC enable for EXTI1*/
//	NVIC_voidEnableInterrupt(7);   //enable EXTI1 NVIC

	while(1)
	{
		GPIO_voidSetOutPinValueFast(GPIO_PORTA , 0 , GPIO_OUTPUT_HIGH);
		STK_voidDelaySync(1000000);
		GPIO_voidSetOutPinValueFast(GPIO_PORTA , 0 , GPIO_OUTPUT_LOW);
		STK_voidDelaySync(1000000);
	}


}


