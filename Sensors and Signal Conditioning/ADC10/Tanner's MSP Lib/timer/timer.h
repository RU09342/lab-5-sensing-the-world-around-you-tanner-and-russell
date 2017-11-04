/*
 * timer.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef TIMER_H_
#define TIMER_H_

/** Timer structure to house all important timer related registers and values */
struct Timer {
    volatile unsigned int * control_reg;
    volatile unsigned int * counter_reg;
    volatile unsigned int * ccr0_reg;
    volatile unsigned int * ccr0_control_reg;
    volatile unsigned int * ccr1_reg;
    volatile unsigned int * ccr1_control_reg;
    volatile unsigned int * ccr2_reg;
    volatile unsigned int * ccr2_control_reg;
    volatile unsigned int * interrupt_vector;

    int clk;
    int divider;
    int mode;
};

struct Timer timerA;
struct Timer timerB;

#define TACLK           0x01
#define ACLK            0x02
#define SMCLK           0x03
#define INCLK           0x04

#define DIV1            0x01
#define DIV2            0x02
#define DIV4            0x03
#define DIV8            0x04

#define STOP            0x01
#define UP              0x02
#define CONTINUOUS      0x03
#define UP_DOWN         0x04

void TimerA_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val);
void TimerA_Stop();
void TimerA_SetCompareVal0(unsigned int compare_val);
void TimerA_SetCompareVal1(unsigned int compare_val);
void TimerA_SetCompareVal2(unsigned int compare_val);
void TimerA_EnableInterrupt0();
void TimerA_EnableInterrupt1();
void TimerA_EnableInterrupt2();
int  TimerA_GetInterruptVector();
void TimerA_ResetTime();
int  TimerA_TimeNow();
int  TimerA_TimeSince(unsigned int time);

void TimerB_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val);
void TimerB_Stop();
void TimerB_SetCompareVal0(unsigned int compare_val);
void TimerB_SetCompareVal1(unsigned int compare_val);
void TimerB_SetCompareVal2(unsigned int compare_val);
void TimerB_EnableInterrupt0();
void TimerB_EnableInterrupt1();
void TimerB_EnableInterrupt2();
int  TimerB_GetInterruptVector();
void TimerB_ResetTime();
int  TimerB_TimeNow();
int  TimerB_TimeSince(unsigned int time);

int Convert_ValToHz(unsigned int value, unsigned int clock_speed);
int Convert_HzToVal(unsigned int hz, unsigned int clock_speed);

#endif /* TIMER_H_ */
