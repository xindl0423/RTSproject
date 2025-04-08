#pragma once
#include<Arduino.h>


#define BAUD_RATE 0x0067

void USART_init(void);
void USART_send(char data);
void USART_send_string(char* str);
unsigned char USART_receive (void);
void USART_get_string(char *str);