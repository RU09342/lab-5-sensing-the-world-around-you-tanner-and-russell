/*
 * hal_timer.c
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#include "hal_timer.h"
#include "timer.h"

int Timer_SetClock(int clock);
int Timer_SetDivider(int divider);
int Timer_SetMode(int mode);

/** Inializes the Timer A structure and all registers to use it.
 *  This function must be called before any other function in this C file
 *
 *  @param int clock_sel                Processor specific clock that will be used to count
 *  @param int clock_mode               Mode the timer will operate in (Stop, Up, Continuous, Up/Down)
 *  @param int clock_div                Divisor of processor specific clock chosen to run the timer
 *  @param unsigned int compare_val     Initial value of CCR0
 */
void TimerA_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val){

    timerA.control_reg = controlA_reg;
    timerA.counter_reg = counterA_reg;
    timerA.ccr0_reg = ccr0A_reg;
    timerA.ccr0_control_reg = ccr0A_control_reg;
    timerA.ccr1_reg = ccr1A_reg;
    timerA.ccr1_control_reg = ccr1A_control_reg;
    timerA.ccr2_reg = ccr2A_reg;
    timerA.ccr2_control_reg = ccr2A_control_reg;
    timerA.interrupt_vector = interrupt_vector_A;
    timerA.clk = Timer_SetClock(clock_sel);
    timerA.divider = Timer_SetDivider(clock_div);
    timerA.mode = Timer_SetMode(clock_mode);

    *timerA.ccr0_reg = compare_val;
    *timerA.control_reg = timerA.clk + timerA.divider + timerA.mode;                  // SMCLK, contmode

}

/** Stops and resets Timer A. TimerA_Init must be called to restart the timer. */
void TimerA_Stop(){
    *timerA.control_reg = timer_clear;
}

/** Sets the CCR0 register for Timer A.*/
void TimerA_SetCompareVal0(unsigned int compare_val){
    *timerA.ccr0_reg = compare_val;
}

/** Sets the CCR1 register for Timer A.*/
void TimerA_SetCompareVal1(unsigned int compare_val){
    *timerA.ccr1_reg = compare_val;
}

/** Sets the CCR2 register for Timer A.*/
void TimerA_SetCompareVal2(unsigned int compare_val){
    *timerA.ccr2_reg = compare_val;
}

/** Enables Timer A interrupt for CCR0 */
void TimerA_EnableInterrupt0(){
    *timerA.ccr0_control_reg = interrupt_enable;
}

/** Enables Timer A interrupt for CCR1 */
void TimerA_EnableInterrupt1(){
    *timerA.ccr1_control_reg = interrupt_enable;
}

/** Enables Timer A interrupt for CCR2 */
void TimerA_EnableInterrupt2(){
    *timerA.ccr2_control_reg = interrupt_enable;
}

/** Returns the Timer A interrupt vector */
int TimerA_GetInterruptVector(){
    return *timerA.interrupt_vector;
}

/** Resets the time on timer A */
void TimerA_ResetTime(){
    *timerA.counter_reg = 0;
}

/** Gets the current time.
 *
 *  @return current time
 */
int TimerA_TimeNow(){
    return *timerA.counter_reg;
}

/** Returns the time since the passed in time.
 *  Time inbetween events CAN NOT be more than 65535 or return value will be wrong.
 *
 *  @return Difference between the current time and time passed in
 */
int TimerA_TimeSince(unsigned int time){
    unsigned int time_prev = time;
    unsigned int time_now = *timerA.counter_reg;

    if(time_now > time_prev){
        return time_now - time_prev;
    }
    else{
        return time_now + 65535 - time_prev;
    }
}


/** Inializes the Timer B structure and all registers to use it.
 *  This function must be called before any other function in this C file
 *
 *  @param int clock_sel                Processor specific clock that will be used to count
 *  @param int clock_mode               Mode the timer will operate in (Stop, Up, Continuous, Up/Down)
 *  @param int clock_div                Divisor of processor specific clock chosen to run the timer
 *  @param unsigned int compare_val     Initial value of CCR0
 */
void TimerB_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val){

    timerB.control_reg = controlB_reg;
    timerB.counter_reg = counterB_reg;
    timerB.ccr0_reg = ccr0B_reg;
    timerB.ccr0_control_reg = ccr0B_control_reg;
    timerB.ccr1_reg = ccr1B_reg;
    timerB.ccr1_control_reg = ccr1B_control_reg;
    timerB.ccr2_reg = ccr2B_reg;
    timerB.ccr2_control_reg = ccr2B_control_reg;
    timerB.interrupt_vector = interrupt_vector_B;
    timerB.clk = Timer_SetClock(clock_sel);
    timerB.divider = Timer_SetDivider(clock_div);
    timerB.mode = Timer_SetMode(clock_mode);

    *timerB.ccr0_reg = compare_val;
    *timerB.control_reg = timerB.clk + timerB.divider + timerB.mode;                  // SMCLK, contmode

}

/** Stops and resets Timer B.*/
void TimerB_Stop(){
    *timerB.control_reg = timer_clear;
}

/** Sets the CCR1 register for Timer B.*/
void TimerB_SetCompareVal0(unsigned int compare_val){
    *timerB.ccr0_reg = compare_val;
}

/** Sets the CCR1 register for Timer B.*/
void TimerB_SetCompareVal1(unsigned int compare_val){
    *timerB.ccr1_reg = compare_val;
}

/** Sets the CCR2 register for Timer B.*/
void TimerB_SetCompareVal2(unsigned int compare_val){
    *timerB.ccr2_reg = compare_val;
}


/** Enables Timer B interrupt for CCR0 */
void TimerB_EnableInterrupt0(){
    *timerB.ccr0_control_reg = interrupt_enable;                             // CCR0 interrupt enabled
}

/** Enables Timer B interrupt for CCR1 */
void TimerB_EnableInterrupt1(){
    *timerB.ccr1_control_reg = interrupt_enable;                             // CCR0 interrupt enabled
}

/** Enables Timer B interrupt for CCR2 */
void TimerB_EnableInterrupt2(){
    *timerB.ccr2_control_reg = interrupt_enable;                             // CCR0 interrupt enabled
}

/** Returns the Timer B interrupt vector */
int TimerB_GetInterruptVector(){
    return *timerB.interrupt_vector;
}

/** Resets the time on timer B */
void TimerB_ResetTime(){
    *timerB.counter_reg = 0;
}

/** Gets the current time.
 *
 *  @return current time
 */
int TimerB_TimeNow(){
    return *timerB.counter_reg;
}

/** Returns the time since the passed in time.
 *  Time inbetween events CAN NOT be more than 65535 or return value will be wrong.
 *
 *  @return Difference between the current time and time passed in
 */
int TimerB_TimeSince(unsigned int time){
    unsigned int time_prev = time;
    unsigned int time_now = *timerB.counter_reg;

    if(time_now > time_prev){
        return time_now - time_prev;
    }
    else{
        return time_now + 65355 - time_prev;
    }
}




/** Converts a timer value to frequency based on clock speed
 *
 *  @param unsigned int timer value     timer value to convert
 *  @param unsigned int clock_speed     clock speed for returned timer value
 *  @return int                         frequency equivalent to timer value
 */
int Convert_ValToHz(unsigned int value, unsigned int clock_speed){
   return clock_speed/value;
}

/** Converts a frequency to timer value based on clock speed
 *
 *  @param unsigned int hz              frequency to convert
 *  @param unsigned int clock_speed     clock speed for returned timer value
 *  @return int                         timer value equivalent to input frequency
 */
int Convert_HzToVal(unsigned int hz, unsigned int clock_speed){
   return clock_speed/hz;
}

/** Returns the specific clock for a timer based on values defined in timer.h*/
int Timer_SetClock(int clock){
    switch (clock) {
        case 1:
            return  taclk;
          break;
        case 2:
            return  aclk;
          break;
        case 3:
            return  smclk;
          break;
        case 4:
            return  inclk;
          break;
        default:
            return  smclk;
          break;
      }
}

/** Returns the specific divider for a timer based on values defined in timer.h*/
int Timer_SetDivider(int divider){
    switch (divider) {
        case 1:
            return divider_1;
          break;
        case 2:
            return divider_2;
          break;
        case 3:
            return divider_4;
          break;
        case 4:
            return divider_8;
          break;
        default:
            return divider_1;
          break;
      }
}

/** Returns the specific mode for a timer based on values defined in timer.h*/
int Timer_SetMode(int mode){
    switch (mode) {
        case 1:
            return off;
          break;
        case 2:
            return up;
          break;
        case 3:
            return continuous;
          break;
        case 4:
            return up_down;
          break;
        default:
            return continuous;
          break;
      }
}
