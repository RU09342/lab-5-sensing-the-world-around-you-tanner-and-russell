/*
 * led.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef LED_H_
#define LED_H_

/** LED structure to house all important LED related registers and values */
struct Led {
    volatile unsigned char * port_dir;
    volatile unsigned char * port;
    int location;
};

struct Led led1;
struct Led led2;

void Led1_Init();
void Led2_Init();
void Led1_Toggle();
void Led2_Toggle();
void Led1_On();
void Led2_On();
void Led1_Off();
void Led2_Off();



#endif /* LED_H_ */
