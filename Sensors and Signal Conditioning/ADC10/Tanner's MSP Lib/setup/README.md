# Tanner's Setup Library for MSP430
This library is used as a hardware abstraction layer between the five specific processors: MSP430G2553, MSP430F5529, MSP430FR6989, MSP430FR2311, and MSP430FR5994. It allows easy access and use of all setup functions needed for each specific processor and dev board.

## Dependencies
This library depends on having the processor specific header files in a compiler include path and editing the target properties to the correct processor.

## Usage
After including the header and c files in the same working directory as your project, you can include the setup.h file in any module and use setup specific functions.

## Functions

### void Setup_Init()
Initializes each processor to remove any suppression on ports
#### Initialize Setup()
```c
void Setup_Init();
```

## Tasks
- [x] Implement setup function over five specific processors
- [ ] Add more functionality available to the user

## Author
Written by Tanner Smith