#ifndef BUZZER_H
#define BUZZER_H

#include <avr/io.h>

#define BUZZER_PIN PB2

void Buzzer_init();
void Buzzer_sequence();

#endif