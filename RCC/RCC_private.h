/*************************************************************/
/*************************************************************/
/************     Author    : Mostafa Mahmoud     ************/
/************     file name : RCC_private.h       ************/
/************     Date      : 5/5/2023            ************/
/*************************************************************/
/*************************************************************/

/*Header file guard*/
#ifndef RCC_private_H_
#define RCC_private_H_

//Private Configurations
#define HSI            1
#define HSE_RC     	   2
#define HSE_CRYSTAL	   3
#define PLL      	   4

//Private error state enum
typedef enum
{
	InvalidPeripheralID,
	InvalidBusID,
	OK
}Error_t;

//RCC registers
/*RCC clock control register*/
#define       RCC_CR           *((volatile u32 *)(0x40023800))

/*RCC PLL configuration register*/
#define       RCC_PLLCFGR      *((volatile u32 *)(0x40023804))

/*RCC clock configuration register*/
#define       RCC_CFGR         *((volatile u32 *)(0x40023808))

/*RCC clock interrupt register */
#define       RCC_CIR          *((volatile u32 *)(0x4002380C))

/*RCC AHB1 peripheral reset register*/
#define       RCC_AHB1RSTR     *((volatile u32 *)(0x40023810))

/*RCC AHB2 peripheral reset register*/
#define       RCC_AHB2RSTR     *((volatile u32 *)(0x40023814))

/*RCC APB1 peripheral reset register for (RCC_APB1RSTR)*/
#define       RCC_APB1RSTR     *((volatile u32 *)(0x40023820))

/*RCC APB2 peripheral reset register (RCC_APB2RSTR)*/
#define       RCC_APB2RSTR     *((volatile u32 *)(0x40023824))

/*RCC AHB1 peripheral clock enable register*/
#define       RCC_AHB1ENR      *((volatile u32 *)(0x40023830))

/*RCC AHB2 peripheral clock enable register */
#define       RCC_AHB2ENR      *((volatile u32 *)(0x40023834))

/*RCC APB1 peripheral clock enable register*/
#define       RCC_APB1ENR      *((volatile u32 *)(0x40023840))

/*RCC APB2 peripheral clock enable register*/
#define       RCC_APB2ENR      *((volatile u32 *)(0x40023844))

/*RCC AHB1 peripheral clock enable in low power mode register*/
#define       RCC_AHB1LPENR    *((volatile u32 *)(0x40023850))

/*RCC AHB2 peripheral clock enable in low power mode register*/
#define       RCC_AHB2LPENR    *((volatile u32 *)(0x40023854))

/*RCC APB1 peripheral clock enable in low power mode register*/
#define       RCC_APB1LPENR    *((volatile u32 *)(0x40023860))

/*RCC APB2 peripheral clock enabled in low power mode register*/
#define       RCC_APB2LPENR    *((volatile u32 *)(0x40023864))

/*RCC Backup domain control register*/
#define       RCC_BDCR         *((volatile u32 *)(0x40023870))

/*RCC clock control & status register*/
#define       RCC_CSR          *((volatile u32 *)(0x40023874))

/*RCC spread spectrum clock generation register */
#define       RCC_SSCGR        *((volatile u32 *)(0x40023880))

/*RCC PLLI2S configuration register*/
#define       RCC_PLLI2SCFGR   *((volatile u32 *)(0x40023884))

/* RCC Dedicated Clocks Configuration Register*/
#define       RCC_DCKCFGR      *((volatile u32 *)(0x4002388C))

#endif
