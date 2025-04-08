#include "LCD.h"
#include "PINinit.h"

void LCD_init() {
    DDRB |= (1 << RS) | (1 << EN);
    DDRD |= 0xF0; // PD4-PD7 as outputs
    
    _delay_ms(20);
    LCD_command(0x28); // 4-bit, 2-line, 5x7
    LCD_command(0x06); // Cursor right
    LCD_clear();
    LCD_command(0x0F); // Display on, blink
}

void LCD_command(uint8_t cmd) {
    PORTB &= ~(1 << RS);
    PORTD = (PORTD & 0x0F) | (cmd & 0xF0);
    
    PORTB |= (1 << EN);
    _delay_us(1);
    PORTB &= ~(1 << EN);
    _delay_ms(2);
    
    PORTD = (PORTD & 0x0F) | (cmd << 4);
    PORTB |= (1 << EN);
    _delay_us(1);
    PORTB &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_data(uint8_t data) {
    PORTB |= (1 << RS);
    PORTD = (PORTD & 0x0F) | (data & 0xF0);
    
    PORTB |= (1 << EN);
    _delay_us(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
    
    PORTD = (PORTD & 0x0F) | (data << 4);
    PORTB |= (1 << EN);
    _delay_us(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}

void LCD_string(const char *str) {
    while(*str) LCD_data(*str++);
}

void LCD_clear() {
    LCD_command(0x01);
    _delay_ms(2);
}

void LCD_set_cursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x80 : 0xC0;
    LCD_command(address + col);
}