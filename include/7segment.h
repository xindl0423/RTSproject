#pragma once
#include <Arduino.h>

#define ARRAY_SIZE 5

extern uint8_t digits[ARRAY_SIZE];

void segment_init();
void displyValue(byte value);
