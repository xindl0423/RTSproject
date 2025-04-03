#pragma once
#include <Arduino.h>

#define LED_down PB1
#define LED3 PB2
#define LED2 PB3
#define LED1 PB4


void ADC_init(){
    DDRC &=~((1<<PC0) | (1<<PC1));
    PORTC &= ~((1 << PC0) | (1 << PC1)); 
    ADCSRA |= (1<<ADEN) | (1<<ADATE) | (1<<ADPS2) | (1<<ADPS1) |(1<<ADPS0);
    ADMUX = 0x40;
    DIDR0 = 0x03;
}

void LED_init(){
    DDRB |= (1<<LED3) | (1<<LED2) | (1<<LED1) | (1<<LED_down);
    PORTB &= ~((1<<LED3) | (1<<LED2) | (1<<LED1) | (1<<LED_down));
}

void updateLED(uint16_t x_value, uint16_t y_value);
int ADC_Read(byte channel);
