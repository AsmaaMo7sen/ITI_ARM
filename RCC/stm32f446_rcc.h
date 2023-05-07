/*
 * stm32f446_rcc.h
 *
 *  Created on: May 4, 2023
 *      Author: moham
 */

#ifndef RCC_STM32F446_RCC_H_
#define RCC_STM32F446_RCC_H_
#include "stm32f446.h"


//This macro is to define main clock source
//Options : HSI - HSE-RC - HSE-CRYSTAL - PLL
#define HSI			1
#define HSE			2
#define HSE_CRYS	3
#define PLL			4



#define AHB_PRESCALER_1		0
#define AHB_PRESCALER_2		8
#define AHB_PRESCALER_4		9
#define AHB_PRESCALER_8		10
#define AHB_PRESCALER_16	11
#define AHB_PRESCALER_64	12
#define AHB_PRESCALER_128	13
#define AHB_PRESCALER_256	14
#define AHB_PRESCALER_512	15

#define AHB_PRESCALER	AHB_PRESCALER_1

#define APB1_PRESCALER_1	0
#define APB1_PRESCALER_2	4
#define APB1_PRESCALER_4	5
#define APB1_PRESCALER_8	6
#define APB1_PRESCALER_16	7

#define APB1_PRESCLAER		APB1_PRESCALER_1

#define APB2_PRESCALER_1	0
#define APB2_PRESCALER_2	4
#define APB2_PRESCALER_4	5
#define APB2_PRESCALER_8	6
#define APB2_PRESCALER_16	7

#define APB2_PRESCLAER		APB2_PRESCALER_1

#define SYSTEM_CLK_SRC		HSI

#define AHB1	1
#define AHB2	2
#define APB1	3
#define APB2	4

void SetClockSystem(void);

void RCC_EnablePeripheral(uint8_t BUS_ID,uint8_t PeripheralID);
void RCC_DisablePeripheral(uint8_t BUS_ID,uint8_t PeripheralID);

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);

#endif /* RCC_STM32F446_RCC_H_ */
