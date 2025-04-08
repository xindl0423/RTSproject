#include <avr/io.h>

// Button pin (A0/PC0)
#define BUTTON_PIN PC0

// Buzzer pin
#define BUZZER_PIN PB2

void Buzzer_init();
void Buzzer_sequence();