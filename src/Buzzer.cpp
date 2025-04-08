#include "Buzzer.h"
#include "PINinit.h"
#include <Buzzer.h>
#include <PINinit.h>
#include <util/delay.h> 

void Buzzer_init() {
    DDRC |= (1 << BUZZER_PIN);  // Set PC3 (A3) as output
    PORTC &= ~(1 << BUZZER_PIN); // Turn off buzzer initially
}

void Buzzer_sequence() {
    for (uint8_t i = 0; i < 3; i++) {
        PORTC |= (1 << BUZZER_PIN);  // Turn on buzzer
        _delay_ms(200);
        PORTC &= ~(1 << BUZZER_PIN); // Turn off buzzer
        _delay_ms(200);
    }
}