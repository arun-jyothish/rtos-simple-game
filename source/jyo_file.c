/*
 * jyo_file.c
 *
 *  Created on: 16-Aug-2023
 *      Author: arun
 */

#include "jyo_file.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "MK64F12.h"
#include <stdint.h>


void led_init() {
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);
	port_pin_config_t led_port_config = {
		.driveStrength = 1,
		.lockRegister = 0,
		.mux = kPORT_MuxAsGpio,
		.openDrainEnable = 0,
		.passiveFilterEnable = 0,
		.pullSelect = 0,
		.slewRate = 0
	};

	uint32_t mask = 0b11 << 21;				//  mask for red led and blue led
	PORT_SetMultiplePinsConfig( blue_led_port, mask, &led_port_config);	// blue & red led portConfig

	mask = 0b1 << 26;
	PORT_SetMultiplePinsConfig( green_led_port, mask, &led_port_config);

	gpio_pin_config_t led_config = { .pinDirection = kGPIO_DigitalOutput,
			.outputLogic = 1 };			// SET LED DEFAULT OFF

	GPIO_PinInit(red_led_base, red_led_pin, &led_config);
	GPIO_PinInit(blue_led_base, blue_led_pin, &led_config);
	GPIO_PinInit(green_led_base, green_led_pin, &led_config);
}

void light_led( jLEDs led , int state){
	switch (led){
	case red:
		GPIO_PinWrite(red_led_base, red_led_pin, !state);
		break;
	case blue:
		GPIO_PinWrite(blue_led_base, blue_led_pin, !state);
		break;
	case green:
		GPIO_PinWrite(green_led_base, green_led_pin, !state);
	}
}

