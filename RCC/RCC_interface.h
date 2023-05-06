#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/*************Interfacing Macros ***************/

/*Controllers' different buses*/

#define RCC_AHB1 1
#define RCC_AHB2 2
#define RCC_APB1 3
#define RCC_APB2 4


/*This Function responsible to enable specific peripheral clock*/
u8 RCC_u8EnablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/*This Function responsible to disable peripheral clock*/
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);


/*This Function is used to set system clock between:HSI,HSE,PLL*/
void RCC_voidSetSystemClock(void);








#endif
