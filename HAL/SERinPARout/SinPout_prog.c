/*
 * SinPout_prog.c
 *
 *  Created on: May 30, 2023
 *      Author: shady
 */
#include "../../MCAL/GPIO/GPIO_interface.h"
#include"SinPout_interface.h"

void SIN_shift_out(u8 data,u8 num) {

    switch (num)
    {
    case SinPout1:

        for (u8 i = 0; i < 8; i++) {

        GPIO_voidSetOutPinValue(SER1_Pin, (data >> i) & 1);
        GPIO_voidSetOutPinValue(SRCLK1_Pin,GPIO_OUTPUT_HIGH);
        GPIO_voidSetOutPinValue(SRCLK1_Pin, GPIO_OUTPUT_LOW);
    }  
    break;
    
    case SinPout2:

        for (u8 i = 0; i < 8; i++) {

        GPIO_voidSetOutPinValue(SER2_Pin, (data >> i) & 1);
        GPIO_voidSetOutPinValue(SRCLK2_Pin,GPIO_OUTPUT_HIGH);
        GPIO_voidSetOutPinValue(SRCLK2_Pin, GPIO_OUTPUT_LOW);
    }  
    break;
    
    default:
        break;
    }

    
}

void SIN_latch_data(u8 num) {
    switch (num)
    {
    case SinPout1:
        /* code */
    GPIO_voidSetOutPinValue(RCLK1_Pin, GPIO_OUTPUT_HIGH);
    GPIO_voidSetOutPinValue(RCLK1_Pin, GPIO_OUTPUT_LOW);
        break;
    
    case SinPout2:
        /* code */
    GPIO_voidSetOutPinValue(RCLK2_Pin, GPIO_OUTPUT_HIGH);
    GPIO_voidSetOutPinValue(RCLK2_Pin, GPIO_OUTPUT_LOW);
        break;
    
    default:
        break;
    }
}

void SIN_enable_output(u8 num) {

    switch (num)
    {
    case SinPout1:
        /* code */
        GPIO_voidSetOutPinValue(OE1_Pin, GPIO_OUTPUT_HIGH);
        break;
    
    case SinPout2:
        /* code */
        GPIO_voidSetOutPinValue(OE2_Pin, GPIO_OUTPUT_HIGH);
        break;
    
    default:
        break;
    }

}

void SIN_disable_output(u8 num) {

    switch (num)
    {
    case SinPout1:
        /* code */
        GPIO_voidSetOutPinValue(OE1_Pin, GPIO_OUTPUT_LOW);
        break;
    
    case SinPout2:
        /* code */
        GPIO_voidSetOutPinValue(OE2_Pin, GPIO_OUTPUT_LOW);
        break;
    
    default:
        break;
    }
}

