/*
 * RTOS_private.h
 *
 *  Created on: May 23, 2019
 *      Author: Hanna Nabil
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


typedef struct {
	void (*TaskHandler)(void);
	u8 Periodicity;
	u8 FirstDelay;
	/*        private data */
	u8 IsFirstTime;
	u8 state;
	u8 IsDelayed;
	u8 DelayValue;
	void (*ReturnLine)(void);
}Task;
static void Schedular(void);
#define RTOS_u8_NUM_OF_TASK    4

#define NULL_ADDRESS           (void(*)(void)) 0x0

#endif /* RTOS_PRIVATE_H_ */
