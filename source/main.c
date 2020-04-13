/*	Author: kennethalvarez
 *  Partner(s) Name: 
 *	Lab Section:26
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: WRITE A PROGRAM THAT ILLUMINATES AN LED IF THE GARAGE IS OPEN AT NIGHT
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
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
	
    /* Insert your solution below */
    while (1) {
	if(PINA == 0x01) {
		PORTB = 0x01;	
	}
	else {
		PORTB = 0x00;
	}

    }
    return 1;
}
