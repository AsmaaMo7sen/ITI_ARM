/*******************************************/
/* Author: Mena Ghobrial                   */
/* Date:   18 SEP 2022                     */
/* Version: V01                            */
/*******************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define GPIOA_BASE_ADDRESS          0x40020000
#define GPIOB_BASE_ADDRESS          0x40020400
#define GPIOC_BASE_ADDRESS          0x40020800
#define GPIOD_BASE_ADDRESS          0x40020C00
#define GPIOE_BASE_ADDRESS          0x40021000
#define GPIOH_BASE_ADDRESS          0x40021C00

typedef struct
{
	volatile u32 MODER   ;
	volatile u32 OTYPER  ;
	volatile u32 OSPEEDR ;
	volatile u32 PUPDR   ;
	volatile u32 IDR     ;
	volatile u32 ODR     ;
	volatile u32 BSRR    ;
	volatile u32 LCKR    ;
	volatile u32 AFRL    ;
	volatile u32 AFRH    ;
}GPIOx_t;

#define GPIOA  ((GPIOx_t*) GPIOA_BASE_ADDRESS)
#define GPIOB  ((GPIOx_t*) GPIOB_BASE_ADDRESS)
#define GPIOC  ((GPIOx_t*) GPIOC_BASE_ADDRESS)
#define GPIOD  ((GPIOx_t*) GPIOD_BASE_ADDRESS)
#define GPIOE  ((GPIOx_t*) GPIOE_BASE_ADDRESS)
#define GPIOH  ((GPIOx_t*) GPIOH_BASE_ADDRESS)


#endif /* GPIO_PRIVATE_H */