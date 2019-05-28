/*
 * SysTick.h
 *
 *  Created on: May 23, 2019
 *      Author: Hanna Nabil
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define STK_CTRL            *((u32*) 0xE000E010)
#define STK_LOAD            *((u32*) 0xE000E014)
#define STK_VAL             *((u32*) 0xE000E018)
#define STK_CALIB           *((u32*) 0xE000E01C)
#define NULL_ADDRESS           (void(*)(void)) 0x0

void SysTick_Initialize(u16 period);
void SysTick_Disable(void);
void SysTick_Handler(void);
void SysTick_setcallback(void (*ptr)(void) );
#endif /* SYSTICK_H_ */
