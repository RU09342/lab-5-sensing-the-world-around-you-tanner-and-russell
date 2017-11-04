/*
 * hal_led.c
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#include "hal_led.h"
#include "led.h"

/** Inializes the led1 structure and all registers to use it.
 *  This function must be called before any other function in this C file
 */
void Led1_Init(){
    led1.port_dir = led1_port_dir;
    led1.port = led1_port;
    led1.location = led1_location;

    *led1.port_dir |= led1.location;
}

/** Inializes the led2 structure and all registers to use it.
 *  This function must be called before any other function in this C file
 */
void Led2_Init(){
    led2.port_dir = led2_port_dir;
    led2.port = led2_port;
    led2.location = led2_location;

    *led2.port_dir |= led2.location;
}

/** Toggle led1 */
void Led1_Toggle(){
    *led1.port ^= led1.location;
}

/** Toggle led2 */
void Led2_Toggle(){
    *led2.port ^= led2.location;
}

/** Turn on led1 */
void Led1_On(){
    *led1.port |= led1.location;
}

/** Turn on led2 */
void Led2_On(){
    *led2.port |= led2.location;
}

/** Turn off led1 */
void Led1_Off(){
    *led1.port &= ~led1.location;
}

/** Turn off led2 */
void Led2_Off(){
    *led2.port &= ~led2.location;
}

