/*
 * button.c
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#include "hal_button.h"
#include "button.h"

/** Initializes the button 1 structure and all registers to use it.
 *  MUST be called before any other functions are called.
 *
 *  @param int pull_up  1 for pull-up resistor or 0 for pull-down resistor
 */
void Button1_Init(int pull_up){
    btn1.port_dir = btn1_port_dir;
    btn1.port_in = btn1_port_in;
    btn1.port_out = btn1_port_out;
    btn1.ren_reg = btn1_ren_reg;
    btn1.ie_reg = btn1_ie_reg;
    btn1.ies_reg = btn1_ies_reg;
    btn1.ifg_reg = btn1_ifg_reg;
    btn1.location = btn1_location;

    *btn1.port_dir &= ~btn1.location;
    *btn1.ren_reg |= btn1.location;
    if(pull_up){
        *btn1.port_out |= btn1.location;
    }
    else{
        *btn1.port_out &= ~btn1.location;
    }
    Button1_ClearFlag();
}

/** Used to determine if button 1 is pressed or unpressed.
 *
 *  @return 1 for pressed button1 and 0 for unpressed button1
 */
int Button1_Read(){
    return (*btn1.port_in & btn1.location) ^ btn1.location;
}

/** Enable the button 1 interrupt.
 *
 *  @param int positive_edge_trigger    1 for pos edge trigger, 0 for neg edge trigger
 */
void Button1_EnableInterrupt(int positive_edge_trigger){
    *btn1.ie_reg |= btn1.location;
    if(positive_edge_trigger){
        *btn1.ies_reg |= btn1.location;
    }
    else{
        *btn1.ies_reg &= ~btn1.location;
    }
    *btn1.ifg_reg &= ~(btn1.location);

    Button1_ClearFlag();
}

/** Disable the button 1 interrupt */
void Button1_DisableInterrupt(){
    *btn1.ie_reg &= ~btn1.location;
}

/** Clear the button 1 interrupt flag */
void Button1_ClearFlag(){
    *btn1.ifg_reg &= ~(btn1.location);
}


