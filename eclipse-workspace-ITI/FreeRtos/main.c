/*
 * main.c
 *
 *  Created on: Apr 16, 2019
 *      Author: Khlood
 */

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SSD_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

TaskHandle_t mytask1Handle = NULL;
TaskHandle_t mytask2Handle = NULL;
TaskHandle_t mytask3Handle = NULL;
TaskHandle_t mytask4Handle = NULL;

void VIDmytask1(void *p)
{
	TickType_t xLastWakeTime;
	DIO_u8SetPortDirection(DIO_u8_PORT_B, DIO_u8_OUTPUT);
	xLastWakeTime=xTaskGetTickCount();
	while(1)
	{
	  for(u8 iter1=0 ; iter1 <10  ; iter1++ )
	  {
		 SSD_u8DisplayOff(1);
		 SSD_u8WriteNumber(1,iter1);
		 SSD_u8DisplayOn(1);
		 vTaskDelay(pdMS_TO_TICKS(1000));
	  }
	}
}

int main(void)
{
	//Add of ISR
	//Name by developer for ISR
	//Depth of stack
	//pass argument
	//task priority
	//taskHandle unique per task

	xTaskCreate(VIDmytask1 , "LEDTask1" , 50 , (void*)0,tskIDLE_PRIORITY,mytask1Handle );

	vTaskStartScheduler();
	while(1)
	{

	}
	return 0;
}
