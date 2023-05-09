/*************************************************************/
/*************************************************************/
/************     Author    : Mostafa Mahmoud     ************/
/************     file name : BIT_MATH.h          ************/
/************     Date      : 5/5/2023            ************/
/*************************************************************/
/*************************************************************/

/*Header file guard*/
#ifndef RCC_BIT_MATH_H_
#define RCC_BIT_MATH_H_

/*This function is used to set a certain bit in the register*/
#define  SET_BIT(REG,BIT_NO)       REG |= (1<<BIT_NO)

/*This function is used to Clear a certain bit in the register*/
#define  CLR_BIT(REG,BIT_NO)       REG &= ~(1<<BIT_NO)

/*This function is used to Toggle a certain bit in the register*/
#define  TOGGLE_BIT(REG,BIT_NO)    REG ^= (1<<BIT_NO)

/*This function is used to Get the value a certain bit in the register*/
#define  GET_BIT(REG,BIT_NO)       (REG>>BIT_NO) & 1


#endif
