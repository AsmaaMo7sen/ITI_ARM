/*
 * BIT_MATH.h
 *
 *  Created on: May 4, 2023
 *      Author: mohnd
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define LIB_BIT_MATH_H_
#define SET_BIT(reg,bit_n) reg|=(1<<bit_n)
#define CLR_BIT(reg,bit_n) reg&=~(1<<bit_n)
#define TGL_BIT(reg,bit_n) reg^=(1<<bit_n)
#define GET_BIT(reg,bit_n) ((reg>>bit_n)&1)
#define WR_BIT(reg,bit_n,bit_value) (reg=(reg &=~(1<<bit_n))|(bit_value<<bit_n))
#endif /* BIT_MATH_H_ */
