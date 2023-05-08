/************************************************************************/
/*Author      : Saad Mohamed										    */
/*File Name   : RCC_interface.h                                         */
/*Layer       : MCAL								 	        	    */
/*Description : This file contains Interfacing parameters of RCC module */
/*Date        : 5 May 2023                                              */
/************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*************************************************************************/
/**************************Interfacing Macros*****************************/
/*************************************************************************/

/*Bus Macros*/
#define RCC_AHB1	1
#define RCC_AHB2	2
#define RCC_APB1	3
#define RCC_APB2	4

/*Peripheral Macros*/
#define RCC_GPIOAEN 0
#define RCC_GPIOBEN 1
#define RCC_GPIOCEN 2
#define RCC_GPIODEN 3
#define RCC_GPIOEEN 4
#define RCC_GPIOHEN 7
#define RCC_CRCEN   12
#define RCC_DMA1EN  21
#define RCC_DMA2EN  22


/*************************************************************************/
/************************Functions' prototypes****************************/
/*************************************************************************/

/*This Function Shall Initialize the RCC peripheral*/
void RCC_voidSetSystemClock(void);

/*This Function Shall Enable a Specific Peripheral*/
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

/*This Function Shall Disable a Specific Peripheral*/
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_u8PeripheralID);

#endif
