#pragma once
#include <Arduino.h>

//PortB
#define LED1 PB5
#define LED2 PB4
#define LED3 PB3
#define BUZZER_PIN PC3
#define RS PB1 // Register Select is connected to PB0
#define EN PB0 // Enable pin is connected to PB1

//PortD
#define DATA PD1 // pin 4 of Arduino for data pin of shift register
#define LATCH PD2 // pin 2 of Arduino for Latch pin of shift register
#define CLOCK PD3  // pins 3 of Arduino for clock pin of shift register 
#define D4 PD4 // D4 is connected to PD4
#define D5 PD5 // D5 is connected to PD5
#define D6 PD6 // D6 is connected to PD6
#define D7 PD7

//PortC
#define BUTTON_PIN PC0