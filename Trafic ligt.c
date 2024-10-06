


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Seven Segment.h"
#include "LED.h"
#include "Timer.h"
#include "std_macros.h"

volatile signed char counter_g=20;
volatile signed char counter_y=15;
volatile signed char counter_r=20;


volatile char counter2=0;
volatile char counter3=0;

int main(void)
{
	seven_segment_Init('A');
	Timer_CTC_init_interrupt();
	LED_Init('D',0);
	LED_Init('D',1);
	LED_Init('D',2);
	SET_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	
    while(1)
    {
       // green sign 
	   while(counter_g>=0)
	   {
			  LED_Turn_on('D',0);
			   CLR_BIT(PORTB,0);
			   SET_BIT(PORTB,1);
			   seven_segment_write('A',counter_g%10);
			   while(counter3==0);
			   counter3=0;
			   
			   CLR_BIT(PORTB,1);
			   SET_BIT(PORTB,0);
			   seven_segment_write('A',counter_g/10);
			   while(counter3==0);
			   counter3=0;
			   if (counter2>100)
			   {
				   counter2=0;
				   counter_g--;
			   }
			  LED_Turn_off('D',0);				   
		   
	   }
	   //yellow sign
	   
	    while(counter_y>=0)
	    {
		    LED_Turn_on('D',1);
		    CLR_BIT(PORTB,0);
		    SET_BIT(PORTB,1);
		    seven_segment_write('A',counter_y%10);
		    while(counter3==0);
		    counter3=0;
		    
		    CLR_BIT(PORTB,1);
		    SET_BIT(PORTB,0);
		    seven_segment_write('A',counter_y/10);
		    while(counter3==0);
		    counter3=0;
		    if (counter2>100)
		    {
			    counter2=0;
			    counter_y--;
		    }
		    LED_Turn_off('D',1);
		    
	    }
	   
	   //red sign 
	     while(counter_r>=0)
	     {
		     LED_Turn_on('D',2);
		     CLR_BIT(PORTB,0);
		     SET_BIT(PORTB,1);
		     seven_segment_write('A',counter_r%10);
		     while(counter3==0);
		     counter3=0;
		     
		     CLR_BIT(PORTB,1);
		     SET_BIT(PORTB,0);
		     seven_segment_write('A',counter_r/10);
		     while(counter3==0);
		     counter3=0;
		     if (counter2>100)
		     {
			     counter2=0;
			     counter_r--;
		     }
		     LED_Turn_off('D',2);
		     
	     }
		 
		 counter_g=20;
		 counter_y=15;
		 counter_r=20;
    }
}
ISR(TIMER0_COMP_vect)
{
	counter2++;
	counter3=1;
	
}