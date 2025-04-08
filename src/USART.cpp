#include <USART.h>
#inclde <PINinit.h>

// Function to initialize the USART to 8-bit char and 1 stop bit
void USART_init(void)
{
    // Set baud rate
    UBRR0 = BAUD_RATE; 
    // Set frame format: 8 data, 1 stop bit.
    UCSR0C = ((0 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00));
    // Enable receiver and transmitter 
    UCSR0B = ((1 << RXEN0) | (1 << TXEN0));
}

// Function to send one char 
void USART_send(unsigned char data)
{
    // Wait until transmit buffer is empty
    while(!(UCSR0A & (1 << UDRE0)));
    // Write data to transmit buffer
    UDR0 = data;
}

// Function to send a string
void USART_send_string(char* str)
{
    while (*str != '\0')
    {
        USART_send(*str);
        str++;
    }
}

// Function to receive a char
unsigned char USART_receive(void)
{
    // Wait for data to be received
    while(!(UCSR0A & (1 << RXC0)));
    // Get the received data and return it
    return UDR0;
}	

// Function to receive a string
void USART_get_string(char* str) 
{
    unsigned char i = 0;
    unsigned char c;
  
    while(1) // Loop forever
    {
        c = USART_receive(); // Grab the next character
        if(c == '\r' || c == '\n') // Break on carriage return or newline
        {
            break;
        }
        str[i] = c; // Write into the supplied buffer
        i++; // Next character index
    }
    str[i] = '\0'; // Null-terminate the string
}