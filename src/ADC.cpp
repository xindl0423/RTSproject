#include <ADC.h>

void updateLED(uint16_t x_value, uint16_t y_value){
    PORTB &= ~((1 << LED5) | (1 << LED4) | (1 << LED3) | (1 << LED2) | (1 << LED1) | (1 << LED_down));
    if(x_value >= 256 && x_value <= 768 && y_value >= 256 && y_value <= 768){
        PORTB |= (1<<LED3);
    }
    else if (x_value  < 256){
        PORTB |= (1<<LED1);
    }
    else if(x_value > 768){
        PORTB |= (1<<LED5);
    }
    else if(y_value < 256){
        PORTB |= (1<<LED_down);
    }
}

int ADC_Read(byte channel)
{
    ADMUX = 0x40 | (channel & 0x07); // set input channel to read
    ADCSRA |= (1<<ADSC); // Start ADC conversion
    while (!(ADCSRA & (1<<ADSC))); // Wait until ADSC is 0
    _delay_ms(1); // Wait a little bit
    return ADCW; // Return ADC word
}