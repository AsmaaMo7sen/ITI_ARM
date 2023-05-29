/*
 * stm32f446_exti.c
 *
 *  Created on: May 22, 2023
 *      Author: moham
 */
#include "stm32f446_exti.h"

void (*GlobalCallBackINT[16])(void)={NULL};

void EXTI_Init(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,void (*APP)(void))
{
	GlobalCallBackINT[PinNumber]=APP;
	uint8_t RegisterNumber,PinValue,PortAsNumber;

	/*To determine which register from the SYSCFG EXTICR is the one we need*/
	RegisterNumber=PinNumber/4;

/*	To determine which 4 bits will we need*/
	PinValue=PinNumber%4;

/*	This functions transfers the GPIOx value from Pointer address to a NUMBER*/
	PortAsNumber=GPIO_PORT_TO_NUMBER(pGPIOx);

/*	Enable the Clock peripheral for the SYSCFG*/
	RCC_EnablePeripheral(APB2,APB2_SYSCFG);

/*	Set the GPIOx we will use in the EXTICR*/
	SYSCFG->EXTICR[RegisterNumber] &= ~(0xF<<PinValue*4);
	SYSCFG->EXTICR[RegisterNumber] |= (PortAsNumber<<PinValue*4);

/*	Set the PIN Number used by the EXTI*/
	EXTI->IMR |= (1<<PinNumber);

}

void EXTI_InterruptType(uint8_t PinNumber,uint8_t InterruptPhase){

	if(InterruptPhase==EXTI_MODE_IT_FE){
		/*Set the falling edged detector*/
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR &= ~(1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_RE){
		/*Set the RISING edged detector*/
		EXTI->FTSR &= ~(1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_FRE){
		/*Set the FALLING&RISING edged detector*/
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}
}
void EXTI_ClearPending(uint8_t PinNumber){

	/*Check if the pending flag is already set*/
	if(EXTI->PR & (1<<PinNumber)){
		EXTI->PR |= (1<<PinNumber);
	}
}

void EXTI_SetSofwareINT(uint8_t PinNumber){
	EXTI->SWIER |= (1<<PinNumber);
}

void EXTI0_IRQHandler(void){
	EXTI_ClearPending(0);
	GlobalCallBackINT[0]();
}
void EXTI1_IRQHandler(void){
	EXTI_ClearPending(1);
	GlobalCallBackINT[1]();
}

void EXTI2_IRQHandler(void){
	EXTI_ClearPending(2);
	GlobalCallBackINT[2]();
}

void EXTI3_IRQHandler(void){
	EXTI_ClearPending(3);
	GlobalCallBackINT[3]();
}

void EXTI4_IRQHandler(void){
	EXTI_ClearPending(4);
	GlobalCallBackINT[4]();
}

void EXTI9_5_IRQHandler(void){

	if(EXTI->PR & (1<<9)){
		EXTI_ClearPending(9);
		GlobalCallBackINT[9]();
	}
	else if(EXTI->PR & (1<<8)){
		EXTI_ClearPending(8);
			GlobalCallBackINT[8]();
		}
	else if(EXTI->PR & (1<<7)){
		EXTI_ClearPending(7);
			GlobalCallBackINT[7]();
		}
	else if(EXTI->PR & (1<<6)){
		EXTI_ClearPending(6);
			GlobalCallBackINT[6]();
		}
	else if(EXTI->PR & (1<<5)){
		EXTI_ClearPending(5);
			GlobalCallBackINT[5]();
		}
}

void EXTI15_10_IRQHandler(void){

	if(EXTI->PR & (1<<15)){
		EXTI_ClearPending(15);
		GlobalCallBackINT[15]();
	}
	else if(EXTI->PR & (1<<14)){
		EXTI_ClearPending(14);
		GlobalCallBackINT[14]();
		}
	else if(EXTI->PR & (1<<13)){
		EXTI_ClearPending(13);
		GlobalCallBackINT[13]();
		}
	else if(EXTI->PR & (1<<12)){
		EXTI_ClearPending(12);
		GlobalCallBackINT[12]();
		}
	else if(EXTI->PR & (1<<11)){
		EXTI_ClearPending(11);
		GlobalCallBackINT[11]();
		}
	else if(EXTI->PR & (1<<10)){
		EXTI_ClearPending(10);
		GlobalCallBackINT[10]();
		}
}
