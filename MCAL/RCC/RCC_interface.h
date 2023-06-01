#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"



//Private error state enum
typedef enum
{
	InvalidPeripheralID,
	InvalidBusID,
	OK
}Error_t;

//Interfacing Macros
/*controller's different busses*/
#define RCC_AHB1    1
#define RCC_AHB2    2
#define RCC_APB1    3
#define RCC_APB2    4

/*ABH1 Peripherals*/
#define AHB1_GPIOAEN        0
#define AHB1_GPIOBEN        1
#define AHB1_GPIOCEN        2
#define AHB1_GPIODEN        3
#define AHB1_GPIOEEN        4
#define AHB1_GPIOHEN        7
#define AHB1_CRCEN          12
#define AHB1_DMA1EN         21
#define AHB1_DMA2EN         22

/*ABH2 Peripherals*/
#define AHB2_OTGFSEN        7

/*APB1 Peripherals*/
#define APB1_TIM2EN         0
#define APB1_TIM3EN         1
#define APB1_TIM4EN         2
#define APB1_TIM5EN         3
#define APB1_WWDGEN         11
#define APB1_SPI2EN         14
#define APB1_SPI3EN         15
#define APB1_USART2EN       17
#define APB1_I2C1EN         21
#define APB1_I2C2EN         22
#define APB1_I2C3EN         23
#define APB1_PWREN          28

/*APB2 Peripherals*/
#define APB2_TIM1EN         0
#define APB2_USART1EN       4
#define APB2_USART6EN       5
#define APB2_ADC1EN         8
#define APB2_SDIOEN         11
#define APB2_SPI1EN         12
#define APB2_SPI4EN         13
#define APB2_SYSCFGEN       14
#define APB2_TIM9EN         16
#define APB2_TIM10EN        17
#define APB2_TIM11EN        18



//Functions prototypes
/*This function is used to Enable a certain peripheral's clock*/
Error_t RCC_voidEnablePeripheralClock(u8 copy_u8BusID, s8 copy_u8PeripheralID);

/*This function is used to Disable a certain peripheral's clock*/
Error_t RCC_voidDisablePeripheralClock(u8 copy_u8BusID, s8 copy_u8PeripheralID);

/*This function is used to set the system's clock clock*/
void RCC_voidSetSystemClock(void);

#endif
