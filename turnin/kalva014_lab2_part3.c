/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: Write a program that outputs in binary on port C the number of available spaces
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0X00; PORTA = 0x00; //Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; //Configure port B's 8 pins as outputs, // Initialize PORTB output to 0's
    unsigned char cntavail = 0; //Temporary variable to hold the value of B

    while(1) {
        if((PINA & 0x0F) == 0x0F) {
		PORTC = (PINC & 0x00) | 0x80;
        }
        else if(((PINA & 0x0F) == 0x01) || ((PINA & 0x0F) == 0x02) || ((PINA & 0x0F) == 0x04) || ((PINA & 0x0F) == 0x08)) {
                cntavail = 3;
		PORTC = cntavail;
        }
        else if(((PINA & 0x0F) == 0x0E) || ((PINA & 0x0F) == 0x0B) || ((PINA & 0x0F) == 0x0D)|| ((PINA & 0x0F) == 0x07)) {
                cntavail = 1;
		PORTC = cntavail;
        }
        else if((PINA & 0x0F) == 0x00) {
                cntavail = 4;
		PORTC = cntavail;
        }
        else {
                cntavail = 2;
		PORTC = cntavail;
        }
    }

   return 0;
}
