/*
 * hal_setup.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef HAL_SETUP_H_
#define HAL_SETUP_H_

/** Assigns register pointers to variables depending on target specified processor */
#if defined(__MSP430G2553__)
    #include <msp430g2553.h>

    volatile unsigned int * setup_reg =          0;
    int setup_val =                              0;

#elif defined(__MSP430FR5994__)
    #include <msp430fr5994.h>

    volatile unsigned int * setup_reg =          &PM5CTL0;
    int setup_val =                              ~LOCKLPM5;

#elif defined(__MSP430FR2311__)
    #include <msp430fr2311.h>

    volatile unsigned int * setup_reg =         &PM5CTL0;
    int setup_val =                             ~LOCKLPM5;

#elif defined(__MSP430F5529__)
    #include <msp430f5529.h>

    volatile unsigned int * setup_reg =         0;
    int setup_val =                             0;


#elif defined(__MSP430FR6989__)
    #include <msp430fr6989.h>

    volatile unsigned int * setup_reg =         &PM5CTL0;
    int setup_val =                             ~LOCKLPM5;

#endif

#endif /* HAL_SETUP_H_ */
