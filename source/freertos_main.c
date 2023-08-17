/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*jyothu includes*/
#include "jyo_file.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void hello_task(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */

static void redL();
static void greenL();
int main(void)
{
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
/*    -------------------------------------*/
    led_init();						// initialized red, blue, green leds
#define RAND_MAX 10
	srand(time(NULL));

/*	while(1){
		redL();
		greenL();
	}*/

	//    --------------------------------------------------------------------------------
/*
	int max = 500, min = 5;
		while (1){
		int rn = rand() % max;
		if (rn < min && rn > 0){
	        light_led(blue, true);
	        light_led(green, false);
	        PRINTF(" red.\r\n");
		}
		else if (rn < max && rn > max-min){

	        light_led(green, true);
	        light_led(blue, false);
	        PRINTF(" blue.\r\n");
		}
		else{
	        light_led(blue, false);
	        light_led(green, false);
		}
		}*/
	//	-----------------------------------------------------------------------------------

/*    -------------------------------------*/
    if (xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY-2, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1) ;
    }
    if (xTaskCreate(redL, "red_led", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY-1, NULL) !=
          pdPASS)
      {
          PRINTF("red_led!.\r\n");
          while (1) ;
      }
    if (xTaskCreate(greenL, "green_led", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY-1, NULL) !=
          pdPASS)
      {
          PRINTF("green_led!.\r\n");
          while (1) ;
      }



    vTaskStartScheduler();

    for (;;)
        ;
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters)
{
    for (;;)
    {
        PRINTF("Hello world.\r\n");
        light_led(red, false);
        vTaskSuspend(NULL);
    }
}
static void greenL(){
	while(1)
		light_led(green,true);
//	vTaskDelay(1);
}
static void redL(){
	while(1)
		light_led(red,true);
}
/*void led_task1 (){
	while (1){ 
	int rn = rand() % 20;
	if (rn < 5 && rn > 0){
        light_led(blue, true);
	}
	else if (rn < 20 && rn > 14){
        light_led(green, true);
	}
	vTaskDelay(150);
    light_led(green, false);
    light_led(blue, false);
	vTaskDelay(150);
	}
}*/
