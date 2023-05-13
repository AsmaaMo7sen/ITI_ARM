/*
 * GPIO_private.h
 *
 *  Created on: May 11, 2023
 *      Author: Hardware
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_


typedef struct
{
	u32 MODER   ; //This register is to set the mode of any pin.
	u32 OTYPER  ; //This register is to set the type of output pins[PP/OD].
	u32 OSPEEDR ; //This register is to set the speed of output pins.
	u32 PUPDR   ; //This register is to select whether pull up or pull down input
	u32 IDR     ; //This register is to get the value of input pins.
	u32 ODR     ; //This register is to set the value of output pins.
	u32 BSRR    ; //This register is to set/reset any pin in atomic access
}GPIO_REG_t;


/*POINTER TO STRUCT*/
#define GPIOA    ((volatile GPIO_REG_t*)(0x40020000))
#define GPIOB    ((volatile GPIO_REG_t*)(0x40020400))
#define GPIOC    ((volatile GPIO_REG_t*)(0x40020800))


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
