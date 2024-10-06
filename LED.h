/*
 * LED.h
 *
 * Created: 21/11/2023 01:59:27 ص
 *  Author: Admin
 */ 


#ifndef LED_H_
#define LED_H_

void LED_Init(unsigned char port_nam, unsigned char pin_num);

/* Function to set the direction of a given pin in a given port as an output pin
   Function name   : LED_Init
   Function return : void 
*/

void LED_Turn_on(unsigned char port_nam, unsigned char pin_num);

/* Function to set the output of a given pin in a given port as high output to turn on the led 
   Function name   : LED_Turn_on
   Function return : void 
*/

void LED_Turn_off(unsigned char port_nam, unsigned char pin_num);

/* Function to set the output of a given pin in a given port as low output to turn off the led 
   Function name   : LED_Turn_off
   Function return : void 
*/

void LED_Tog(unsigned char port_nam, unsigned char pin_num);
/* Function to toggle the output of a given pin in a given port
   Function name   : LED_Tog
   Function return : void 
*/

#endif /* LED_H_ */