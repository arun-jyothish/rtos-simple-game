/*
 * jyo_file.h
 *
 *  Created on: 16-Aug-2023
 *      Author: arun
 */

#ifndef JYO_FILE_H_
#define JYO_FILE_H_

/*LED PINS AND PORT DEFINITION FOR RED , GREEN , BLUE LEDS*/
#define blue_led_pin  21
#define red_led_pin  22
#define green_led_pin  26

#define blue_led_port PORTB
#define red_led_port PORTB
#define green_led_port PORTE

#define blue_led_base GPIOB
#define red_led_base GPIOB
#define green_led_base GPIOE
//------------------------------------------------------------

typedef enum {
	red,
	blue,
	green
} jLEDs;

//_______________________________________________________________
//Function Declarations

void light_led( jLEDs led , int state );
void led_init(void );

#endif /* JYO_FILE_H_ */
