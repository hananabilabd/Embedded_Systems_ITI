/*
 * DIO_private.h
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_



typedef struct{
	Register_32Bit CRL;
	Register_32Bit CRH;
	Register_32Bit IDR;
	Register_32Bit ODR;
	Register_32Bit BSRR;
	Register_32Bit BRR;
	Register_32Bit LCKR;

}GPIO;

#define DIO_GPIOA ((GPIO*) 0x40010800)
#define DIO_GPIOB ((GPIO*) 0x40010C00)
#define DIO_GPIOC ((GPIO*) 0x40011000)
#define DIO_GPIOD ((GPIO*) 0x40011400)


#endif /* DIO_PRIVATE_H_ */
