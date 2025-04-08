#include "USART.h"
#include "stdlib.h"

void USART_init(unsigned int ubrr) {
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART_send(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void USART_send_string(const char *str) {
    while (*str) USART_send(*str++);
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

void parse(const char *text, uint8_t *red, uint8_t *green, uint8_t *blue) {
    char *end;
    *red = (uint8_t)strtoul(text, &end, 10);
    *green = (uint8_t)strtoul(end, &end, 10);
    *blue = (uint8_t)strtoul(end, NULL, 10);
}