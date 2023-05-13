
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "RCC_private.h"
#define RCC_AHB1	1
#define RCC_AHB2	2
#define RCC_APB1	3
#define RCC_APB2	4
#define RCC_GPIOA   0
#define RCC_GPIOB   1
#define RCC_GPIOC   2
#define RCC_GPIOD   3
#define RCC_GPIOE   4
#define RCC_GPIOH	7

void RCC_enable_preihreal_clock(u8 bus_id,u8 peripheral_id);
void RCC_disable_preihreal_clock(u8 bus_id,u8 peripheral_id);
void RCC_set_system_clock(System_clock_source source);

#endif
