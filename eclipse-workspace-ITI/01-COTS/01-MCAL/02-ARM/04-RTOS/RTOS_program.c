/*
 * RTOS_program.c
 *
 *  Created on: May 23, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "SysTick.h"
static Task SysTasks[RTOS_u8_NUM_OF_TASK] ={0};
static u8 u8TickCounter=0;

static void Schedular(void){
	u8 Local_u8LoopIndex;
	u8TickCounter++;
	for (Local_u8LoopIndex=0; Local_u8LoopIndex <RTOS_u8_NUM_OF_TASK;Local_u8LoopIndex++){
		if ((SysTasks[Local_u8LoopIndex].TaskHandler != NULL_ADDRESS) && (SysTasks[Local_u8LoopIndex].state = ACTIVE) ){
			/* No valid Task */
			if (SysTasks[Local_u8LoopIndex].IsFirstTime==1){
				if (u8TickCounter % (SysTasks[Local_u8LoopIndex].FirstDelay)){
					SysTasks[Local_u8LoopIndex].TaskHandler();
					SysTasks[Local_u8LoopIndex].IsFirstTime=0;
				}
			}
			if (SysTasks[Local_u8LoopIndex].IsDelayed==1){
				SysTasks[Local_u8LoopIndex].DelayValue--;
				if (SysTasks[Local_u8LoopIndex].DelayValue ==0){
					SysTasks[Local_u8LoopIndex].IsDelayed =0;
					/*** Run the task from the delayed line */
					SysTasks[Local_u8LoopIndex].ReturnLine =0;
				}
			}

			else if  ((u8TickCounter - (SysTasks[Local_u8LoopIndex].FirstDelay)) %
				(SysTasks[Local_u8LoopIndex].Periodicity)==0){
			SysTasks[Local_u8LoopIndex].TaskHandler();
		}
		}

	}
}
u8 RTOS_u8CreateTask(void (*Copy_Handler)(void) , u8 Copy_Periodicity , u8 Copy_Priority,u8 FirstDelay , u8 Copy_state){
	u8 Local_u8OperationStatus;
	if ( ( (SysTasks[Copy_Priority].TaskHandler) == NULL_ADDRESS) &&  (Copy_Priority < RTOS_u8_NUM_OF_TASK)){
		SysTasks[Copy_Priority].TaskHandler =Copy_Handler;
		SysTasks[Copy_Priority].Periodicity =Copy_Periodicity;
		SysTasks[Copy_Priority].IsFirstTime =1;
		SysTasks[Copy_Priority].state =Copy_state;
	}
	return Local_u8OperationStatus;
}
u8 RTOS_StartOs(void){
 /* Initialize Tick Timer */
	SysTick_setcallback(Schedular);
	SysTick_Initialize(100);

}
void RTOS_DeleteTask(u8 Copy_Priority){
	if (Copy_Priority < RTOS_u8_NUM_OF_TASK){
		SysTasks[Copy_Priority].TaskHandler =NULL_ADDRESS;
	}
}
u8  RTOS_TaskSuspend(u8 Copy_Priority){
	if (Copy_Priority < RTOS_u8_NUM_OF_TASK){
		SysTasks[Copy_Priority].state =SUSPENDED;
	}
}
u8  RTOS_TaskResume(u8 Copy_Priority){
	if (Copy_Priority < RTOS_u8_NUM_OF_TASK){
		SysTasks[Copy_Priority].state =ACTIVE;
	}
}

