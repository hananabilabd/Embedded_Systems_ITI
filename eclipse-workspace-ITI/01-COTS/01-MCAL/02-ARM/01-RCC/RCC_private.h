/*
 * RCC_private.h
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_u32_CR           ((Register_32Bit*) 0x40021000)
#define RCC_u32_CFGR         ((Register_32Bit*) 0x40021004)
#define RCC_u32_CIR          ((Register_32Bit*) 0x40021008) 
#define RCC_u32_APB2RSTR     ((Register_32Bit*) 0x4002100C)
#define RCC_u32_APB1RSTR     ((Register_32Bit*) 0x40021010)
#define RCC_u32_AHBENR       ((Register_32Bit*) 0x40021014)
#define RCC_u32_APB2ENR      ((Register_32Bit*) 0x40021018)
#define RCC_u32_APB1ENR      ((Register_32Bit*) 0x4002101C)
#define RCC_u32_PDCR         ((Register_32Bit*) 0x40021020)
#define RCC_u32_CSR          ((Register_32Bit*) 0x40021024)


#endif /* RCC_PRIVATE_H_ */
