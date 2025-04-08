#include "7segment.h"
#include <util/delay.h>

uint8_t digits[ARRAY_SIZE] = {0xEE, 0x82, 0xDC, 0xD6, 0xB2, 0x76, 0x7E, 0xC2, 0xFE, 0xF6, 0xFA, 0xFE, 0x6C, 0xEE, 0x7C, 0x78};

void segment_init() {
    DDRD = 0xFF;    // PORTD (0-7) as outputs for segments
    DDRB |= 0x0F;   // PB0-PB3 (8-11) for digit selection
    DDRC |= 0x1E;   // PC1-PC4 (A1-A4) for digit selection
    
    // Initialize button
    DDRC &= ~(1<<Button);
    PORTC |= (1<<Button);
    
    // Initialize switches
    DDRB &= ~((1<<switch0) | (1<<switch1));
    PORTB |= ((1<<switch0) | (1<<switch1));
}

void displaydigits() {
    static uint8_t current_digit = 0;
    PORTD = digits[current_digit];
    current_digit = (current_digit + 1) % ARRAY_SIZE;
    _delay_ms(500);
}