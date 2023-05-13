/**************************************************************************/
/*Author      : Hager Hesham										      */
/*File Name   : RCC_private.h                                             */
/*Description : This file contains private parameters of RCC module       */
/*Date        : 7 May 2023                                                */
/**************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


/*System Clock Configurations*/
#define HSI              1
#define HSE_RC           2
#define HSE_CRYSTAL      3
#define PLL              4

/***************RCC Registers*************/
#define RCC_CR           (*((volatile u32*)(0x40023800)))
#define RCC_PLLCFGR      (*((volatile u32*)(0x40023804)))
#define RCC_CFGR         (*((volatile u32*)(0x40023808)))
#define RCC_CIR          (*((volatile u32*)(0X4002380C)))

#define RCC_AHB1RSTR     (*((volatile u32*)(0x40023810)))
#define RCC_AHB2RSTR     (*((volatile u32*)(0X40023814)))
#define RCC_APB1RSTR     (*((volatile u32*)(0x40023820)))
#define RCC_APB2RSTR     (*((volatile u32*)(0X40023824)))

#define RCC_AHB1ENR      (*((volatile u32*)(0x40023830)))
#define RCC_AHB2ENR      (*((volatile u32*)(0x40023834)))
#define RCC_APB1ENR      (*((volatile u32*)(0x40023840)))
#define RCC_APB2ENR      (*((volatile u32*)(0x40023844)))

#define RCC_AHB1LPENR    (*((volatile u32*)(0x40023850)))
#define RCC_AHB2LPENR    (*((volatile u32*)(0x40023854)))
#define RCC_APB1LPENR    (*((volatile u32*)(0x40023860)))
#define RCC_APB2LPENR    (*((volatile u32*)(0x40023864)))

#define RCC_BDCR         (*((volatile u32*)(0x40023870)))
#define RCC_CSR          (*((volatile u32*)(0x40023874)))
#define RCC_SSCGR        (*((volatile u32*)(0x40023880)))

#define RCC_PLLI2SCFGR   (*((volatile u32*)(0x40023884)))
#define RCC_DCKCFGR      (*((volatile u32*)(0x4002388C)))


/*************Pin Configurations**************/
/*RCC clock control register (RCC_CR)*/
#define RCC_CR_HSI_ON         0   //enable HSI
#define RCC_CR_HSI_RDY        1   //HSI ready bit (read only)
#define RCC_CR_HSI_TRIM       0xFFFFFF08
#define RCC_CR_HSI_CAL        0xFFFF00FF
#define RCC_CR_HSE_ON         16  //enable HSE
#define RCC_CR_HSE_RDY        17  //HSE ready bit (read only)
#define RCC_CR_HSE_BYP        18  //HSE bypass mode
#define RCC_CR_CSS_ON         19  //clock security system bit (when enabled & HSE fails -> HSI ON)
#define RCC_CR_PLL_ON         24  //enable PLL
#define RCC_CR_PLL_RDY        25  //PLL ready bit (read only)



/*RCC clock interrupt register (RCC_CIR)*/
#define RCC_CIR_CSSC          23 //Clock security system interrupt clear
#define RCC_CIR_PLLI2SRDYC    21 //PLLI2S ready interrupt clear
#define RCC_CIR_PLLRDYC       20 //Main PLL(PLL) ready interrupt clear
#define RCC_CIR_HSERDYC       19 //HSE ready interrupt clear
#define RCC_CIR_HSIRDYC       18 //HSI ready interrupt clear
#define RCC_CIR_LSERDYC       17 //LSE ready interrupt clear
#define RCC_CIR_LSIRDYC       16 //LSI ready interrupt clear
#define RCC_CIR_PLLI2SRDYIE   13 //PLLI2S ready interrupt enable
#define RCC_CIR_PLLRDYIE      12 //Main PLL (PLL) ready interrupt enable
#define RCC_CIR_HSERDYIE      11 //HSE ready interrupt enable
#define RCC_CIR_HSIRDYIE      10 //HSI ready interrupt enable
#define RCC_CIR_LSERDYIE      9 //LSE ready interrupt enable
#define RCC_CIR_LSIRDYIE      8 //LSI ready interrupt enable
#define RCC_CIR_CSSF          7 //Clock security system interrupt flag
#define RCC_CIR_PLLI2SRDYF    5 //PLLI2S ready interrupt flag
#define RCC_CIR_PLLRDYF       4 //Main PLL (PLL) ready interrupt flag
#define RCC_CIR_HSERDYF       3 //HSE ready interrupt flag
#define RCC_CIR_HSIRDYF       2 //HSI ready interrupt flag
#define RCC_CIR_LSERDYF       1 //LSE ready interrupt flag
#define RCC_CIR_LSIRDYF       0 //LSI ready interrupt flag


/*RCC clock configuration register (RCC_CFGR)*/
#define RCC_CFGR_MCO21        31 //Microcontroller clock output 2
#define RCC_CFGR_MCO20        30
#define RCC_CFGR_MCO2PRE2     29 //MCO2 prescaler
#define RCC_CFGR_MCO2PRE1     28
#define RCC_CFGR_MCO2PRE0     27
#define RCC_CFGR_MCO1PRE2     26 //MCO1 prescaler
#define RCC_CFGR_MCO1PRE1     25
#define RCC_CFGR_MCO1PRE0     24
#define RCC_CFGR_I2SSRC       23  //I2S clock selection
#define RCC_CFGR_MCO11        22   //Microcontroller clock output 1
#define RCC_CFGR_MCO10        21
#define RCC_CFGR_RTCPRE4      20 //HSE division factor for RTC clock
#define RCC_CFGR_RTCPRE3      19
#define RCC_CFGR_RTCPRE2      18
#define RCC_CFGR_RTCPRE1      17
#define RCC_CFGR_RTCPRE0      16
#define RCC_CFGR_PPRE22       15 //APB high-speed prescaler (APB2)
#define RCC_CFGR_PPRE21       14
#define RCC_CFGR_PPRE20       13
#define RCC_CFGR_PPRE12       12 //APB Low speed prescaler (APB1)
#define RCC_CFGR_PPRE11       11
#define RCC_CFGR_PPRE10       10
#define RCC_CFGR_HPRE3        7 //AHB prescaler
#define RCC_CFGR_HPRE2        6
#define RCC_CFGR_HPRE1        5
#define RCC_CFGR_HPRE0        4
#define RCC_CFGR_SWS1         3 //System clock switch status
#define RCC_CFGR_SWS0         2
#define RCC_CFGR_SW1          1 //System clock switch
#define RCC_CFGR_SW0          0


/*RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)*/
#define RCC_AHB1ENR_DMA2EN    22 //DMA2 clock enable
#define RCC_AHB1ENR_DMA1EN    21 //DMA1 clock enable
#define RCC_AHB1ENR_CRCEN     12 //CRC clock enable
#define RCC_AHB1ENR_GPIOHEN   7 //IO port H clock enable
#define RCC_AHB1ENR_GPIOEEN   4 //IO port E clock enable
#define RCC_AHB1ENR_GPIODEN   3 //IO port D clock enable
#define RCC_AHB1ENR_GPIOCEN   2 //IO port C clock enable
#define RCC_AHB1ENR_GPIOBEN   1 //IO port B clock enable
#define RCC_AHB1ENR_GPIOAEN   0 //IO port A clock enable

/*RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)*/
#define RCC_AHB2ENR_OTGFSEN   7 //USB OTG FS clock enable

/*RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
#define RCC_APB1ENR_PWREN     28 //Power interface clock enable
#define RCC_APB1ENR_I2C3EN    23 //I2C3 clock enable
#define RCC_APB1ENR_I2C2EN    22 //I2C2 clock enable
#define RCC_APB1ENR_I2C1EN    21 //I2C1 clock enable
#define RCC_APB1ENR_USART2EN  17 //USART2 clock enable
#define RCC_APB1ENR_SPI3EN    15 //SPI3 clock enable
#define RCC_APB1ENR_SPI2EN    14 //SPI2 clock enable
#define RCC_APB1ENR_WWDGEN    11 //Window watchdog clock enable
#define RCC_APB1ENR_TIM5EN    3 //TIM5 clock enable
#define RCC_APB1ENR_TIM4EN    2 //TIM4 clock enable
#define RCC_APB1ENR_TIM3EN    1 //TIM3 clock enable
#define RCC_APB1ENR_TIM2EN    0 //TIM2 clock enable

/*RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
#define RCC_APB2ENR_TIM11EN   18 //TIM11 clock enable
#define RCC_APB2ENR_TIM10EN   17 //TIM10 clock enable
#define RCC_APB2ENR_TIM9EN    16 //TIM9 clock enable
#define RCC_APB2ENR_SYSCFGEN  14 //System configuration controller clock enable
#define RCC_APB2ENR_SPI4EN    13 //SPI4 clock enable
#define RCC_APB2ENR_SPI1EN    12 //SPI1 clock enable
#define RCC_APB2ENR_SDIOEN    11 //SDIO clock enable
#define RCC_APB2ENR_ADC1EN    8 //ADC1 clock enable
#define RCC_APB2ENR_USART6EN  5 //USART6 clock enable
#define RCC_APB2ENR_USART1EN  4 //USART1 clock enable
#define RCC_APB2ENR_TIM1EN    0 //TIM1 clock enable


#endif
