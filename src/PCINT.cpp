#include"PCINT.h"

void PCINT0_init()
{
    DDRC &=~(1<<BUTTON_PIN); //Button for PCINT0 as input
    PORTC |= (1<<BUTTON_PIN); // activate pull-up

  PCICR |= (1 << PCIE0);    // set PCIE0 to enable PCMSK0 scan
	PCMSK0 |= (1 << PCINT0) | (1 << PCINT1);  // set PCINT0 and 1 to trigger an interrupt on state change 
	sei();                    // turn on interrupts

}

void Timer1_init()
{
  TCCR1B |= (1<<CS12); // prescalar 256
  TCNT1 = 34285; //65535 - (0.5/0.000016)
  TIMSK1 |= (1<<TOIE1); //enable timer overflow interrupt
  sei();
}

