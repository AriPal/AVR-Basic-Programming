/*
 * PWM.c
 *
 * Created: 31.10.2016 10.57.30
 * Author : dhs
 */ 
#define F_CPU 20000000

#include <avr/io.h>
#include <avr/interrupt.h>

double dutyCycle = 0; 

int main(void)
{
	DDRD = (1 << PORTD6); // Set output
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);  
	TIMSK0 = (1 << TOIE0); // When it overflows
	
	setupADC(); 
	sei(); 
	
	TCCR0B = (1 << CS00) | (1 << CS02); // Prescaler

    while (1) 
    {
    }
}

void setupADC()
{
	// ADC settup
	ADMUX = (1 << REFS0) | (1 << MUX2) | (1 << MUX0); // Set reference and pin
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) ; // ADEN - Enables the ADC conversion, ADIE - activate interrupt, ADPS[2:0] a reliable division factor
	DIDR0 = (1 << ADC5D); 

	startConversion(); 
}

void startConversion()
{
	// Start conversion
	ADCSRA |= (1 << ADSC);
}

ISR(TIMER0_OVF_vect)
{
	OCR0A = dutyCycle; 
}

ISR(ADC_vect)
{
	dutyCycle = ADC; 
	startConversion(); 
}
