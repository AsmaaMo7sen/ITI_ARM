/***************************************/
/* Author: Mena Ghobrial               */
/* Date: 26 SEP 2022                   */
/* Version: V01                        */
/***************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#define STK_BASE_ADDRESS    0xE000E010 


typedef struct{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
	volatile u32 CALIB;
}STK_t;


#define STK     ((STK_t *) STK_BASE_ADDRESS)


#define STK_SRC_AHB       0
#define STK_SRC_AHB_8     1

#define SINGLE_INTERVAL     0
#define PERIODIC_INTERVAL   1



#endif /* STK_PRIVATE_H */