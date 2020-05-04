#include <avr/io.h>
#define SOLUTION 0
uint8_t button;
bool state = true;

void togglePinD13(bool *state)
{
  PORTB = (*state << 5);
  *state=!(*state);
}

void delay()
{
  for(uint32_t j = 0x1FFFF; j > 0; j--)
  __asm__ __volatile__("nop");
}
