#include <avr/io.h>

uint8_t button;
bool state = true;

void togglePinD13(bool *state)
{
  PORTB = (*state << 5);
  *state = !(*state);
}

void delay()
{
  for(uint32_t j = 0x1FFFF; j > 0; j--)
  __asm__ __volatile__("nop");
}

int main()
{
  DDRB &= !(1 << 0);
  DDRB |= (1 << 5);
  while (1)
  {
  button = (PINB & (1 << PINB0));
  if (button == 0)
  {
    togglePinD13(&state);
    delay();
  }
  else
    delay();
  }
}