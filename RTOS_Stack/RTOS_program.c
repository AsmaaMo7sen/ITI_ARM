/*
 * RTOS_program.c
 *
 *  Created on: May 29, 2023
 *      Author: shady
 */





#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "../MCAL/STK/STK_interface.h"



Task_t Task[TASK_NUM];

/*************************Functions' implementation***********************/


void RTOS_voidInit(void)
{
    STK_voidInit();
      
    STK_voidDelayAsyncPeriodic(1000,Task->TaskPtrToFunc);

}

void RTOS_voidCreatTask( u32 Copy_u32TaskPeriodicity , void(*Copy_PtrToFunc)(void))
{
    static u8 TaskIterator = 0 ; 
    if(TaskIterator < TASK_NUM)
    {
        Task[TaskIterator].Periodicty = Copy_u32TaskPeriodicity ;
        Task[TaskIterator].TaskPtrToFunc = Copy_PtrToFunc ;

        TaskIterator++ ;
        }
        

}

void scheduler (void)
{
    u8 TaskIterator = 0 ;

    static u32 SystemTick = 0 ;

    SystemTick++ ;

    if(SystemTick > Task[0].Periodicty)
    {
        SystemTick = 0 ;
        Task[0].TaskPtrToFunc() ;
    }
        for(TaskIterator = 0 ; TaskIterator < TASK_NUM ; TaskIterator++)

        {
            if(SystemTick % Task[TaskIterator].Periodicty == 0 )
            {
                Task[TaskIterator].TaskPtrToFunc() ;
                SystemTick = 0 ;
            }
        }
            
    
}

void RTOS_voidRunOS(void)
{
    while(1)
    {
        scheduler() ;
    }
}
        
    
