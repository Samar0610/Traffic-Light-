

#include "DIO.h"


void LED_Init(unsigned char port_nam, unsigned char pin_num)
{
	DIO_Pin_Direction(port_nam,pin_num,1);// set the given pin in a given port as output pin 
}

void LED_Turn_on(unsigned char port_nam, unsigned char pin_num)
{
	DIO_Pin_write(port_nam, pin_num,1);// set the output of a given pin in a given port as high output
}

void LED_Turn_off(unsigned char port_nam, unsigned char pin_num)
{
	DIO_Pin_write(port_nam, pin_num,0);// set the output of a given pin in a given port as low output
}

void LED_Tog(unsigned char port_nam, unsigned char pin_num)
{
	DIO_Pin_Tog(port_nam, pin_num);// toggel the output of a pin 
}