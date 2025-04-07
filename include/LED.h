#pragma once
#include <Arduino.h>

#define LED3 PB3
#define LED2 PB4
#define LED1 PB5

void LED_init(){
    DDRB |= (1<<LED3) | (1<<LED2) | (1<<LED1) ;
    PORTB &= ~((1<<LED3) | (1<<LED2) | (1<<LED1));
}