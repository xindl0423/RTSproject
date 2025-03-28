#include <ADC.h>

void updateLED(uint16_t x_value, uint16_t y_value);
int ADC_Read(byte channel);

void updateLED(uint16_t x_value, uint16_t y_value){
    PORTB &= ~((1 << LED_up) | (1 << LED_down) | (1 << LED_centre) | (1 << LED_right) | (1 << LED_left));
    if(x_value >= 256 && x_value <= 768 && y_value >= 256 && y_value <= 768){
        PORTB |= (1<<LED_centre);
    }
    else if (x_value  < 256){
        PORTB |= (1<<LED_left);
    }
    else if(x_value > 768){
        PORTB |= (1<<LED_right);
    }
    else if(y_value < 256){
        PORTB |= (1<<LED_down);
    }
    else if(y_value > 768){
        PORTB |= (1<<LED_up);
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