#ifndef LED_H
#define LED_H

#include <avr/io.h>

// LED pins (must match your hardware)
#define LED1 PB5
#define LED2 PB4
#define LED3 PB3

// Button pin (A0/PC0)
#define BUTTON_PIN PC0

void LED_init();
void LED_sequence();
uint8_t is_button_pressed();  // New function for button checking

#endif