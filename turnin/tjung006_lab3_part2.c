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

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
    return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
}
unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpC = 0x00;
	if(tmpA > 0x00){
		tmpC = SetBit(tmpC,5,1);
	}
	if(tmpA > 0x02){
                tmpC = SetBit(tmpC,4,1);
        }
	if(tmpA > 0x04){
                tmpC = SetBit(tmpC,3,1);
        }
	if(tmpA > 0x06){
                tmpC = SetBit(tmpC,2,1);
        }
	if(tmpA > 0x09){
                tmpC = SetBit(tmpC,1,1);
        }
	if(tmpA > 0x0C){
                tmpC = SetBit(tmpC,0,1);
        }
	if(tmpA < 0x05){
                tmpC = SetBit(tmpC,6,1);
        }
	PORTC = tmpC;
    }
    return 0;
}
