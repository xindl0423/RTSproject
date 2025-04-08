#pragma once
#include <Arduino.h>

#define ARRAY_SIZE 5
#define Button PC0  // Analog A0
#define switch0 PB0 // Digital 8
#define switch1 PB1 // Digital 9

extern uint8_t digits[ARRAY_SIZE];

void segment_init();
void displyValue(byte value);


#endif