/*
 * RTOS_interface.h
 *
 *  Created on: May 23, 2019
 *      Author: Hanna Nabil
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


#define SUSPENDED 0
#define ACTIVE    1
u8 RTOS_u8CreateTask(void (*Copy_Handler)(void) , u8 Copy_Periodicity , u8 Copy_Priority,u8 FirstDelay);
u8 RTOS_StartOs(void);

#define OS_DELAY(Priority ,Value)  SysTask[Priority].DelayValue=value;\
									SysTask[Priority].IsDelayed=1;\
									SysTask[Priority].ReturnLine=PC;\
									if(1)\
									return

#endif /* RTOS_INTERFACE_H_ */
