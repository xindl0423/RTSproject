#ifndef _7SEGMENT_H
#define _7SEGMENT_H

#include <avr/io.h>

#define ARRAY_SIZE 16
#define Button PC0  // Analog A0
#define switch0 PB0 // Digital 8
#define switch1 PB1 // Digital 9

extern uint8_t digits[ARRAY_SIZE];

void displaydigits(void);
void segment_init(void);

#endif