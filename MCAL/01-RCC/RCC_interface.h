/**********************************************/
/* Author:  Mena Ghobrial                     */
/* Date:    16 SEP 2022                       */
/* Version: V01                               */
/**********************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void MRCC_voidInitSystemClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#define RCC_AHB1   0
#define RCC_AHB2   1
#define RCC_APB1   2
#define RCC_APB2   3

/* AHB1ENR */
#define RCC_GPIOAEN     0
#define RCC_GPIOBEN     1
#define RCC_GPIOCEN     2
#define RCC_GPIODEN     3
#define RCC_GPIOEEN     4
#define RCC_GPIOHEN     7
#define RCC_GPIOCRCEN   12
#define RCC_DMA1EN      21
#define RCC_DMA2EN      22

/* AHB2ENR */
#define RCC_OTGFSEN     7

/* APB1ENR */
#define RCC_TIM2EN          0
#define RCC_TIM3EN          1
#define RCC_TIM4EN          2
#define RCC_TIM5EN          3
#define RCC_WWDGEN          11
#define RCC_SPI2EN          14
#define RCC_SPI3EN          15
#define RCC_USART2EN        17
#define RCC_I2C1EN          21
#define RCC_I2C2EN          22
#define RCC_I2C3EN          23
#define RCC_PWREN           28

/* APB2ENR */
#define RCC_TIM1EN           0
#define RCC_USART1EN         4
#define RCC_USART6EN         5
#define RCC_ADC1EN           8
#define RCC_SDIOEN           11
#define RCC_SPI1EN           12
#define RCC_SPI4EN           13
#define RCC_SYSCFGEN         14
#define RCC_TIM9EN           16
#define RCC_TIM10EN          17
#define RCC_TIM11EN          18




#endif /* RCC_INTERFACE_H */