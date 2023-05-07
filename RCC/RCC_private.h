/*
 * RCC_private.h
 *
 *  Created on: May 4, 2023
 *      Author: mohnd
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/*System clock configurations*/
#define HSI          1
#define HSC_RC       2
#define HSC_CRYSTAL  3
#define PLL          4
/*                         peripheral connected on AHB1                           */
// GPIO:
#define GPIOAEN     0 // this macro to define GPIO port a enable bit.
#define GPIOBEN     1   // this macro to define GPIO port b enable bit.
#define GPIOCEN     2// this macro to define GPIO port c enable bit.
#define GPIODEN     3// this macro to define GPIO port d enable bit.
#define GPIOEEN     4// this macro to define GPIO port e enable bit.
#define GPIOHEN     7// this macro to define GPIO port H clock enable bit.

/*********************************************************************************/
//CRC:
#define CRCEN       12


/*********************************************************************************/


//DMA:
#define DMA1        21
#define DMA2        22

/*********************************************************************************/


/*                           peripheral connected on AHB2                         */

//OTG FS:
#define OTGFSEN     7

/*********************************************************************************/

/*                            peripheral connected on APB1                        */


//TIMERS:
#define TIM2EN     0  // timer 2 clock enable
#define TIM3EN     1  // timer 3 clock enable
#define TIM4EN     2  // timer 4 clock enable
#define TIM5EN     3  // timer 5 clock enable


/*********************************************************************************/

// WWDOG:
#define  WWDGEN    11 // window watch dog timer clock  enable

/*********************************************************************************/
//SPI :
#define SPI2EN     14
#define SPI3EN     15


/*********************************************************************************/
// UART:
#define  UART2EN   17

/*********************************************************************************/
// I2C :

#define I2C1EN     21
#define I2C1EN     22
#define I2C1EN     23

/*********************************************************************************/
// PWR:
#define PWREN      28


/*                           peripheral connected on AHPB2                         */

// TIMER:
#define TIM1EN      0
#define TIM9EN      16
#define TIM10EN     17
#define TIM11EN     18

/*********************************************************************************/
// UART:
#define UART1EN     4
#define UART6EN     5

/*********************************************************************************/
//ADC:
#define ADC1        8

/*********************************************************************************/
//SDIO:
#define SDIOEN     11

/*********************************************************************************/
// SPI:
#define SPI1EN     12

#define SPI4En     13

/*********************************************************************************/
//SYSCFGEN:
#define SYSCFGEN   14

/*********************************************************************************/
//

/*                               RCC Registers                                    */

//this reg used to set the clock of M
#define  RCC_CR        *((volatile u32 *)0x40023800)

#define  RCC_PLLCFGR   *((volatile u32 *)0x40023804)
// this reg too used to set clock system for M with RCC_CR
#define  RCC_CFGR      *((volatile u32 *)0x40023808)

#define  RCC_CIR       *((volatile u32 *)0x4002380C)

#define  RCC_AHB1RSTR  *((volatile u32 *)0x40023810)

#define  RCC_AHB2RSTR  *((volatile u32 *)0x40023814)

#define  RCC_APB1RSTR  *((volatile u32 *)0x40023820)

#define  RCC_APB2RSTR  *((volatile u32 *)0x40023824)

#define  RCC_AHB1ENR   *((volatile u32 *)0x40023830)

#define  RCC_AHB2ENR   *((volatile u32 *)0x40023834)

#define  RCC_APB1ENR   *((volatile u32 *)0x40023840)

#define  RCC_APB2ENR   *((volatile u32 *)0x40023844)

#define  RCC_AHB1PENR  *((volatile u32 *)0x40023850)

#define  RCC_AHB2PENR  *((volatile u32 *)0x40023854)

#define  RCC_APB1PENR  *((volatile u32 *)0x40023860)

#define  RCC_APB2PENR  *((volatile u32 *)0x40023864)

#define  RCC_BDCR      *((volatile u32 *)0x40023870)

#define  RCC_CSR       *((volatile u32 *)0x40023874)

#define  RCC_SSCGR     *((volatile u32 *)0x40023880)

#define  RCC_PLLI2SCFGR *((volatile u32 *)0x40023884)

#define  RCC_DCKCFGR   *((volatile u32 *)0x4002388C)

#endif /* RCC_PRIVATE_H_ */
