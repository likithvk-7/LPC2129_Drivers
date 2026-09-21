/* --------------------------------------------------------------------------------------

Usedefined delay functions for LPC2129 microcontroller

Delay in seconds, milliseconds and microseconds using timer0 and its registers

VPBDIV=0; PCLK=15MHz; T0PR=15MHz-1;

If VPBDIV=1; PCLK=60MHz; T0PR=60MHz-1;

If VPBDIV=2; PCLK=30MHz; T0PR=30MHz-1;
---------------------------------------------------------------------------------------*/

#include<lpc21xx.h>

//Delay in seconds

void delay_sec(unsigned int sec)
{
	T0PR=15000000-1;                      // As VPBDIV=0 Prescale Reg value is 14999999 
	T0PC=0;                               // T0PC counts from 0 to T0PR value
	T0TC=0;                               // for every T0PC count from 0 T0PR value T0TC increments by 1
	T0TCR=0X01;                           // Start timer0 
	while(T0TC<sec);
	T0TCR=0x00;                           // Stop timer0
}

//Delay in milliseconds

void delay_ms(unsigned int ms)
{
	T0PR=15000-1;
	T0PC=0;
	T0TC=0;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x00;
}

//Delay in microseconds

void delay_us(unsigned int us)
{
	T0PR=15-1;
	T0PC=0;
	T0TC=0;
	T0TCR=0X01;
	while(T0TC<us);
	T0TCR=0X00;
}

