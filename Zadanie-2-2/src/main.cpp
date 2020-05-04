#include <avr/io.h>
#define LED_LENGHT 8

int main()
{
  DDRD |= 0xFF;
  while (1)
  {
    for (uint8_t i = 0; i < LED_LENGHT; i++)
    {
    
      PORTD = (1<< i);
      for (uint32_t j = 0x1FFFF; j > 0 ; j--)
      {
      __asm__ __volatile("nop");
      }

    }

    for (uint8_t i = 1; i < LED_LENGHT-1; i++)
    {
       PORTD = (PORTD >> 1);
     for (uint32_t j = 0x1FFFF; j > 0 ; j--)
      {
      __asm__ __volatile("nop");
      }
    }
  }
}