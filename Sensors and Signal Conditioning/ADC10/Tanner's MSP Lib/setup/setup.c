/*
 * hal_init.c
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#include "hal_setup.h"
#include "setup.h"

/** Initializes each processor to remove any suppression on ports */
void Setup_Init(){
    *setup_reg &= setup_val;
}


