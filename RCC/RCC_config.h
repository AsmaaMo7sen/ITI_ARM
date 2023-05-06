
/**********************************************************************/
/* Author  : Osama Gamil 											  */
/* Date    : 29/4/2023 												  */
/* Version : V01									   				  */
/**********************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* This macro is to define the system clock source
 * Option  	:  RCC_HSE_CRYSTAL
			:  RCC_HSE_RC
			:  RCC_HSI
			:  RCC_RLL

		*/
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL


/* RCC_PLL_IN_HSI_DIV_2
   RCC_PLL_IN_HSE_DIV_2
   RCC_PLL_IN_HSE
*/
/*select value if you have RCC_PLL as input clock source  */
#if			RCC_CLOCK_TYPE == RCC_RLL
#define 	RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV_2		
#endif

 
/* Options from 2 to 16 */
/*select value if you have RCC_PLL as input clock source  */
#if			RCC_CLOCK_TYPE == RCC_RLL
#define 	RCC_PLL_MUL_VAL		4
#endif



#endif 
