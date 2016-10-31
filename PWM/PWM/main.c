/*
 * PWM.c
 *
 * Created: 31.10.2016 10.57.30
 * Author : dhs
 */ 
#define F_CPU 20000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

double dutyCycle = 0; 

int main(void)
{
	DDRD = (1 << PORTD6); // Set output
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);  
	TIMSK0 = (1 << TOIE0); // When it overflows

	OCR0A = (dutyCycle/100.0)*255.0; // Time we want it to be ON.
	
	sei(); 
	
	TCCR0B = (1 << CS00) | (1 << CS02); // Prescaler

    while (1) 
    {
    }
}
ISR(TIMER0_OVF_vect)
{
	// Everytime it overflows, it recalculates. 
	OCR0A = (dutyCycle/100)*255; // Time we want it to be ON. 
	_delay_ms(300);
	dutyCycle += 10; 

	// Reset duty cycle if it is over 100
	if(dutyCycle > 100)
	{
		dutyCycle = 0; 
	}
}

