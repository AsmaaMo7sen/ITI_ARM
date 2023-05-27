/***************************************/
/* Author: Mena Ghobrial               */
/* Date: 26 SEP 2022                   */
/* Version: V01                        */
/***************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable SysTick                       */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u8Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void MSTK_voidStopInterval(void);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);


#endif /* STK_INTERFACE_H */