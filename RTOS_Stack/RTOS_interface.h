/*
 * RTOS_interface.h
 *
 *  Created on: May 29, 2023
 *      Author: shady
 */

#ifndef RTOS_STACK_RTOS_INTERFACE_H_
#define RTOS_STACK_RTOS_INTERFACE_H_

#include "../LIB/STD_TYPES.h"

typedef struct 
{
    void (*TaskPtrToFunc)(void); // pointer to task C func
    u32 Periodicty ;             // How often the task is repeated
}Task_t;

/*************************Functions' ProtoTypes***********************/

void RTOS_voidInit(void);

void RTOS_voidCreatTask( u32 Copy_u32TaskPeriodicity , void(*Copy_PtrToFunc)(void));

void scheduler (void);

void RTOS_voidRunOS(void);




#endif /* RTOS_STACK_RTOS_INTERFACE_H_ */
