/*
 * GPIO_private.h
 *
 *  Created on: May 11, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_


typedef struct
{
	u32 MODER    ;         //this register is to set the mode of any pin
	u32 OTYPER   ;         //this register is to set the type of output pins(push pull/open drain)
	u32 OSPEEDR  ;         //this register is to set the speed of output pins
	u32 PUPDR    ;         //this register is to select whether pull up or down input
	u32 IDR      ;         //this register is to get the value of input pins
	u32 ODR      ;         //this register is to set the value of output pins
    u32 BSRR     ;         //this reg is to set/reset
}GPIO_REG_t;


/*POINTER TO STRUCT*/
#define GPIOA       ((volatile GPIO_REG_t*)(0x40020000))
#define GPIOB       ((volatile GPIO_REG_t*)(0x40020400))
#define GPIOC       ((volatile GPIO_REG_t*)(0x40020800))


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
