#include <avr/io.h>

int main()
{
  uint32_t i;

  DDRC |= (1<<7);
  while (1)
  {
    PORTC |= (1<<7);
    i = 0x3FFFF;
    do
    {
      __asm__ __volatile("nop");
    } while (i--);
    PORTC &= !(1<<7);
    i = 0x3FFFF;
    do
    {
      __asm__ __volatile("nop");
    } while (i--);
  }
}