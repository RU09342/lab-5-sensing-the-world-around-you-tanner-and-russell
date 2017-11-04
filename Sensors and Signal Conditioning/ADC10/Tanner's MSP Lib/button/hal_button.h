/*
 * hal_button.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

/** Assigns register pointers to variables depending on target specified processor */
#if defined(__MSP430G2553__)
    #include <msp430g2553.h>

    volatile unsigned char *  btn1_port_dir =    &P1DIR;
    volatile unsigned char *  btn1_port_in =     &P1IN;
    volatile unsigned char *  btn1_port_out =    &P1OUT;
    volatile unsigned char *  btn1_ren_reg =     &P1REN;
    volatile unsigned char *  btn1_ie_reg =      &P1IE;
    volatile unsigned char *  btn1_ies_reg =     &P1IES;
    volatile unsigned char *  btn1_ifg_reg =     &P1IFG;
    int btn1_location =                          BIT3;

#elif defined(__MSP430FR5994__)
    #include <msp430fr5994.h>

    volatile unsigned char *  btn1_port_dir =    &P5DIR;
    volatile unsigned char *  btn1_port_in =     &P5IN;
    volatile unsigned char *  btn1_port_out =    &P5OUT;
    volatile unsigned char *  btn1_ren_reg =     &P5REN;
    volatile unsigned char *  btn1_ie_reg =      &P5IE;
    volatile unsigned char *  btn1_ies_reg =     &P5IES;
    volatile unsigned char *  btn1_ifg_reg =     &P5IFG;
    int btn1_location =                          BIT6;


#elif defined(__MSP430FR2311__)
    #include <msp430fr2311.h>

    volatile unsigned char *  btn1_port_dir =   &P1DIR;
    volatile unsigned char *  btn1_port_in =    &P1IN;
    volatile unsigned char *  btn1_port_out =   &P1OUT;
    volatile unsigned char *  btn1_ren_reg =    &P1REN;
    volatile unsigned char *  btn1_ie_reg =     &P1IE;
    volatile unsigned char *  btn1_ies_reg =    &P1IES;
    volatile unsigned char *  btn1_ifg_reg =    &P1IFG;
    int btn1_location =                         BIT1;

#elif defined(__MSP430F5529__)
    #include <msp430f5529.h>

    volatile unsigned char *  btn1_port_dir =   &P2DIR;
    volatile unsigned char *  btn1_port_in =    &P2IN;
    volatile unsigned char *  btn1_port_out =   &P2OUT;
    volatile unsigned char *  btn1_ren_reg =    &P2REN;
    volatile unsigned char *  btn1_ie_reg =     &P2IE;
    volatile unsigned char *  btn1_ies_reg =    &P2IES;
    volatile unsigned char *  btn1_ifg_reg =    &P2IFG;
    int btn1_location =                         BIT1;

#elif defined(__MSP430FR6989__)
    #include <msp430fr6989.h>

    volatile unsigned char *  btn1_port_dir =    &P1DIR;
    volatile unsigned char *  btn1_port_in =     &P1IN;
    volatile unsigned char *  btn1_port_out =    &P1OUT;
    volatile unsigned char *  btn1_ren_reg =     &P1REN;
    volatile unsigned char *  btn1_ie_reg =      &P1IE;
    volatile unsigned char *  btn1_ies_reg =     &P1IES;
    volatile unsigned char *  btn1_ifg_reg =     &P1IFG;
    int btn1_location =                          BIT1;

#endif

#endif /* HAL_BUTTON_H_ */
