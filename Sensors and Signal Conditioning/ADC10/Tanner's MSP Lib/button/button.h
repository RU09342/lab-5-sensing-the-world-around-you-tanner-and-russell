/*
 * button.h
 *
 *  Created on: Sep 26, 2017
 *      Author: Tanner
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/** Button structure to house all important button related registers and values */
struct Button {
    volatile unsigned char * port_dir;
    volatile unsigned char * port_in;
    volatile unsigned char * port_out;
    volatile unsigned char * ren_reg;
    volatile unsigned char * ie_reg;
    volatile unsigned char * ies_reg;
    volatile unsigned char * ifg_reg;
    int location;
};

struct Button btn1;

void Button1_Init(int pull_up);
int  Button1_Read();
void Button1_EnableInterrupt(int positive_edge_trigger);
void Button1_DisableInterrupt();
void Button1_ClearFlag();

#endif /* BUTTON_H_ */
