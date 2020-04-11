/*	Author: terry
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char add(unsigned char a, unsigned char b){
    while(b != 0){
        unsigned char x = a & b;
        a = a ^ b;
        b = x << 1;
    }
    return a;
}

unsigned char GetBit(unsigned char y, unsigned char k) {
   return ((y & (0x01 << k)) != 0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char one = 0x01;     
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = 0x00;
	unsigned char j = 0x00;
	for(int i = 0; i < 8; i++){
	    if(GetBit(tmpA,j) == 0x01){
		tmpC = add(tmpC,one);
	    }	
	    if(GetBit(tmpB,j) == 0x01){
		tmpC = add(tmpC,one);
	    }
	    j = add(j,one);
	}
	PORTC = tmpC;
    }
    return 0;
}
