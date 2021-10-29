/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	
 *	Demo Link: https://youtu.be/oOzsKBhXREc
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0x0000;

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    //DDRD = 0xFF; PORTD = 0x00;
    unsigned short max = 0x03F3;
    /* Insert your solution below */
    ADC_init();
    //max 1100000011
    while (1) {
        x = ADC;
        if (x >= max/2){
            PORTB = 0x00;
        }
        else{
            PORTB = 0x01;
        }
    }
    return 1;
}
