#include <util/delay.h>
#include "Buzzer.h"

void Buzzer_init(){
    DDRB |= (1 << BUZZER_PIN);
    PORTB &= ~(1 << BUZZER_PIN);
}

void Buzzer_sequence(){
    PORTB |= (1 << BUZZER_PIN); // Buzzer on
    _delay_ms(3000);
    PORTB &= ~(1 << BUZZER_PIN); // Buzzer off
    _delay_ms(3000);
}