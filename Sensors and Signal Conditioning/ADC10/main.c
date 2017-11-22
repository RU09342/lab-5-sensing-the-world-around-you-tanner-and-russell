#include <msp430g2553.h>

#define TXLED       BIT0
#define RXLED       BIT6
#define TXD         BIT2
#define RXD         BIT1

int temp = 0;

int main(void){

    WDTCTL = WDTPW + WDTHOLD;               // Stop Watch Dog Timer

    /****** ADC10 Setup ******/

    ADC10CTL1 = SHS_1;                      // Sets Sample Start on Timer A CCR1
    ADC10CTL1 = INCH_7;                     // Selects ADC channel A7
    ADC10AE0 = BIT7;                        // Selects P1.7 to be an ADC10 Input

    /****** Timer A Setup ******/
    TA0CCTL0 = CCIE;                        // Enable the interrupt for Timer0
    TA0CCR0 = 65535;                        // 1 Hz Frequency
    TA0CCTL1 = OUTMOD_3;                    // Set then Reset
    TA0CCR1 = 4096;                         // Sets the TACCR1 PWM Duty Cycle
    TA0CTL = TASSEL_2 + MC_1 + ID_3;        // Initialize Timer to ACLK, UP Mode and DIV8

    /****** UART Config ******/
    if (CALBC1_1MHZ==0xFF){                 // If calibration constant erased
        while(1);                           // do not load, trap CPU!!
    }

    /** Calibrate and Set internal oscillator to 1 MHz **/
    DCOCTL = 0;                             // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;                  // Set DCO
    DCOCTL = CALDCO_1MHZ;

    /** Switch P1.1 and P1.2 to Special Function Mode for UART **/
    P1SEL |= RXD + TXD;                     // P1.1 = RXD, P1.2=TXD
    P1SEL2 = RXD + TXD;                     // P1.1 = RXD, P1.2=TXD

    /** Configure 9600 baud rate **/
    UCA0CTL1 |= UCSSEL_2;                   // SMCLK
    UCA0BR0 = 109;                          // Divide 1 MHz by 104 to achieve 9600 (actually 9615)
    UCA0BR1 = 0;                            // 1MHz 9600
    UCA0MCTL = UCBRS2;                      // Modulation UCBRSx = 3
    UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**

    __bis_SR_register(GIE);       // enable interrupts
    while(1){

    }

}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){

  temp = ADC10MEM;
  UC0IE |= UCA0TXIE;

  ADC10CTL0 &= ~ENC;                        // ADC10 disabled
  ADC10CTL0 = 0;                            // ADC10, Vref disabled completely

}

// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void){

    ADC10CTL0 = SREF_1 +REFON + ADC10SHT_2 + ADC10ON + ADC10IE;
    ADC10CTL0 |= ENC;                      // ADC10 enable set

}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void)
{
   P1OUT |= TXLED;
   UCA0TXBUF = temp;                         //send to TX
   UC0IE &= ~UCA0TXIE;                   // Disable USCI_A0 TX interrupt
   P1OUT &= ~TXLED;
   ADC10CTL0 |= ENC;
}
