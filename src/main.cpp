#include <Arduino.h>
#include <avr/interrupt.h>
#include <ADC.h>
#include <USART.h>

int main() {
    #ifdef __DEBUG__
        dbg_start();
    #endif
    int x;
    int y;
    char text[30];
    USART_init();
    ADC_init();
    LED_init();
    updateLED(uint16_t x_value, uint16_t y_value);
    ADC_Read(byte channel);
    

    while (1) {
        x = ADC_Read(PC0);
        y = ADC_Read(PC1);
        updateLED(x, y);
        sprintf(text, "X: %d, Y: %d\n", x, y);
        USART_send_string(text);
    }
}
