/*
 * RTOS_test_EX1.c
 *
 * In this  exercise, we have two tasks. First task blinks a LED every 200 msec and the other one blinks a LED every 1000 msec
 * The two tasks run in parallel.
 *
 *  Author: Nael
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
//================= [Tasks] ===============
void Blink_200ms_task( void *pvParameters)
{
	DDRA |=(1<<0); //PA.0 is output
	
	while(1)
	{
		
		PORTA ^= (1<<0); //toggle PA.0
		vTaskDelay(500); //OS Delay 200*TIC Time
	}
}
//--------------------------------------------------
void Blink_1000ms_task( void *pvParameters)
{
	DDRA |=(1<<1); //PB.0 is output
	
	while(1)
	{
		
		PORTA ^= (1<<1); //toggle PB.0
		vTaskDelay(1000); //OS Delay
	}
}
void Blink_1500ms_task( void *pvParameters)
{
	DDRA |=(1<<2); //PA.0 is output

	while(1)
	{

		PORTA ^= (1<<2); //toggle PA.0

		vTaskDelay(1500); //OS Delay 200*TIC Time
	}
}
void Blink_2000ms_task( void *pvParameters)
{
	DDRA |=(1<<3); //PA.0 is output

	while(1)
	{

		PORTA ^= (1<<3); //toggle PA.0
		vTaskDelay(2000); //OS Delay 200*TIC Time
	}
}

//================= [Main] ====================
#include <avr/io.h>

int main(void)
{
	// Create Tasks
	xTaskCreate( Blink_200ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( Blink_1000ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( Blink_1500ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( Blink_2000ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	
	// Start FreeRTOS
	vTaskStartScheduler();
	
}
