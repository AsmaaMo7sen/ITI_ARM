/*
 * SinPout_interface.h
 *
 *  Created on: May 30, 2023
 *      Author: shady
 */

#ifndef HAL_SERINPAROUT_SINPOUT_INTERFACE_H_
#define HAL_SERINPAROUT_SINPOUT_INTERFACE_H_

#include "SinPout_config.h"
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

void SIN_shift_out(u8 data,u8 num);


void SIN_latch_data(u8 num);

void SIN_enable_output(u8 num); 

void SIN_disable_output(u8 num);




#endif /* HAL_SERINPAROUT_SINPOUT_INTERFACE_H_ */
