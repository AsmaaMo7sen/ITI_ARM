
/**********************************************************************/
/* Author  : Osama Gamil 											  */
/* Date    : 29/4/2023 												  */
/* Version : V01									   				  */
/**********************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/*CLock types  */

/*******************Register Defination *****************/

#define RCC_BASEADDRESS 0x40023800

/*enable or disable the clock that get in the system
 * we use RC Register and CFGR
 * */
#define RCC_CR				*((volatile u32 *)RCC_BASEADDRESS + 0x00)

#define RCC_PLLCFGR 		*((volatile u32 *)RCC_BASEADDRESS + 0x04)
	
#define RCC_CFGR  			*((volatile u32 *)RCC_BASEADDRESS + 0x08)

#define RCC_CIR				*((volatile u32 *)RCC_BASEADDRESS + 0x0C)

#define RCC_AHB1RSTR		*((volatile u32 *)RCC_BASEADDRESS + 0x10)
/*for chossing the clk  */
#define RCC_AHB2RSTR		*((volatile u32 *)RCC_BASEADDRESS + 0x14)

#define RCC_APB1RSTR 		*((volatile u32 *)RCC_BASEADDRESS + 0x20)

#define RCC_APB2RSTR		*((volatile u32 *)RCC_BASEADDRESS + 0x24)

#define RCC_AHB1ENR 		*((volatile u32 *)RCC_BASEADDRESS + 0x30)

#define RCC_AHB2ENR			*((volatile u32 *)RCC_BASEADDRESS + 0x34)

#define RCC_APB1ENR			*((volatile u32 *)RCC_BASEADDRESS + 0x40)

#define RCC_APB2ENR			*((volatile u32 *)RCC_BASEADDRESS + 0x44)

#define RCC_AHB1LPENR		*((volatile u32 *)RCC_BASEADDRESS + 0x50)

#define RCC_AHB2LPENR		*((volatile u32 *)RCC_BASEADDRESS + 0x54)

#define RCC_APB1LPENR		*((volatile u32 *)RCC_BASEADDRESS + 0x60)

#define RCC_APB2LPENR		*((volatile u32 *)RCC_BASEADDRESS + 0x64)

#define RCC_BDCR			*((volatile u32 *)RCC_BASEADDRESS + 0x70)

#define RCC_CSR				*((volatile u32 *)RCC_BASEADDRESS + 0x74)

#define RCC_SSCGR			*((volatile u32 *)RCC_BASEADDRESS + 0x80)

#define RCC_PLLI2SCFGR		*((volatile u32 *)RCC_BASEADDRESS + 0x84)

#define RCC_DCKCFGR			*((volatile u32 *)RCC_BASEADDRESS + 0x8C)


/*******************	CLock types 	*****************/
#define RCC_HSE_CRYSTAL		0	
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_RLL 			4

/******************		PLL Types	*********************/
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE_DIV 		2



#define BIT_NUM0 	0
#define BIT_NUM1 	1
#define BIT_NUM2 	2
#define BIT_NUM3 	3
#define BIT_NUM4 	4
#define BIT_NUM5 	5
#define BIT_NUM6 	6
#define BIT_NUM16 	16
#define BIT_NUM18 	18
#define BIT_NUMB24	24
#endif 
