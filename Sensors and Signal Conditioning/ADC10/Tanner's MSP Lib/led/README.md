# Tanner's LED Library for MSP430
This library is used as a hardware abstraction layer between the five specific processors: MSP430G2553, MSP430F5529, MSP430FR6989, MSP430FR2311, and MSP430FR5994. It allows easy access and use of LEDs attached to each specific processor and dev board.

## Dependencies
This library depends on having the processor specific header files in a compiler include path and editing the target properties to the correct processor.

## Usage
After including the header and c files in the same working directory as your project, you can include the led.h file in any module and use LED specific functions.

## Functions

### void Led1_Init()
Initializes the LED 1 structure and all registers to use it. This function MUST be called before any other functions are called.
#### LED1 Init
```c
Led1_Init();
```

### void Led2_Init()
Initializes the LED 2 structure and all registers to use it. This function MUST be called before any other functions are called.
#### LED2 Init
```c
Led2_Init();
```

### void Led1_Toggle()
Toggle the state of LED 1.
#### Led1 Toggle
```c
Led1_Toggle();
```

### void Led2_Toggle()
Toggle the state of LED 2.
#### Led2 Toggle
```c
Led2_Toggle();
```

### void Led1_On()
Turn on LED 1.
#### Led1 On
```c
Led1_On();
```

### void Led2_On()
Turn on LED 2.
#### Led2 On
```c
Led2_On();
```

### void Led1_Off()
Turn off LED 1
#### Led1 Off
```c
Led1_Off();
```

### void Led2_Off()
Turn off LED 2
#### Led2 Off
```c
Led2_Off();
```

## Tasks
- [x] Implement led 1 over five specific processors
- [x] Implement led 1 over five specific processors
- [ ] Add more functions

## Author
Written by Tanner Smith