#include "LED.h"
#include "Buzzer.h"
#include "PINinit.h"
#include "USART.h"
#include "seg7.h"
#include <util/delay.h>

int main() {
    LED_init();
    Buzzer_init();

    while (1) {
        if (is_button_pressed()) {
            // Immediate feedback beep
            PORTB |= (1 << BUZZER_PIN);
            _delay_ms(100);
            PORTB &= ~(1 << BUZZER_PIN);
            
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run sequences
            LED_sequence();
            Buzzer_sequence();
        }
    }
}