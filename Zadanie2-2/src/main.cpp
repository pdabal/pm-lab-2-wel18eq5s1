#include <avr/io.h>
#define SOLUTION 0
uint8_t button;
bool state = true;

 void togglePinD13(bool *state) // Zmiana stanu wyjścia D13
 {
       PORTB = (*state << 5);
       *state = !(*state);
 }

 void delay()
 {
   for (uint32_t j = 0x1FFFF; j > 0; j--)
       __asm__ __volatile("nop");
 }

 int main()
 {
   DDRB &= !(1 << 0); // Skasowanie PB0 (D8) - praca jako wejście
   DDRB |= (1 << 5); //Ustawienie PB5 (D13) - praca jako wyjście
   while (1)
   {
 #if (SOLUTION == 0)
     button = (PINB & (1 << PINB0)); //Odczytanie stanu PB0
     if(button == 0) {// Jeeli przycisk puszczony - przełącz
       togglePinD13(&state); // Zmiana stanu PB5
       delay(); // Pauza
     }
     else //W przeciwnym razie
       delay(); // Pauza
 #elif (SOLUTION == 1)
 // Rozwiązanie alternatywne
       while (!(PINB & (1 << PINB0))){
         togglePinD13(&state); // Zmiana stanu PB5
         delay(); // Pauza
       }
 #endif
   }
   }