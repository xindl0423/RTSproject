#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USART_init(unsigned int ubrr);
void USART_send(char data);
void USART_send_string(const char *str);

#endif