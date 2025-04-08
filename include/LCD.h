#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>


// Function Prototypes
void LCD_init();
void LCD_command(uint8_t cmd);
void LCD_data(uint8_t data);
void LCD_string(const char *str);
void LCD_clear();
void LCD_set_cursor(uint8_t row, uint8_t col);

#endif