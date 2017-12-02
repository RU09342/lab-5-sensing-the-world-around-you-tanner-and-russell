# Lab 5 - Russell Binaco and Tanner Smith

Lab 5 Consists of using the microprocessors to read in data from a sensor circuit using an ADC, then visualizing that data through different means.

NOTE: All code for this lab (ADC10, ADC12 and LCD Screen) is in Sensors and Signal Conditioning folder.

## Sensors and Signal Conditioning: The Hardware
For this lab, three different sensors were used: a photoresistor, a temperature sensor, and a phototransistor. These sensors produce a resistance, voltage, and current, respectively, satisfying
the requirements for the lab. 
In the images and videos folder, there is a picture that shows each circuit. 

![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/All%20three%20circuits.jpg)

### Photoresistor
The circuit for the photoresistor is simply a voltage divider, using the photoresistor and one other resistor. This second resistor should be approximately the same resistance value of the
mid-range value of the photoresistor in order for the ADC to have the greatest range. The photoresistor is on the high side of the circuit, and the value at the middle node decreases with
decreasing light, so the photoresistor increases in resistance as its exposure to light decreases. 

LCD            |  UART
:-------------------------:|:-------------------------:
![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/LCD%20gifs/Photoresistor%20GIF.gif)  |  ![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/UART%20gifs/Photoresistor%20GIF.gif)

### Temperature Sensor
The temperature sensor device contains all necessary circuitry internally, so no circuit is required; only Vcc, ground, and a pin that varies voltage with temperature. For the specific temperature sensor used, for every increase in degree Celsius, the voltage varying pin increased by 10 mV. For this lab, ADC 
values are simply displayed, but Lab 6 precisely calculates the actual temperature. 

LCD            |  UART
:-------------------------:|:-------------------------:
![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/LCD%20gifs/Temperature%20Sensor%20GIF.gif)  |  ![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/UART%20gifs/Temperature%20Sensor%20GIF.gif)

### Phototransistor
A phototransistor is a light-controlled transistor, in which a base current is induced by light. A high-side switch configuration is used to enable the measurement as voltage. 
The base pin is left open, but could be biased. The open pin is a good way of isolating two parts of a circuit, i.e. powering an LED from a microprocessor to control a phototransistor.
The dishwasher circuit used this setup. Increasing light increases the base current, so the high-side switch configuration allows a higher voltage for greater exposure to light. 

LCD            |  UART
:-------------------------:|:-------------------------:
![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/LCD%20gifs/Phototransistor%20GIF.gif) |  ![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/UART%20gifs/Phototransistor%20GIF.gif)

## Visualizing Data: The Software
All of the circuits described above function with the same software. The MSP430G2553 ADC10 was used for UART communication and MATLAB, and the MSP430FR6989 ADC12 was used to display
results on its LCD screen. Ultimately, each circuit has a point at which its voltage is read in and used by the microprocessor.

### The ADC
For both the ADC10 and ADC12, configuration settings include sample rate, source clock, and the pin(s) to be read from. P1.7 on the G2 and P8.7 on the FR were used. Since sampling rates are
all very fast, a timer was used to have a sampling rate on the order of 1Hz so the LCD output and UART output could be easily observed. A timer in UPMODE triggers an interrupt that turns on 
the ADC. When the ADC finishes computing a single conversion, its interrupt triggers. This interrupt turns off the ADC, therefore stopping it from continuing to sample at a fast rate, and
it transmits the ADC1XMEM value accordingly. The sections below discuss how this part is done.

### UART
For UART, the UCA0TXBUF simply needs to be assigned the ADC10 value. Since the value is 10 bits, and UART works in bytes, the ADC10 value must be stored in two temp variables. One holds the
full 10 bits, and one holds that value shifted right 8 bits to send only the upper two. The lower 8 bits are sent when a 10-bit value is given to the buffer. These two values are transmitted
with a while loop between them to wait for the first value to finish sending before attempting to send the second one.

![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/ADC10%20UART%20GIF.gif)

### MATLAB
For MATLAB, a script was found online that takes UART input and plots it. In our code, a '\r' character had to be sent for this script to accept a data point. The images and videos folder
holds the resulting graphs. For our data, this graph may not be meaningful, but the functionality of sending data to MATLAB is demonstrated. 

![alt text](https://github.com/RU09342/lab-5-sensing-the-world-around-you-tanner-and-russell/blob/master/Lab5%20images%20and%20videos/matlab%20plot.PNG)

### LCD
For the LCD display, characters can be shown. These characters are hex values, which are four bits. This means that for the ADC12, three characters must be used. The provided LCD library easily
displays characters. However, the integer input must be modified to be transmitted as characters. First, shifting and masking are used to have three temp values holding four bits each. Then, if
these values are less than 'A', they are 0-9, so the corresponding character value is temp plus '0'. Otherwise, the corresponding character value is temp minus 10 plus 'A'. 