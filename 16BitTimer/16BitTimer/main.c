/*
 * 16BitTimer.c
 *
 * Created: 31.10.2016 09.59.37
 * Author : dhs
 * http://eleccelerator.com/avr-timer-calculator/#comment-1444
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0x01; // Set output
	TCCR1B = (1 << WGM12);
	OCR1A = 19531; // Timer limit (Ticks)
	TIMSK1 = (1 << OCIE1A);
	
	sei(); 
	
	TCCR1B |= (1 << CS12) | (1 << CS10); 

    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PORTB0);
}

