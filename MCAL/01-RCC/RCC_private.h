/**********************************************/
/* Author:  Mena Ghobrial                     */
/* Date:    16 SEP 2022                       */
/* Version: V01                               */
/**********************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_BASE_ADDRESS       0x40023800 


typedef struct{
	volatile u32 CR         ;
	volatile u32 PLLCFGR    ;
	volatile u32 CFGR       ;
	volatile u32 CIR        ;
	volatile u32 AHB1RSTR   ;
	volatile u32 AHB2RSTR   ;
	u32 Res1[2]             ;
	volatile u32 APB1RSTR   ;
	volatile u32 APB2RSTR   ;
	u32 Res2[2]             ;
	volatile u32 AHB1ENR    ;
	volatile u32 AHB2ENR    ;
	u32 Res3[2]             ;
	volatile u32 APB1ENR    ;
	volatile u32 APB2ENR    ;
	u32 Res4[2]             ;
	volatile u32 AHB1LPENR  ;
	volatile u32 AHB2LPENR  ;
	u32 Res5[2]             ;
	volatile u32 APB1LPENR  ;
	volatile u32 APB2LPENR  ;
	u32 Res6[2]             ;
	volatile u32 BDCR       ;
	volatile u32 CSR        ;
	u32 Res7[2]             ;
	volatile u32 SSCGR      ;
	volatile u32 PLLI2SCFGR ;
	u32 Res8                ;
	volatile u32 DCKCFGR    ;
}RCC_t;


#define RCC   ((RCC_t*) RCC_BASE_ADDRESS)

/* Clock Types */
#define RCC_HSE_CRYSTAL  0
#define RCC_HSE_RC       1
#define RCC_HSI          2
#define RCC_PLL          3


/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2       0
#define RCC_PLL_IN_HSE_DIV_2       1
#define RCC_PLL_HSE                2

#endif /* RCC_PRIVATE_H */