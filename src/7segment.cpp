#include <7segment.h>

void displaydigits()
{

  while(1)
  {
    byte i;
    if(PINC & (1<< Button)){
      if((PINB & (1<<switch0)) && !(PINB & (1<<switch1))){
     for(i = ARRAY_SIZE; i > 0;i--)
    {
      PORTD = digits[i];
      _delay_ms(1000);
    }
      }
    }
   
  }
}