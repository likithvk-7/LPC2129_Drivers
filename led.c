/* --------------------------------------------------------------------------------------

Active HIGH LED blinking using LPC2129 microcontroller

user defined delay functions are in delay.c file

Default state of Active HIGH LED is OFF state

LPC2129 has two GPIO ports P0 and P1

Port P0 has pins from P0.0 to P0.31 and port P1 has pins P1.0 to P1.31

In P0, P0.26 and P0.31 are not programmable and in P1, P1.0 to P1.15 are not programmable

Each Port has four 32-bit registers named IODIR, IOSET, IOCLR, IOPIN

IODIR is used to determine whether pin is INPUT or OUTPUT direction;
IOSET is used to set pin to HIGH; 
IOCLR is used to set pin to LOW; 
IOPIN is to decide read/write mode;

// use   8     4     2     1 code
//     P0.3   P0.2  P0.1  P0.0

For example to use pin 0, we need to set P0.0 its decimal value is 1    
For pins 0 and 1 we need to set P0.0 and P0.1 its decimal value is 3    
Similarly for pins 0 to 7 we need to set all pins from P0.0 TO P0.7 its decimal value is 255

---------------------------------------------------------------------------------------*/

#include<lpc21xx.h>
#include "header.h"
#define LED 7 // Macro for pins P0.1, P0.1 and P0.3 //Change the value of macro if LEDs are connected to different pins
int main()
{
IODIR0=LED;   // Sets P0.1 P0.2 and P0.3 as output direction
while(1)      // Infinite loop
{
IOSET0=LED;   // Sets P0.1 P0.2 and P0.3 HIGH and turns ON the LEDs
delay_ms(500);
IOCLR0=LED;   // Sets P0.1 P0.2 and P0.3 LOW and turns OFF the LEDs
delay_ms(500);
}
}

