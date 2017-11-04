/*
 * hal_timer.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_

/** Assigns register pointers to variables depending on target specified processor */
#if defined(__MSP430G2553__)
    #include <msp430g2553.h>

    volatile unsigned int  *  controlA_reg =         &TA0CTL;
    volatile unsigned int  *  counterA_reg =         &TA0R;
    volatile unsigned int  *  ccr0A_reg =            &TA0CCR0;
    volatile unsigned int  *  ccr0A_control_reg =    &TA0CCTL0;
    volatile unsigned int  *  ccr1A_reg =            &TA0CCR1;
    volatile unsigned int  *  ccr1A_control_reg =    &TA0CCTL1;
    volatile unsigned int  *  ccr2A_reg =            &TA0CCR2;
    volatile unsigned int  *  ccr2A_control_reg =    &TA0CCTL2;
    volatile unsigned int  *  interrupt_vector_A =   &TA0IV;

    volatile unsigned int  *  controlB_reg =         &TA1CTL;
    volatile unsigned int  *  counterB_reg =         &TA1R;
    volatile unsigned int  *  ccr0B_reg =            &TA1CCR0;
    volatile unsigned int  *  ccr0B_control_reg =    &TA1CCTL0;
    volatile unsigned int  *  ccr1B_reg =            &TA1CCR1;
    volatile unsigned int  *  ccr1B_control_reg =    &TA1CCTL1;
    volatile unsigned int  *  ccr2B_reg =            &TA1CCR2;
    volatile unsigned int  *  ccr2B_control_reg =    &TA1CCTL2;
    volatile unsigned int  *  interrupt_vector_B =   &TA1IV;

    unsigned int interrupt_enable =                 CCIE;
    unsigned int timer_clear =                      TACLR;

    unsigned int taclk =                            TASSEL_0;
    unsigned int aclk  =                            TASSEL_1;
    unsigned int smclk =                            TASSEL_2;
    unsigned int inclk =                            TASSEL_3;

    unsigned int off =                              MC_0;
    unsigned int up =                               MC_1;
    unsigned int continuous =                       MC_2;
    unsigned int up_down =                          MC_3;

    unsigned int divider_1 =                        ID_0;
    unsigned int divider_2 =                        ID_1;
    unsigned int divider_4 =                        ID_2;
    unsigned int divider_8 =                        ID_3;

#elif defined(__MSP430FR5994__)
    #include <msp430fr5994.h>

    volatile unsigned int  *  controlA_reg =         &TA0CTL;
    volatile unsigned int  *  counterA_reg =         &TA0R;
    volatile unsigned int  *  ccr0A_reg =            &TA0CCR0;
    volatile unsigned int  *  ccr0A_control_reg =    &TA0CCTL0;
    volatile unsigned int  *  ccr1A_reg =            &TA0CCR1;
    volatile unsigned int  *  ccr1A_control_reg =    &TA0CCTL1;
    volatile unsigned int  *  interrupt_vector_A =   &TA0IV;

    volatile unsigned int  *  controlB_reg =         &TA1CTL;
    volatile unsigned int  *  counterB_reg =         &TA1R;
    volatile unsigned int  *  ccr0B_reg =            &TA1CCR0;
    volatile unsigned int  *  ccr0B_control_reg =    &TA1CCTL0;
    volatile unsigned int  *  ccr1B_reg =            &TA1CCR1;
    volatile unsigned int  *  ccr1B_control_reg =    &TA1CCTL1;
    volatile unsigned int  *  interrupt_vector_B =   &TA1IV;

    unsigned int interrupt_enable =                 CCIE;
    unsigned int timer_clear =                      TACLR;

    unsigned int taclk =                            TASSEL_0;
    unsigned int aclk  =                            TASSEL_1;
    unsigned int smclk =                            TASSEL_2;
    unsigned int inclk =                            TASSEL_3;

    unsigned int off =                              MC_0;
    unsigned int up =                               MC_1;
    unsigned int continuous =                       MC_2;
    unsigned int up_down =                          MC_3;

    unsigned int divider_1 =                        ID_0;
    unsigned int divider_2 =                        ID_1;
    unsigned int divider_4 =                        ID_2;
    unsigned int divider_8 =                        ID_3;

#elif defined(__MSP430FR2311__)
    #include <msp430fr2311.h>

    volatile unsigned int  *  controlA_reg =         &TB0CTL;
    volatile unsigned int  *  counterA_reg =         &TB0R;
    volatile unsigned int  *  ccr0A_reg =            &TB0CCR0;
    volatile unsigned int  *  ccr0A_control_reg =    &TB0CCTL0;
    volatile unsigned int  *  ccr1A_reg =            &TB0CCR1;
    volatile unsigned int  *  ccr1A_control_reg =    &TB0CCTL1;
    volatile unsigned int  *  interrupt_vector_A =   &TB0IV;

    volatile unsigned int  *  controlB_reg =         &TB1CTL;
    volatile unsigned int  *  counterB_reg =         &TB1R;
    volatile unsigned int  *  ccr0B_reg =            &TB1CCR0;
    volatile unsigned int  *  ccr0B_control_reg =    &TB1CCTL0;
    volatile unsigned int  *  ccr1B_reg =            &TB1CCR1;
    volatile unsigned int  *  ccr1B_control_reg =    &TB1CCTL1;
    volatile unsigned int  *  interrupt_vector_B =   &TB1IV;

    unsigned int interrupt_enable =                 CCIE;
    unsigned int timer_clear =                      TBCLR;

    unsigned int taclk =                            TBSSEL_0;
    unsigned int aclk  =                            TBSSEL_1;
    unsigned int smclk =                            TBSSEL_2;
    unsigned int inclk =                            TBSSEL_3;

    unsigned int off =                              MC_0;
    unsigned int up =                               MC_1;
    unsigned int continuous =                       MC_2;
    unsigned int up_down =                          MC_3;

    unsigned int divider_1 =                        ID_0;
    unsigned int divider_2 =                        ID_1;
    unsigned int divider_4 =                        ID_2;
    unsigned int divider_8 =                        ID_3;

#elif defined(__MSP430F5529__)
    #include <msp430f5529.h>

    volatile unsigned int  *  controlA_reg =         &TA0CTL;
    volatile unsigned int  *  counterA_reg =         &TA0R;
    volatile unsigned int  *  ccr0A_reg =            &TA0CCR0;
    volatile unsigned int  *  ccr0A_control_reg =    &TA0CCTL0;
    volatile unsigned int  *  ccr1A_reg =            &TA0CCR1;
    volatile unsigned int  *  ccr1A_control_reg =    &TA0CCTL1;
    volatile unsigned int  *  interrupt_vector_A =   &TA0IV;

    volatile unsigned int  *  controlB_reg =         &TA1CTL;
    volatile unsigned int  *  counterB_reg =         &TA1R;
    volatile unsigned int  *  ccr0B_reg =            &TA1CCR0;
    volatile unsigned int  *  ccr0B_control_reg =    &TA1CCTL0;
    volatile unsigned int  *  ccr1B_reg =            &TA1CCR1;
    volatile unsigned int  *  ccr1B_control_reg =    &TA1CCTL1;
    volatile unsigned int  *  interrupt_vector_B =   &TA1IV;

    unsigned int interrupt_enable =                 CCIE;
    unsigned int timer_clear =                      TACLR;

    unsigned int taclk =                            TASSEL_0;
    unsigned int aclk  =                            TASSEL_1;
    unsigned int smclk =                            TASSEL_2;
    unsigned int inclk =                            TASSEL_3;

    unsigned int off =                              MC_0;
    unsigned int up =                               MC_1;
    unsigned int continuous =                       MC_2;
    unsigned int up_down =                          MC_3;

    unsigned int divider_1 =                        ID_0;
    unsigned int divider_2 =                        ID_1;
    unsigned int divider_4 =                        ID_2;
    unsigned int divider_8 =                        ID_3;

#elif defined(__MSP430FR6989__)
    #include <msp430fr6989.h>

    volatile unsigned int  *  controlA_reg =         &TA0CTL;
    volatile unsigned int  *  counterA_reg =         &TA0R;
    volatile unsigned int  *  ccr0A_reg =            &TA0CCR0;
    volatile unsigned int  *  ccr0A_control_reg =    &TA0CCTL0;
    volatile unsigned int  *  ccr1A_reg =            &TA0CCR1;
    volatile unsigned int  *  ccr1A_control_reg =    &TA0CCTL1;
    volatile unsigned int  *  interrupt_vector_A =   &TA0IV;

    volatile unsigned int  *  controlB_reg =         &TA1CTL;
    volatile unsigned int  *  counterB_reg =         &TA1R;
    volatile unsigned int  *  ccr0B_reg =            &TA1CCR0;
    volatile unsigned int  *  ccr0B_control_reg =    &TA1CCTL0;
    volatile unsigned int  *  ccr1B_reg =            &TA1CCR1;
    volatile unsigned int  *  ccr1B_control_reg =    &TA1CCTL1;
    volatile unsigned int  *  interrupt_vector_B =   &TA1IV;

    unsigned int interrupt_enable =                 CCIE;
    unsigned int timer_clear =                      TACLR;

    unsigned int taclk =                            TASSEL_0;
    unsigned int aclk  =                            TASSEL_1;
    unsigned int smclk =                            TASSEL_2;
    unsigned int inclk =                            TASSEL_3;

    unsigned int off =                              MC_0;
    unsigned int up =                               MC_1;
    unsigned int continuous =                       MC_2;
    unsigned int up_down =                          MC_3;

    unsigned int divider_1 =                        ID_0;
    unsigned int divider_2 =                        ID_1;
    unsigned int divider_4 =                        ID_2;
    unsigned int divider_8 =                        ID_3;

#endif

#endif /* HAL_TIMER_H_ */
