/*
 * RTOS_LAB2_ATMEGA32.c
 *
 * brief: show how to sync.between an ISR and a task 
 * that will print a welcome message in LCD if button pressed  
 *
 * Created: 1/30/2014 12:07:51 AM
 *  Author: Islam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd_4bit.h"
#include "macros.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#define F_CPU 8000000UL
#include <util/delay.h>

/*task function prototype */
void TASK(void * pvParameters );

/*create a semaphore handle*/
xSemaphoreHandle task_sync_sem ; 

int main(void)
{
	
	/*initialization section*/
	/*initialize PD2 as INPUT and enable PULL-UP resistor*/
	DDRD &=0xfB; // set direction you can use clear macro instead of this way CLR_BIT(PORTD,2)
	PORTD|=0x04; // set PORTD.PD2 high to enable PULL-UP resistor you can use instead this way SET_BIT(PORTD,2)

	/*enable external interrupt INT0 and set sense control for low level */
	MCUCR &=0xfC; // set MCU control register to enable int0 and sense low level 
	SET_BIT(GICR,6); // enable INT0 from global interrupt reg
	SET_BIT(SREG,7); // enable GlOBAL interrupt in SREG 

	/*init LCD*/
	lcd_init();
	
	/*Create binary semaphore with initial value 0 because we used it for sync. between INTERRUPT and TASK*/
	task_sync_sem = xSemaphoreCreateCounting(1,0);

	/*create task */
	xTaskCreate(TASK,"task",configMINIMAL_STACK_SIZE,NULL,2,NULL);
	/*Start OS "Scheduler " */

	vTaskStartScheduler();


}

void TASK(void * pvParameters )
{

	for (;;)
	{
		//lcd_dispString("Running");
		//delay_ms(500);
		//lcd_clrScreen();
		/*pend for semaphore until it released from ISR */

		xSemaphoreTake(task_sync_sem,portMAX_DELAY);

			/*print if semaphore released*/
			lcd_dispString("Button pressed:D");

			_delay_ms(500);

			/*clear screen */
			lcd_clrScreen();

		/*take semaphore to decrement it is val. to wait again until it released by Interrupt */
		//xSemaphoreTake(task_sync_sem,portMAX_DELAY);
	}

}

/*interrupt service routine for external interrupt 0 (PD2) */
ISR(INT0_vect)
{
	/*release semaphore */
	xSemaphoreGiveFromISR(task_sync_sem,NULL);
}
