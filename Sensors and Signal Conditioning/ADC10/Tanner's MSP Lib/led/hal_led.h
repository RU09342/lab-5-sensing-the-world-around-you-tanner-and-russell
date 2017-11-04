/*
 * hal_led.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_

/** Assigns register pointers to variables depending on target specified processor */
#if defined(__MSP430G2553__)
    #include <msp430g2553.h>

    volatile unsigned char * led1_port_dir =     &P1DIR;
    volatile unsigned char * led1_port =         &P1OUT;
    int led1_location =                          BIT0;

    volatile unsigned char * led2_port_dir =     &P1DIR;
    volatile unsigned char * led2_port =         &P1OUT;
    int led2_location =                          BIT6;

#elif defined(__MSP430FR5994__)
    #include <msp430fr5994.h>

    volatile unsigned char * led1_port_dir =     &P1DIR;
    volatile unsigned char * led1_port =         &P1OUT;
    int led1_location =                          BIT0;

    volatile unsigned char * led2_port_dir =     &P1DIR;
    volatile unsigned char * led2_port =         &P1OUT;
    int led2_location =                          BIT1;

#elif defined(__MSP430FR2311__)
    #include <msp430fr2311.h>

    volatile unsigned char * led1_port_dir =    &P1DIR;
    volatile unsigned char * led1_port =        &P1OUT;
    int led1_location =                         BIT0;

    volatile unsigned char * led2_port_dir =    &P2DIR;
    volatile unsigned char * led2_port =        &P2OUT;
    int led2_location =                         BIT0;

#elif defined(__MSP430F5529__)
    #include <msp430f5529.h>

    volatile unsigned char * led1_port_dir =    &P1DIR;
    volatile unsigned char * led1_port =        &P1OUT;
    int led1_location =                         BIT0;

    volatile unsigned char * led2_port_dir =    &P4DIR;
    volatile unsigned char * led2_port =        &P4OUT;
    int led2_location =                         BIT7;

#elif defined(__MSP430FR6989__)
    #include <msp430fr6989.h>

    volatile unsigned char * led1_port_dir =     &P1DIR;
    volatile unsigned char * led1_port =         &P1OUT;
    int led1_location =                          BIT0;

    volatile unsigned char * led2_port_dir =     &P9DIR;
    volatile unsigned char * led2_port =         &P9OUT;
    int led2_location =                          BIT7;

#endif

#endif /* HAL_LED_H_ */
