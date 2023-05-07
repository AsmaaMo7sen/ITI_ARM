/**************************************************************************/
/*Author      : Hager Hesham										      */
/*File Name   : RCC_interface.h                                           */
/*Description : This file contains interfacing parameters of RCC module   */
/*Date        : 7 May 2023                                                */
/**************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/*************Interfacing Macros ***************/

/*Controllers' different buses*/
#define RCC_AHB1 1
#define RCC_AHB2 2
#define RCC_APB1 3
#define RCC_APB2 4

/*This Enum contains different Error states*/
typedef enum
{
	RightData,
	WrongBusID,
	WrongPeripheralID

}RCC_ErrorState_t;


/*This Function responsible to enable specific peripheral clock*/
RCC_ErrorState_t RCC_u8EnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/*This Function responsible to disable peripheral clock*/
RCC_ErrorState_t RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);


/*This Function is used to set system clock between:HSI,HSE,PLL*/
void RCC_voidSetSystemClock(void);








#endif
