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

#define MAX_PERIPHIRAL	31

/***********************************************************************************/
/**************************** Functions prototypes ********************************/
/*********************************************************************************/

/*this function should enable the peripheral clock*/
RCC_ErrorStatus RCC_voidEnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID);

/*this function should disable the peripheral clock*/
RCC_ErrorStatus RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_PeripheralID);

/*this function should choose the clock that system will use*/
void RCC_voidSetSysClock(void);


/***********************************************************************************/
/**************************** Enum for Error state ********************************/
/*********************************************************************************/
typedef enum
{
	NoError,
	WrongPeripheral,
	WrongBus,
}RCC_ErrorStatus;




#endif
