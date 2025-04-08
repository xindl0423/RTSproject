#include "LED.h"
#include "Buzzer.h"
#include <util/delay.h>

int main() {
    LED_init();
    Buzzer_init();

    while (1) {
        // LED Sequence
        if (is_button_pressed()) {
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run the sequence
            LED_sequence();
            Buzzer_sequence();
        }
    }
}