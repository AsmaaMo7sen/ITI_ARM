#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "STD_TYPES.h"

/***************interfacing macros*********/
#define RCC_AHB1        1
#define RCC_AHB2        2
#define RCC_APB1        3
#define RCC_APB2        4
#define 5
#define 6
#define 7
#define 8
/**/
#define 1
#define 2
#define 3
#define 4
#define 5
#define 6
#define 7
#define 8
/**/
#define 1
#define 2
#define 3
#define 4
#define 5
#define 6
#define 7
#define 8
/*this funcution enable peripheral based on bus and the name of peripheral */
void RCC_voidEnablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID);
/*this funcution disable peripheral based on bus and the name of peripheral */
void RCC_voidDisablePeripheralClock(u8 copy_u8BusID,u8 copy_u8PeripheralID);
/*this funcution determine system clock */
void RCC_voidSetSystemClock(void);

#endif
