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
#include "macros.h"
//================= [Tasks] ===============
void Blink_200ms_task( void *pvParameters)
{
DDRA |=(1<<0); //PA.0 is output
	
	while(1)
	{
		
		//PORTA ^= (1<<0); //toggle PA.0
		//vTaskDelay(200); //OS Delay
		//set_bit(PORTA,0);
		PORTA |= (1<<0);
	}
}
//--------------------------------------------------
void Blink_1000ms_task( void *pvParameters)
{
	//DDRB |=(1<<0); //PB.0 is output
	DDRA |= (1<<0);
	while(1)
	{
		
		//PORTB ^= (1<<0); //toggle PB.0
		//vTaskDelay(1000); //OS Delay
		//clr_bit(PORTA,0);
		PORTA &= ~(1<<0);
	}
}


//================= [Main] ====================
#include <avr/io.h>

int main(void)
{
	// Create Tasks
	xTaskCreate( Blink_200ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( Blink_1000ms_task,NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	
	// Start FreeRTOS
	vTaskStartScheduler();
	
}
