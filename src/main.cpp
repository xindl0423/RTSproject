#include "LED.h"
#include <util/delay.h>

int main() {
    LED_init();
    
    while (1) {
        if (is_button_pressed()) {
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run the sequence
            LED_sequence();
        }
    }
}