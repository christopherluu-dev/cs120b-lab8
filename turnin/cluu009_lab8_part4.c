/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *	
 *	Demo Link: https://youtu.be/JoLlpNfHJZo 
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0x0000;
unsigned short max = 0x3F3;

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    //DDRD = 0xFF; PORTD = 0x00;
    ADC_init(); 
    unsigned short eighth = max/8;
    /* Insert your solution below */
    while (1) {
        x = ~ADC;
        unsigned char sens = (char)x;
        if (sens <= eighth){
            PORTB = 0x01;
        }
        else if (sens <= eighth * 2){
            PORTB = 0x03;
        }
        else if (sens <= eighth * 3){
            PORTB = 0x07;
        }
        else if (sens <= eighth * 4){
            PORTB = 0x0F;
        }
        else if (sens <= eighth * 5){
            PORTB = 0x1F;
        }
        else if (sens <= eighth * 6){
            PORTB = 0x3F;
        }
        else if (sens <= eighth * 7){
            PORTB = 0x7F;
        }
        else if (sens <= eighth * 8){
            PORTB = 0xFF;
        }
    }
    return 1;
}
