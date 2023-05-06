#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/*******************************interfacing macros*******************************
 *control difrant buses*********************************************************/
#define RCC_AHB1    1
#define RCC_AHB2    2
#define RCC_APB1    3
#define RCC_APB2    4
u8 RCC_u8enablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID);
u8 RCC_u8DisablePrepheralClock(u8 Copy_u8BUS_ID,u8 Copy_u8Peripheral_ID);
void RCC_voidSetSystemClock(void);


#endif
