/*
 * NVIC_interface.h
 *
 *  Created on: Mar 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#define NVIC_WWDG                   0
#define NVIC_PVD                    1
#define NVIC_TAMPER                 2
#define NVIC_RTC                    3
#define NVIC_FLASH                  4
#define NVIC_RCC                    5
#define NVIC_EXTI0                 (u8) 6
#define NVIC_EXTI1                 (u8) 7
#define NVIC_EXTI2                  8
#define NVIC_EXTI3                  9
#define NVIC_EXTI4                  10
#define NVIC_DMA1_Channel1          11
#define NVIC_DMA1_Channel2          12
#define NVIC_DMA1_Channel3          13
#define NVIC_DMA1_Channel4          14
#define NVIC_DMA1_Channel5          15
#define NVIC_DMA1_Channel6          16
#define NVIC_DMA1_Channel7          17
#define NVIC_ADC1_2                 18
#define NVIC_USB_HP_CAN_            19
#define NVIC_USB_LP_CAN_            20
#define NVIC_RX0                    21
#define NVIC_CAN_RX1                22
#define NVIC_CAN_SCE                23
#define NVIC_EXTI9_5                24
#define NVIC_TIM1_BRK               25
#define NVIC_TIM1_UP                26
#define NVIC_TIM1_TRG_COM           27
#define NVIC_TIM1_CC                28
#define NVIC_TIM2                   29
#define NVIC_TIM3                   30
#define NVIC_TIM4                   31
#define NVIC_I2C1_EV                32
#define NVIC_I2C1_ER                33
#define NVIC_I2C2_EV                34
#define NVIC_I2C2_ER                35
#define NVIC_SPI1                   36
#define NVIC_SPI2                   37
#define NVIC_USART1                 38
#define NVIC_USART2                 39
#define NVIC_USART3                 40
#define NVIC_EXTI15_10              41
#define NVIC_RTCAlarm               42
#define NVIC_USBWakeup              43
#define NVIC_TIM8_BRK               44
#define NVIC_TIM8_UP                45
#define NVIC_TIM8_TRG_COM           46
#define NVIC_TIM8_CC                47
#define NVIC_ADC3                   48
#define NVIC_FSMC                   49
#define NVIC_SDIO                   50
#define NVIC_TIM5                   51
#define NVIC_SPI3					52
#define NVIC_UART4                   53
#define NVIC_UART5                   54
#define NVIC_TIM6                    55
#define NVIC_TIM7                    56
#define NVIC_DMA2_Channel1           57
#define NVIC_DMA2_Channel2           58
#define NVIC_DMA2_Channel3           59
#define NVIC_DMA2_Channel4_5         60



#define NVIC_GROUP_16_SUBPRIORITY_NONE_ID    0x05FA0300
#define NVIC_GROUP_8_SUBPRIORITY_2_ID        0x05FA0400
#define NVIC_GROUP_4_SUBPRIORITY_4_ID        0x05FA0500
#define NVIC_GROUP_2_SUBPRIORITY_8_ID        0x05FA0600
#define NVIC_GROUP_NONE_SUBPRIORITY_16_ID    0x05FA0700
#define NULL_ID                              0x00

void NVIC_voidEnable(u8 Copy_u8Index);
void NVIC_voidDisable(u8 Copy_u8Index);
void NVIC_voidSetPendingFlag(u8 Copy_u8Index);
void NVIC_voidclearPendingFlag(u8 Copy_u8Index);
u8 NVIC_u8setGroupsAndSubPriorities(u32 Copy_u32GroupAndSubPriorities_ID);
u8 NVIC_u8setPriority(u8 Copy_u8Index,u8 Copy_u8GroupPriority,u8 Copy_u8subGroupPriority);
static void writeOnRegister(u8 Copy_u8Index,u32 * Copy_Pu32register);
void NVIC_voidSetCallback(u8 Copy_u8InterruptIndex,void (*Copy_ptr)(void));




#endif /* NVIC_INTERFACE_H_ */
