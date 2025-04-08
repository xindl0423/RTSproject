#include "LED.h"
#include "Buzzer.h"
#include <util/delay.h>

int main() {
    LED_init();
    Buzzer_init();

    while (1) {
        // LED Sequence
        if (is_button_pressed()) {
            // See if the buzzer can turn on immediately
            
            PORTB |= (1 << BUZZER_PIN);
            _delay_ms(100);
            PORTB &= ~(1 << BUZZER_PIN);
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run the sequence
            LED_sequence();
            Buzzer_sequence();
        }
    }
}