#include "driverlib.h"
#include "LCDDriver.h"

/**
*ADC12 code to read data over an ADC channel and display it via the LCD screen
*@author Tanner Smith and Russell Binaco
*Russell wrote a working version without the use of libraries
*Tanner wrote this version that uses libraries
*
**/
void main(void)
{
    /** Stop WDT **/
    WDT_A_hold(WDT_A_BASE);


    /** Set P1.1 as Ternary Module Function Output. **/
    GPIO_setAsPeripheralModuleFunctionOutputPin(
    	GPIO_PORT_P8,
    	GPIO_PIN7,
    	GPIO_TERNARY_MODULE_FUNCTION
    );

    /*
     * Disable the GPIO power-on default high-impedance mode to activate
     * previously configured port settings
     */
    PMM_unlockLPM5();

    /** Initialize the ADC12B Module **/
    /*
    * Base address of ADC12B Module
    * Use internal ADC12B bit as sample/hold signal to start conversion
    * USE MODOSC 5MHZ Digital Oscillator as clock source
    * Use default clock divider/pre-divider of 1
    * Not use internal channel
    */
   	ADC12_B_initParam initParam = {0};
    initParam.sampleHoldSignalSourceSelect = ADC12_B_SAMPLEHOLDSOURCE_SC;   //generic sample and hold source select
    initParam.clockSourceSelect = ADC12_B_CLOCKSOURCE_ADC12OSC;             //generic ADC12 Clock
    initParam.clockSourceDivider = ADC12_B_CLOCKDIVIDER_1;
    initParam.clockSourcePredivider = ADC12_B_CLOCKPREDIVIDER__1;
    initParam.internalChannelMap = ADC12_B_NOINTCH;
	ADC12_B_init(ADC12_B_BASE, &initParam);

    /** Enable the ADC12B module **/
    ADC12_B_enable(ADC12_B_BASE);

    /*
    * Base address of ADC12B Module
    * For memory buffers 0-7 sample/hold for 64 clock cycles
    * For memory buffers 8-15 sample/hold for 4 clock cycles (default)
    * Disable Multiple Sampling
    */
    ADC12_B_setupSamplingTimer(ADC12_B_BASE,
      ADC12_B_CYCLEHOLD_16_CYCLES,
      ADC12_B_CYCLEHOLD_4_CYCLES,
      ADC12_B_MULTIPLESAMPLESDISABLE);

    /** Configure Memory Buffer **/
    /*
    * Base address of the ADC12B Module
    * Configure memory buffer 0
    * Map input A4 to memory buffer 0
    * Vref+ = AVcc
    * Vref- = AVss
    * Memory buffer 0 is not the end of a sequence
    */
    ADC12_B_configureMemoryParam configureMemoryParam = {0};
    configureMemoryParam.memoryBufferControlIndex = ADC12_B_MEMORY_0;
    configureMemoryParam.inputSourceSelect = ADC12_B_INPUT_A4;
    configureMemoryParam.refVoltageSourceSelect = ADC12_B_VREFPOS_AVCC_VREFNEG_VSS;
    configureMemoryParam.endOfSequence = ADC12_B_NOTENDOFSEQUENCE;
    configureMemoryParam.windowComparatorSelect = ADC12_B_WINDOW_COMPARATOR_DISABLE;
    configureMemoryParam.differentialModeSelect = ADC12_B_DIFFERENTIAL_MODE_DISABLE;
    ADC12_B_configureMemory(ADC12_B_BASE, &configureMemoryParam);

    /** Clear memory buffer 0 interrupt **/
    ADC12_B_clearInterrupt(ADC12_B_BASE,
    	0,
    	ADC12_B_IFG0
    	);

    /** Enable memory buffer 0 interrupt **/
    ADC12_B_enableInterrupt(ADC12_B_BASE,
      ADC12_B_IE0,
      0,
      0);

    /** Enable interrupts **/
    __enable_interrupt();

    LCD_C_setPinAsLCDFunctionEx(LCD_C_BASE, LCD_C_SEGMENT_LINE_0, LCD_C_SEGMENT_LINE_21);
    LCD_C_setPinAsLCDFunctionEx(LCD_C_BASE, LCD_C_SEGMENT_LINE_26, LCD_C_SEGMENT_LINE_43);

    LCD_C_initParam initParams = {0};
    initParams.clockSource = LCD_C_CLOCKSOURCE_ACLK;
    initParams.clockDivider = LCD_C_CLOCKDIVIDER_1;
    initParams.clockPrescalar = LCD_C_CLOCKPRESCALAR_16;
    initParams.muxRate = LCD_C_4_MUX;
    initParams.waveforms = LCD_C_LOW_POWER_WAVEFORMS;
    initParams.segments = LCD_C_SEGMENTS_ENABLED;

    LCD_C_init(LCD_C_BASE, &initParams);

    // LCD Operation - VLCD generated internally, V2-V4 generated internally, v5 to ground
    LCD_C_setVLCDSource(LCD_C_BASE, LCD_C_VLCD_GENERATED_INTERNALLY, LCD_C_V2V3V4_GENERATED_INTERNALLY_NOT_SWITCHED_TO_PINS,
         LCD_C_V5_VSS);

    // Set VLCD voltage to 2.60v
    LCD_C_setVLCDVoltage(LCD_C_BASE, LCD_C_CHARGEPUMP_VOLTAGE_2_60V_OR_2_17VREF);

    // Enable charge pump and select internal reference for it
    LCD_C_enableChargePump(LCD_C_BASE);
    LCD_C_selectChargePumpReference(LCD_C_BASE, LCD_C_INTERNAL_REFERENCE_VOLTAGE);

    LCD_C_configChargePump(LCD_C_BASE, LCD_C_SYNCHRONIZATION_ENABLED, 0);

    // Clear LCD memory
    LCD_C_clearMemory(LCD_C_BASE);

    // Turn LCD on
    LCD_C_on(LCD_C_BASE);


    while (1)
    {
        __delay_cycles(5000);

        //Enable/Start sampling and conversion
        /*
         * Base address of ADC12B Module
         * Start the conversion into memory buffer 0
         * Use the single-channel, single-conversion mode
         */
        ADC12_B_startConversion(ADC12_B_BASE,
            ADC12_B_MEMORY_0,
            ADC12_B_SINGLECHANNEL);

        __bis_SR_register(LPM0_bits + GIE);     // LPM0, ADC12_B_ISR will force exit
        __no_operation();                       // For debugger
    }
}



/**
* ADC12 interrupt service routine
* each time the ADC computes a value, it will be 
* displayed on 3 spaces of the LCD screen, representing
* the upper, middle, and last four bits of the 12-bit value
* in Hexadecimal values. Each set of four bits must be masked
* and shifted to display the correct value using the provided
* LCD library. Converting to char values is different between numbers
* and letters, which is handed in if-else blocks.
**/
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(ADC12_VECTOR)))
#endif
void ADC12_ISR(void)
{
  switch(__even_in_range(ADC12IV,12))
  {
    case  0: break;                         // Vector  0:  No interrupt
    case  2: break;                         // Vector  2:  ADC12BMEMx Overflow
    case  4: break;                         // Vector  4:  Conversion time overflow
    case  6: break;                         // Vector  6:  ADC12BHI
    case  8: break;                         // Vector  8:  ADC12BLO
    case 10: break;                         // Vector 10:  ADC12BIN
    case 12:{                                // Vector 12:  ADC12BMEM0 Interrupt

      uint16_t value = ADC12_B_getResults(ADC12_B_BASE, ADC12_B_MEMORY_0);
	  //here, temp values are created from masking all but four bits of the ADC value.
      uint16_t hex1 = value & 0x0F00;
      uint16_t hex2 = value & 0x00F0;
      uint16_t hex3 = value & 0x000F;
	  //now, shifting is done for the bits to all be LSBs.
      hex1 = hex1 >> 8;
      hex2 = hex2 >> 4;
      hex3 = hex3 >> 0;

	  //for each value, add '0' or 'A'-10 to get the correct hex char value corresponding to the int value.
      if(hex1 < 10){
          showChar('0' + hex1, 1);
      }
      else{
          showChar('A' + hex1 - 10, 1);
      }

      if(hex2 < 10){
          showChar('0' + hex2, 2);
      }
      else{
          showChar('A' + hex2 - 10, 2);
      }

        if(hex3 < 10){
          showChar('0' + hex3, 3);
      }
      else{
          showChar('A' + hex3 - 10, 3);
      }


    	  __bic_SR_register_on_exit(LPM0_bits); // Exit active CPU
    }
      break;                                // Clear CPUOFF bit from 0(SR)
    case 14: break;                         // Vector 14:  ADC12BMEM1
    case 16: break;                         // Vector 16:  ADC12BMEM2
    case 18: break;                         // Vector 18:  ADC12BMEM3
    case 20: break;                         // Vector 20:  ADC12BMEM4
    case 22: break;                         // Vector 22:  ADC12BMEM5
    case 24: break;                         // Vector 24:  ADC12BMEM6
    case 26: break;                         // Vector 26:  ADC12BMEM7
    case 28: break;                         // Vector 28:  ADC12BMEM8
    case 30: break;                         // Vector 30:  ADC12BMEM9
    case 32: break;                         // Vector 32:  ADC12BMEM10
    case 34: break;                         // Vector 34:  ADC12BMEM11
    case 36: break;                         // Vector 36:  ADC12BMEM12
    case 38: break;                         // Vector 38:  ADC12BMEM13
    case 40: break;                         // Vector 40:  ADC12BMEM14
    case 42: break;                         // Vector 42:  ADC12BMEM15
    case 44: break;                         // Vector 44:  ADC12BMEM16
    case 46: break;                         // Vector 46:  ADC12BMEM17
    case 48: break;                         // Vector 48:  ADC12BMEM18
    case 50: break;                         // Vector 50:  ADC12BMEM19
    case 52: break;                         // Vector 52:  ADC12BMEM20
    case 54: break;                         // Vector 54:  ADC12BMEM21
    case 56: break;                         // Vector 56:  ADC12BMEM22
    case 58: break;                         // Vector 58:  ADC12BMEM23
    case 60: break;                         // Vector 60:  ADC12BMEM24
    case 62: break;                         // Vector 62:  ADC12BMEM25
    case 64: break;                         // Vector 64:  ADC12BMEM26
    case 66: break;                         // Vector 66:  ADC12BMEM27
    case 68: break;                         // Vector 68:  ADC12BMEM28
    case 70: break;                         // Vector 70:  ADC12BMEM29
    case 72: break;                         // Vector 72:  ADC12BMEM30
    case 74: break;                         // Vector 74:  ADC12BMEM31
    case 76: break;                         // Vector 76:  ADC12BRDY
    default: break;
  }
}
