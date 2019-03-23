/*
 * NVIC_private.h
 *
 *  Created on: Mar 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_
// base address is 0xE000E100
#define ISER ((u32*) 0xE000E100)  // Interrupt set Enable Register
#define ICER ((u32*) 0xE000E180)  //Interrupt clear Enable Register
#define ISPR ((u32*) 0xE000E200)  // Interrupt set pending Register
#define ICPR ((u32*) 0xE000E280)  // Interrupt clear pending Register
#define IABR ((u32*) 0xE000E300) //Interrupt Active Bit register
#define IPR  ((u8*) 0xE000E400)  //Interrupt priority register
#define STIR ((u32*) 0xE000EF00)  //software trigger interrupt register


//page 134 in programming manual
/***
 *  0xE000ED00+0C
 */
#define AIRCR ((u32*) 0xE000ED0C) // application interrupt and reset control register

#endif /* NVIC_PRIVATE_H_ */
