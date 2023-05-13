/*
 * GPIO_private.h
 *
 *  Created on: May 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#define GPIOA_START	(0x40020000)
#define GPIOB_START	(0x40020400)
#define GPIOC_START	(0x40020800)

typedef struct{
	u32 MODER	;
	u32 OTYPER	;
	u32 OSPEEDR	;
	u32 PUPDR	;
	u32 IDR		;
	u32 ODR		;
	u32 BSRR	;
	u32 LCKR	;
	u32 AFRL	;
	u32 AFRH	;
}GPIO_Reg;

#define GPIOA	((volatile GPIO_Reg*)(GPIOA_START))
#define GPIOB	((volatile GPIO_Reg*)(GPIOB_START))
#define GPIOC	((volatile GPIO_Reg*)(GPIOC_START))

//	GPIOC->PUPDR
#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
