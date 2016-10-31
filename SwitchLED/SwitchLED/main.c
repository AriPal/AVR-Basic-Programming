/*
 * SwitchLED.c
 *
 * Created: 25.10.2016 09.36.05
 * Author : dhs
 */ 

#define F_CPU 20000000L

//__________INCLUDES_____________
#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRB = 0x01; // Turn PortB to Output and all others input
	PORTB = 0x02; // PB1 bit is set to HIGH
	 
    /* Replace with your application code */
    while (1) 
    {	 
		if (!(PINB & 0x02))
		{
			PORTB |= 0x01; // Set PB0 to high = 0000 001[1]
		} else {
			PORTB &= 0xFE;
		}
    }
}

