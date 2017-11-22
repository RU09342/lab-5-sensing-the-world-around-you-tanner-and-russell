#include <msp430g2553.h>
//Fields for temporary ints when outputting over UART
int temp=0;
int temp2=0;

/**
*ADC10 code to read data over an ADC channel and transmit it using two bytes over UART, done repeatedly
*@author Russell Binaco and Tanner Smith
*credit to TI sample libraries for configuration code and sample code
*
*supports MATLAB code that will capture and plot data by sending one extra character each conversion.
**/
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  ADC10CTL1 = INCH_7 + SHS_1;               // P1.7, TA1 trigger sample start
  ADC10AE0 = 0x80;                          // P1.7 ADC10 option select
  TACCTL0 = CCIE;                           // Enable interrupt
  TACCR0 = 65535;       					//PWM Period for SMCLK
  TACCTL1 = OUTMOD_3;                       // TACCR1 set/reset
  TACCR1 = 4096;       	 					//TACCR1 PWM Duty Cycle for SMCLK
  TACTL = TASSEL_2 + MC_1 + ID_3;   		//SMCLK div 8, up mode

  //UART Config
  if (CALBC1_1MHZ==0xFF)                  // If calibration constant erased
    {
      while(1);                               // do not load, trap CPU!!
    }
    DCOCTL = 0;                               // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;                    // Set DCO
    DCOCTL = CALDCO_1MHZ;
    P1SEL |= BIT1 + BIT2;                     // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= BIT1 + BIT2;                    // P1.1 = RXD, P1.2=TXD
    UCA0CTL1 |= UCSSEL_2;                     // SMCLK
    UCA0BR0 = 104;                            // 1MHz 9600
    UCA0BR1 = 0;                              // 1MHz 9600
    UCA0MCTL = UCBRS0;                        // Modulation UCBRSx = 1
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    IE2 |= UCA0RXIE;                          // Enable USCI_A0 RX interrupt

    __bis_SR_register(LPM0_bits + GIE);       // enable interrupts and LPM0

}

/** ADC10 interrupt service routine
* When the ADC finished computing a value, the ADC is disabled and the value
* is transmitted over UART at 9600 baud. This is done in two bytes, the first
* containing the upper 2 bits and the second containing the lower 8 bits.
**/
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)

{
  temp = ADC10MEM;  //for lower 8 bits
  temp2 = temp>>8;  //upper bits
  UCA0TXBUF = temp2;
  while(!(IFG2&UCA0TXIFG));     //buffer ready? wait for upper bits to send
  UCA0TXBUF = temp;                     //send to TX
  while(!(IFG2&UCA0TXIFG));     //buffer ready? wait for lower bits to send
  UCA0TXBUF = '\r';                     //send to TX for MATLAB confirmation

  ADC10CTL0 &= ~ENC;                        // ADC10 disabled
  ADC10CTL0 = 0;                            // ADC10, Vref disabled completely
}

/** Timer A0 interrupt service routine
* Timer A0 controls the rate at which the ADC will compute multiple values. 
* This is done by enabling the ADC. Recall it is turned off in the ADC interrupt
* and this ISR tells the ADC to compute another value.
*
**/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)

{
  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + ADC10IE;      //turn ADC10 back on
  ADC10CTL0 |= ENC;                         // ADC10 enable set

}
