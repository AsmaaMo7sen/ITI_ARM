
/**********************************************************************/
/* Author  : Osama Gamil 											  */
/* Date    : 29/4/2023 												  */
/* Version : V01									   				  */
/**********************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/*enum error state */

typedef enum errorState{
	ok, 								/*The function run will */
	EnableClockError_invalidPort,		/*Error in the Enable clock function */
	EnableClockError_invalidPin,		/*Error in the Enable clock function */
	DisableClockError_invalidPort,		/*Error in the Disable clock function */
	DisableClockError_invalidPin,		/*Error in the Disable clock function */

}ErrorState;

/*for define which bus peripheral to enable  */
#define  RCC_AHB1   0
#define  RCC_AHB2	1
#define  RCC_APB1   2
#define  RCC_APB2   3

/*********************** Peripheral Clock enable *********************/

/* For bus AHB1 */
#define  AHB1_MGPIOA 	0
#define  AHB1_MGPIOB 	1
#define  AHB1_MGPIOC 	2
#define  AHB1_MGPIOD 	3
#define  AHB1_MGPIOE 	7
#define  AHB1_CRC	 	12
#define  AHB1_DMA1 		21
#define  AHB1_DMA2 		22

/* For bus AHB2 */
#define  AHB2_OTGFS		7


/* For bus APB1 */
#define  APB1_TIM2	 	0
#define  APB1_TIM3	 	1
#define  APB1_TIM4	 	2
#define  APB1_TIM5	 	3
#define  APB1_WWDG	 	11
#define  APB1_SPI2	 	14
#define  APB1_SPI3 		15
#define  APB1_USART2	17
#define  APB1_I2C1 		21
#define  APB1_I2C2 		22
#define  APB1_I2C3 		23
#define  APB1_PWR 		28

/* For bus APB2 */
#define  APB2_TIM1	 	0
#define  APB2_USART1 	4
#define  APB2_USART6 	5
#define  APB2_ADC1 		8
#define  APB2_SDIO		11
#define  APB2_SPI1 		12
#define  APB2_SPI4 		13
#define  APB2_SYSCFG	14
#define  APB2_TIM9 		16
#define  APB2_TIM10		17
#define  APB2_TIM11 	18



/* 	 this function the to select the peripheral clock
 * 	 Copy_u8BusId :
 * 	 for BUS Selected
 * 	 	1- RCC_AHB1
 * 	 	2- RCC_AHB2
 * 	 	3- RCC_APB1
 * 	 	4- RCC_APB2
 *
 *	 Copy_u8PeriphId :
 *
 *
 *	 is the pin number of the peripheral in the data sheet
 * */

ErrorState RCC_ErrorStateEnableClock(u8 Copy_u8BusId ,  u8  Copy_u8PeriphId);

ErrorState RCC_ErrorStateDisableClock(u8 Copy_u8BusId ,  u8  Copy_u8PeriphId);

/*Prebuild Config */
ErrorState RCC_ErrorStateInitSysClk(void);




#endif 
