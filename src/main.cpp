#include "LED.h"
#include "Buzzer.h"
#include "PINinit.h"
#include "USART.h"
#include "seg7.h"
#include "Button.h"
#include <util/delay.h>
#include "LCD.h"

int main() {
    LED_init();
    Buzzer_init();
    LCD_init();
    USART_init(MYUBRR);

    // Immediate feedback beep
    PORTC |= (1 << BUZZER_PIN);
    _delay_ms(100);
    PORTC &= ~(1 << BUZZER_PIN);

    char text[256];
    uint8_t red, green, blue;

    while (1) {
        if (is_button_pressed()) {
            
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run sequences
            LED_sequence();
            Buzzer_sequence();
            /*Code that sends to LCD and USART*/
            LCD_string("Type valid values for R G B color (use space between values): ");
            USART_send_string("Type valid values for R G B color (use space between values): ");
            USART_get_string(text);
            parse(text, &red, &green, &blue); // Parse RGB values with error checking
            
        }
    }
}