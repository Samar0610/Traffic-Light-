#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"

void Timer_CTC_init_interrupt(void)
{
	SET_BIT(TCCR0,WGM01);  // select ctc mode
	OCR0=80; // compare match value
	
	// set timer clock value
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// enable interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timer_wave_nonPWM(void)
{
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM01);  // select ctc mode
	OCR0=80; // compare match value
	
	// set timer clock value
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	SET_BIT(TCCR0,COM00);
}