#include "Button.h"
#include <util/delay.h>

void Button_init() {
    DDRC &= ~(1 << BUTTON_PIN); // Setting input
    PORTC |= (1 << BUTTON_PIN); // Pull up
}

uint8_t is_button_pressed() {
    if (!(PINC & (1 << BUTTON_PIN))) {  // Button pressed (active-low)
        _delay_ms(30);  // Debounce delay
        if (!(PINC & (1 << BUTTON_PIN))) return 1;
    }
    return 0;

}