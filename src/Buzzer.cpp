#include <Arduino.h>
#include <avr_debugger.h>

#define BUZZER_PIN 5
#define BUTTON_PIN 1

int main()
{
    #ifdef __DEBUG__
      dbg_start();
    #endif

    DDRD |= (1<< BUZZER_PIN); // set PD5 port to output for buzzer
    DDRB &= ~(1<<BUTTON_PIN); // set PB1 to input
    PORTB |= (1<<BUTTON_PIN); // Enabling internal pull-up at PB1

    while(1)
    {
      if(!(PINB & (1<<BUTTON_PIN))) // if button is pressed
      {
        PORTD |= (1<<BUZZER_PIN); // turn on buzzer
      }
      else // if button is not pressed
      {
        PORTD &= ~(1<<BUZZER_PIN); // turn off buzzer
      }
    }
}
