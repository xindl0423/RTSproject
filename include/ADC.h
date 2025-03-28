#pragma once
#include <Arduino.h>

#define LED_up PB1
#define LED_down PB3
#define LED_centre PB0
#define LED_right PB2
#define LED_left PB4

void ADC_init(){
    DDRC &=~((1<<PC0) | (1<<PC1));
    PORTC &= ~((1 << PC0) | (1 << PC1)); 
    ADCSRA |= (1<<ADEN) | (1<<ADATE) | (1<<ADPS2) | (1<<ADPS1) |(1<<ADPS0);
    ADMUX = 0x40;
    DIDR0 = 0x03;
}

void LED_init(){
    DDRB |= (1<<LED_up) | (1<<LED_down) | (1<<LED_centre) | (1<<LED_right) | (1<<LED_left);
    PORTB &= ~((1<<LED_up) | (1<<LED_down) | (1<<LED_centre) | (1<<LED_right) | (1<<LED_left));
}
    