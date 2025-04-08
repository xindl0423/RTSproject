#include "LED.h"
#inclde <PINinit.h>
#include <util/delay.h>

void LED_init() {
    // Set LED pins as outputs
    DDRB |= (1 << LED1) | (1 << LED2) | (1 << LED3);
    // Turn all LEDs OFF (active-high)
    PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3));
    
    // Configure button pin (A0/PC0)
    DDRC &= ~(1 << BUTTON_PIN);  // Set as input
    PORTC |= (1 << BUTTON_PIN);  // Enable pull-up
}

uint8_t is_button_pressed() {
    if (!(PINC & (1 << BUTTON_PIN))) {  // Button pressed (active-low)
        _delay_ms(30);  // Debounce delay
        if (!(PINC & (1 << BUTTON_PIN))) return 1;
    }
    return 0;
}

void LED_sequence() {
    // Turn all LEDs OFF
    PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3));
    _delay_ms(20);
    
    // Sequence: Turn on LEDs one by one
    PORTB |= (1 << LED1);  // LED1 (PB5) ON
    _delay_ms(3000);
    PORTB |= (1 << LED2);  // LED2 (PB4) ON
    _delay_ms(3000);
    PORTB |= (1 << LED3);  // LED3 (PB3) ON
    _delay_ms(3000);
    
    // Turn all OFF
    PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3));
}