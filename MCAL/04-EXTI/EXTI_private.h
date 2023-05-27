/*****************************************/
/* Author:    Mena Ghobrial              */
/* Date:      23 SEP 2022                */
/* Version:   V01                        */
/*****************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS 0x40013C00


typedef struct
{
	volatile u32 IMR  ;
	volatile u32 EMR  ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER;
	volatile u32 PR   ;
}EXTI_t;


#define EXTI    ((EXTI_t *) EXTI_BASE_ADDRESS)


/* Edge options */

/* SYSCFG Register */
#define SYSCFG_BASE_ADDRESS   0x40013800
#define SYSCFG_EXTI          ((volatile u32*) SYSCFG_BASE_ADDRESS + 0x08)


#endif /* EXTI_PRIVATE_H */