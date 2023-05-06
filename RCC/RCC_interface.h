/*****************************************************************************/
/*****************************************************************************/
/******************	   		Author:    Zyad Ahmed	   		******************/
/******************			File Name: RCC_interface.h      ******************/
/******************								     	    ******************/
/*****************************************************************************/
/*****************************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
/***********************************************************************************/
/************************************ Macros **************************************/
/*********************************************************************************/

/*controllers different buses*/
#define RCC_AHB1		1
#define RCC_AHB2		2
#define RCC_APB1		3
#define RCC_APB2		4

#define AHB1_GPIOH		7

/***********************************************************************************/
/**************************** Functions prototypes ********************************/
/*********************************************************************************/

/*this function should enable the peripheral clock*/
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID);

/*this function should disable the peripheral clock*/
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID);

void RCC_voidSetSysClock(void);


#endif
