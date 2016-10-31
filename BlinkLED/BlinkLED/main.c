/*
 * BlinkLED.c
 *
 * Created: 24.10.2016 12.39.21
 * Author : dhs
 */ 

#define F_CPU 20000000L

//__________INCLUDES_____________
#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRB = 0x01; // Turn PortB to Output
	PORTB = 0; // All states are zero 

    /* Replace with your application code */
    while (1) 
    {	  
		PORTB = 0x01;		//Turn LED on
		_delay_ms(1000);	// Delay
		PORTB = 0;			//Turn LED off
		_delay_ms(1000);	// Delay 

    }
}

