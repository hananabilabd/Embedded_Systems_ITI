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
#define AFIO_MAPR           *((u32*) 0x40010004)

#define AFIO_MAPR_SWJ_CFG                      (0x7 << 24)
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ             (0x0 << 24)
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_NJRST    (0x1 << 24)
#define AFIO_MAPR_SWJ_CFG_NO_JTAG_SW           (0x2 << 24)
#define AFIO_MAPR_SWJ_CFG_NO_JTAG_NO_SW        (0x4 << 24)
#define AFIO_BASE                       ((struct afio_reg_map *)0x40010000)
typedef struct afio_reg_map {
    u32 EVCR;    /**< Event control register.  */
    u32 MAPR;    /**< AF remap and debug I/O configuration register. */
     u32 EXTICR1; /**< External interrupt configuration register 1. */
     u32 EXTICR2; /**< External interrupt configuration register 2. */
     u32 EXTICR3; /**< External interrupt configuration register 3. */
     u32 EXTICR4; /**< External interrupt configuration register 4. */
     u32 MAPR2;   /**<
                          * AF remap and debug I/O configuration register 2. */
} afio_reg_map;
typedef enum afio_debug_cfg {
    /** Full Serial Wire and JTAG debug */
    AFIO_DEBUG_FULL_SWJ          = AFIO_MAPR_SWJ_CFG_FULL_SWJ,
    /** Full Serial Wire and JTAG, but no NJTRST. */
    AFIO_DEBUG_FULL_SWJ_NO_NJRST = AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_NJRST,
    /** Serial Wire debug only (JTAG-DP disabled, SW-DP enabled) */
    AFIO_DEBUG_SW_ONLY           = AFIO_MAPR_SWJ_CFG_NO_JTAG_SW,
    /** No debug; all JTAG and SW pins are free for use as GPIOs. */
    AFIO_DEBUG_NONE              = AFIO_MAPR_SWJ_CFG_NO_JTAG_NO_SW,
} afio_debug_cfg;

static inline void afio_cfg_debug_ports(afio_debug_cfg config) {
     u32 *mapr = &AFIO_BASE->MAPR;
    *mapr = (*mapr & ~AFIO_MAPR_SWJ_CFG) | config;
}
//afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY );



#endif /* RCC_PRIVATE_H_ */
