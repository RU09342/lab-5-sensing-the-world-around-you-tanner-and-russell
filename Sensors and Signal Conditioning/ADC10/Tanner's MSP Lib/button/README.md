# Tanner's Button Library for MSP430
This library is used as a hardware abstraction layer between the five specific processors: MSP430G2553, MSP430F5529, MSP430FR6989, MSP430FR2311, and MSP430FR5994. It allows easy access and use of buttons attached to each specific processor and dev board.

## Dependencies
This library depends on having the processor specific header files in a compiler include path and editing the target properties to the correct processor.

## Usage
After including the header and c files in the same working directory as your project, you can include the button.h file in any module and use button specific functions.

## Functions

### void Button1_Init(int pull_up)
Initializes the button 1 structure and all registers to use it. This function MUST be called before any other functions are called.
#### Button Init
```c
Button1_Init(1);
```

### int Button1_Read()
Used to determine if button 1 is pressed or unpressed. Returns 0 if not pressed and 1 if pressed.
#### Button Read
```c
int button_pressed = Button1_Read();
```

### void Button1_EnableInterrupt(int positive_edge_trigger)
Enables the button 1 interrupt to fire on a specific edge
#### Enable Interrupt
```c
Button1_EnableInterrupt(1); //positive edge trigger
```

### void Button1_DisableInterrupt()
Disables the interrupt on button 1.
#### Disable Interrupt
```c
Button1_DisableInterrupt();
```

### void Button1_ClearFlag()
Clears the button 1 flag after interrupt is fired. This flag MUST be cleared for the interrupt to fire again.
#### Clear Flag
```c
Button1_ClearFlag()
```

## Tasks
- [x] Implement button 1 over five specific processors
- [ ] Add button 2 support for processors who have two buttons
- [ ] Add more functions

## Author
Written by Tanner Smith