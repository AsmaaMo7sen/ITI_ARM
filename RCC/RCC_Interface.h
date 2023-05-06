#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "STD_TYPES.h"
typedef enum {
    OK,
    WRONG_BusID
}ERROR_STAT_type;
/***************interfacing macros*****************/
#define RCC_AHB1           1
#define RCC_AHB2           2
#define RCC_APB1           3
#define RCC_APB2           4
/***************RCC AHB1 peripherals macros******************/
#define GPIO_PORT_A         0
#define GPIO_PORT_B         1
#define GPIO_PORT_C         2
#define GPIO_PORT_D         3
#define GPIO_PORT_E         4
#define GPIO_PORT_H         7
#define CRC   C             12
#define DMA1                21
#define DMA2                22

/***************RCC AHB2 peripherals macros******************/
#define  OTGFS              7

/***************RCC APB1 peripherals macros******************/
#define TIMER_2             0
#define TIMER_3             1
#define TIMER_4             2
#define TIMER_5             3
#define WWDG                11
#define SPI_2               14
#define SPI_3               15
#define USART_2             17
#define I2C_1               21
#define I2C_2               22
#define I2C_3               23
#define PWR                 28

/***************RCC APB2 peripherals macros******************/
#define TIMER_1             0
#define USART_1             4
#define USART_6             5
#define ADC_1               3
#define SDIO                11
#define SPI_1               12
#define SPI_4               13
#define SYSCFG              14
#define TIMER_9             16
#define TIMER_10            17
#define TIMER_11            18

/*this funcution enable peripheral based on bus and the name of peripheral */
ERROR_STAT_type RCC_voidEnablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID);
/*this funcution disable peripheral based on bus and the name of peripheral */
ERROR_STAT_type RCC_voidDisablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID);
/*this funcution determine system clock */
void RCC_voidSetSystemClock(void);

#endif
