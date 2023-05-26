/*
 * STK_private.h
 *
 *  Created on: May 26, 2023
 *      Author: Hardware
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_


typedef struct
{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
}STK_t;

#define STK ((STK_t*)(0xE000E010))


#define SINGLE    0
#define PERIODIC  1

#endif /* MCAL_STK_STK_PRIVATE_H_ */
