#include "USART.h"
#include <PINinit.h>

void USART_init(void){
    UBRR0 = BAUD_RATE;
    UCSR0C = ((1 << USBS0) | (1 << UCSZ01) | (1<< UCSZ00));
    UCSR0B = ((1 << RXEN0) | (1 << TXEN0));
}

void USART_send(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void USART_send_string(char* str) {
    while (*str != '\0'){
    USART_send(*str);
    str++;
    }
}

unsigned char USART_receive (void){
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void USART_get_string(char *buffer) {
    char c;
    uint8_t idx = 0;
    while (1) {
        while (!(UCSR0A & (1 << RXC0)));
        c = UDR0;
        if (c == '\r' || c == '\n') {
            buffer[idx] = '\0';
            break;
        }
        buffer[idx++] = c;
        if (idx >= 255) { // Prevent buffer overflow
            buffer[idx] = '\0';
            break;
        }
    }
}