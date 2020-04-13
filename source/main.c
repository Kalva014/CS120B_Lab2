/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description:  A cart has three seats, with 8-bit weight sensors connected to ports A, B, and C
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
    DDRA = 0x00; PORTA = 0x00; //Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0x00; 
    DDRC = 0x00; PORTC = 0x00; 
    DDRD = 0xFF; PORTD = 0x00; //Output
	
    while(1) {
	unsigned char totalWeight = 0; //weight of the seats a, b, and c
        unsigned char weightA = PINA;
        unsigned char weightB = PINB;
        unsigned char weightC = PINC;
        unsigned char weightD = 0;

	totalWeight = (weightA + weightB + weightC);

        if(totalWeight > 140) {
		weightD = weightD | 0x01;
	}

	if((weightA - weightC) > 80) {
		weightD = weightD | 0x02;
	}	
	
	//totalWeight = totalWeight << 2;
	PORTD = weightD | totalWeight;
    }

   return 0;
}
