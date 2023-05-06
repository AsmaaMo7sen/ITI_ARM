#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/**************Interfacing Macros***************/
/*controllers' different buses*/
#define RCC_AHB1              1
#define RCC_AHB2              2
#define RCC_APB1              3
#define RCC_APB2              4

#define AHB1_GPIOH            7


/**/
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID , u8 Copy_PeripheralID);
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID , u8 Copy_PeripheralID);

/**/
void RCC_voidSetSystemClock(void);


#endif
