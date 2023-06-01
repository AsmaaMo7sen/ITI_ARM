/*
 * SinPout_config.h
 *
 *  Created on: May 30, 2023
 *      Author: shady
 */

#ifndef HAL_SERINPAROUT_SINPOUT_CONFIG_H_
#define HAL_SERINPAROUT_SINPOUT_CONFIG_H_
#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define SinPout1        1
#define SinPout2        2


#define SER1_Pin         GPIOA,GPIO_PIN_0

#define SRCLK1_Pin       GPIOA,GPIO_PIN_1

#define RCLK1_Pin        GPIOA,GPIO_PIN_2

#define OE1_Pin          GPIOA,GPIO_PIN_3

#define SER2_Pin         GPIOA,GPIO_PIN_4

#define SRCLK2_Pin       GPIOA,GPIO_PIN_5

#define RCLK2_Pin        GPIOA,GPIO_PIN_6

#define OE2_Pin          GPIOA,GPIO_PIN_7



#endif /* HAL_SERINPAROUT_SINPOUT_CONFIG_H_ */
