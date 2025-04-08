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
    USART_init();
    LCD_command(1);

    while (1) {
        if (is_button_pressed()) {
            
            // Wait for button release
            while (is_button_pressed());
            _delay_ms(50);
            
            // Run sequences
            LED_sequence();
            Buzzer_sequence();
            /*Code that sends to LCD and USART*/
            LCD_string("Press button to start count down");
            USART_send_string("Press button to start count down");
        }
    }
}