# PCB Design

![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/PCB%20Design/PCB%20Board.gif)

The function of this board is to be a breadboard breakout for the MSP430FR2311. The header pins were carefully placed with the breadboard function in mind. Therefore, the pins were properly spaced to fit in different rows of the breaddboard and the headers were properly placed to bridge the gap of the breadboard. A ground plane was included to reduce the noise of the traces. The reset circuitry was also added to the breakout so the MSP430FR2311 could be programmed off board. A bill of materials for this board can be seen below.

## Bill of Materials

* U2: MSP430FR2311
* C1: 10 uF Capacitor, surface mount (CAP_0805) 
* C2: 100 nF Capacitor, surface mount (CAP_0805)
* C3: 100 nF Capacitor, surface mount (CAP_0805)
* R1: 47k Ohm resistor, surface mount (RES_0805)
* J3: 8 through hole pin header
* J4: 8 through hole pin header