e#pragma once
#include <Arduino.h>

#define ARRAY_SIZE 16
#define Button PC0

void displaydigits();

byte digits[ARRAY_SIZE] = {0xEE, 0x82, 0xDC, 0xD6, 0xB2, 0x76, 0x7E, 0xC2, 0xFE, 0xF6, 0xFA, 0xFE, 0x6C, 0xEE, 0x7C, 0x78};
  
DDRD = 00001111;
DDRC = 01111000;   
DDRC &= ~(1<<Button);
PORTC != (1<<Button);

DDRB &= ~((1<<switch0) | (1<<switch1));
PORTB != ((1<<switch0) | (1<<switch1));