/*
 * NVIC_private.h
 *
 *  Created on: May 22, 2023
 *      Author: Hardware
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_


typedef struct
{
	u32 ISER[8] ;
	u32 Reserved1[24];
	u32 ICER[8] ;
	u32 Reserved2[24];
	u32 ISPR[32] ;
	u32 ICPR[32] ;
	u32 IABR[64] ;
 	u8 IPR[240];    //instead of 8 registers , each has 4bytes
}NVIC_t;

#define NVIC       ((volatile NVIC_t *)(0xE000E100))

/*register to configure
  how to divide software priority between group and sub
  for the system*/
#define SCB_AIRCR  (*(volatile  u32*)(0xE000ED0C))


#define GROUP4_SUB0         (0)   //support 16 group(nesting level up to 16)
#define GROUP3_SUB1         (4)   //support 8 groups and 2 subpriorities
#define GROUP2_SUB2         (5)   //support 4 groups and 4 subpriorities
#define GROUP1_SUB3         (6)   //support 2 groups and 8 subpriorities
#define GROUP0_SUB4         (7)   //support 0 groups and 16 subpriorities(no nesting)

#define VECT_KEY           (0x05FA0000) //

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
