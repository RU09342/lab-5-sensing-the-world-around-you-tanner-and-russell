# Tanner's Timer Library for MSP430
This library is used as a hardware abstraction layer between the five specific processors: MSP430G2553, MSP430F5529, MSP430FR6989, MSP430FR2311, and MSP430FR5994. It allows easy access and use of Timers for each specific processor.

## Dependencies
This library depends on having the processor specific header files in a compiler include path and editing the target properties to the correct processor.

## Usage
After including the header and c files in the same working directory as your project, you can include the timer.h file in any module and use Timer specific functions.

## Timer A Functions

### void TimerA_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val)
Initializes the Timer A structure and all registers to use it. This function MUST be called before any other functions are called. MUST use predefined clock source, mode and clock select from timer.h.
#### TimerA Init
```c
TimerA_Init(SMCLK, UP, DIV8, 1000);
```


### void TimerA_Stop()
Stops and resets Timer A. TimerA_Init must be called to restart the timer.
#### TimerA Stop
```c
TimerA_Stop();
```


### void TimerA_SetCompareVal0(unsigned int compare_val)
Sets the CCR0 register for Timer A.
#### TimerA Set Compare Val 0
```c
TimerA_SetCompareVal0(350);
```

### void TimerA_SetCompareVal1(unsigned int compare_val)
Sets the CCR1 register for Timer A.
#### TimerA Set Compare Val 1
```c
TimerA_SetCompareVal1(4300);
```

### void TimerA_EnableInterrupt0()
Enables the interrupt for Timer A CCR0.
#### TimerA Enable Interrupt CCR0
```c
TimerA_EnableInterrupt0();
```

### void TimerA_EnableInterrupt1()
Enables the interrupt for Timer A CCR1.
#### TimerA Enable Interrupt CCR1
```c
TimerA_EnableInterrupt1();
```

### void TimerA_GetInterrupt Vector()
Returns the Timer A interrupt vector.
#### Get Interrupt Vector
```c
int interrupt_vector_TA0IV = TimerA_GetInterruptVector();
```

### void TimerA_ResetTime()
Resets the time for Timer A counter.
#### void TimerA Reset Time
```c
TimerA_ResetTime();
```

### int TimerA_TimeNow()
Returns the current value in the TimerA counter register.
#### TimerA Time Now
```c
current_time = TimerA_TimeNow();
```

### int TimerA_TimeSince(unsigned int time)
Returns the time since the passed in time. Time inbetween events CAN NOT be more than 65535 or return value will be wrong.
#### TimerA Time Since
```c
time_between = TimerA_TimeSince(last_event);
```




## Timer B Functions

### void TimerB_Init(int clock_sel, int clock_mode, int clock_div, unsigned int compare_val)
Initializes the Timer B structure and all registers to use it. This function MUST be called before any other functions are called. MUST use predefined clock source, mode and clock select from timer.h.
#### TimerB Init
```c
TimerB_Init(SMCLK, UP, DIV8, 1000);
```

### void TimerB_Stop()
Stops and resets Timer B. TimerB_Init must be called to restart the timer.
#### TimerB Stop
```c
TimerB_Stop();
```

### void TimerB_SetCompareVal0(unsigned int compare_val)
Sets the CCR0 register for Timer B.
#### TimerB Set Compare Val 0
```c
void TimerB_SetCompareVal0(350);
```

### void TimerB_SetCompareVal1(unsigned int compare_val)
Sets the CCR1 register for Timer B.
#### TimerB Set Compare Val 1
```c
void TimerB_SetCompareVal1(4300);
```

### void TimerB_EnableInterrupt0()
Enables the interrupt for Timer B CCR0.
#### TimerB Enable Interrupt CCR0
```c
TimerB_EnableInterrupt0()
```

### void TimerB_EnableInterrupt1()
Enables the interrupt for Timer B CCR1.
#### TimerB Enable Interrupt CCR1
```c
TimerB_EnableInterrupt1()
```

### void TimerB_GetInterrupt Vector()
Returns the Timer B interrupt vector.
#### Get Interrupt Vector
```c
int interrupt_vector_TB0IV = TimerB_GetInterruptVector();
```

### void TimerB_ResetTime()
Resets the time for Timer B counter.
#### void TimerB Reset Time
```c
TimerB_ResetTime()
```

### int TimerB_TimeNow()
Returns the current value in the TimerB counter register.
#### TimerB Time Now
```c
current_time = TimerB_TimeNow();
```

### int TimerB_TimeSince(unsigned int time)
Returns the time since the passed in time. Time inbetween events CAN NOT be more than 65535 or return value will be wrong.
#### TimerB Time Since
```c
time_between = TimerB_TimeSince(last_event);
```

## Other Functions

### int Convert_ValToHz(unsigned int value, unsigned int clock_speed)
Converts a timer value to frequency based on clock speed
#### Convert Value to Frequency
```c
int frequency = Convert_ValToHz(10000, 1000000);
```

### int Convert_HzToVal(unsigned int hz, unsigned int clock_speed)
Converts a frequency to timer value based on clock speed
#### Convert Frequency to Value
```c
int value = Convert_HzToVal(1000, 1000000);
```

## Tasks
- [x] Implement Timer A over five specific processors
- [x] Implement Timer B over five specific processors
- [ ] Add more functions for each timer

## Author
Written by Tanner Smith