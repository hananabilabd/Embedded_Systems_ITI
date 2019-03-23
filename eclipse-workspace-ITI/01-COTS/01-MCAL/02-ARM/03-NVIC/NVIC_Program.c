/*
 * NVIC_Program.c
 *
 *  Created on: Mar 21, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
static void (*PvoidCallback[13])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static u32 NVIC_u8GroupAndSubPrioritiesID_state =NULL_ID;

static void writeOnRegister(u8 Copy_u8Index,u32 * Copy_Pu32register){
	u8 Local_u8RegisterID,Local_u8BitID;
	Local_u8RegisterID=Copy_u8Index /32;
	Local_u8BitID=Copy_u8Index %32;
	Copy_Pu32register[Local_u8RegisterID]= (1<<Local_u8BitID);
}
void NVIC_voidEnable(u8 Copy_u8Index){
	writeOnRegister(Copy_u8Index,ISER);
}
void NVIC_voidDisable(u8 Copy_u8Index){
	writeOnRegister(Copy_u8Index,ICER);
}
void NVIC_voidSetPendingFlag(u8 Copy_u8Index){
	writeOnRegister(Copy_u8Index,ISPR);
}
void NVIC_voidclearPendingFlag(u8 Copy_u8Index){
	writeOnRegister(Copy_u8Index,ICPR);
}
u8 NVIC_u8setGroupsAndSubPriorities(u32 Copy_u32GroupAndSubPriorities_ID){
	u8 Local_u8ErrorState=0;
	NVIC_u8GroupAndSubPrioritiesID_state =Copy_u32GroupAndSubPriorities_ID;//update global static variable
	*AIRCR                                =Copy_u32GroupAndSubPriorities_ID; //assign values into Application interrupt and reset control register
	return Local_u8ErrorState;
}
u8 NVIC_u8setPriority(u8 Copy_u8InterruptIndex,u8 Copy_u8GroupPriority,u8 Copy_u8subGroupPriority){
	u8 Local_u8ErrorState=0;
	if (NVIC_u8GroupAndSubPrioritiesID_state != NULL_ID){
	switch(NVIC_u8GroupAndSubPrioritiesID_state){
	case NVIC_GROUP_16_SUBPRIORITY_NONE_ID:IPR[Copy_u8InterruptIndex]=Copy_u8GroupPriority<<4;break;
	case NVIC_GROUP_8_SUBPRIORITY_2_ID    :IPR[Copy_u8InterruptIndex]=Copy_u8GroupPriority<<5 |Copy_u8subGroupPriority<<4;break;
	case NVIC_GROUP_4_SUBPRIORITY_4_ID    :IPR[Copy_u8InterruptIndex]=Copy_u8GroupPriority<<6 |Copy_u8subGroupPriority<<4;break;
	case NVIC_GROUP_2_SUBPRIORITY_8_ID    :IPR[Copy_u8InterruptIndex]=Copy_u8GroupPriority<<7 |Copy_u8subGroupPriority<<4;break;
	case NVIC_GROUP_NONE_SUBPRIORITY_16_ID:IPR[Copy_u8InterruptIndex]=Copy_u8subGroupPriority<<4;break;
	default : Local_u8ErrorState=1;break;
	}
	}
return Local_u8ErrorState;
}
void NVIC_voidSetCallback(u8 Copy_u8InterruptIndex,void (*Copy_ptr)(void)){
	PvoidCallback[Copy_u8InterruptIndex] = Copy_ptr;
}

void EXTI0_IRQHandler(void){
	if (PvoidCallback[NVIC_EXTI0] !=NULL){
		PvoidCallback[NVIC_EXTI0]();//or (*PvoidCallback)();
	}
}
void EXTI1_IRQHandler(void){
	if (PvoidCallback[NVIC_EXTI1] !=NULL){
		PvoidCallback[NVIC_EXTI1]();//or (*PvoidCallback)();
	}
}
void EXTI2_IRQHandler(void){
	if (PvoidCallback[NVIC_EXTI2] !=NULL){
		PvoidCallback[NVIC_EXTI2]();//or (*PvoidCallback)();
	}
}
void EXTI3_IRQHandler(void){
	if (PvoidCallback[NVIC_EXTI3] !=NULL){
		PvoidCallback[NVIC_EXTI3]();//or (*PvoidCallback)();
	}
}
void EXTI4_IRQHandler(void){
	if (PvoidCallback[NVIC_EXTI4] !=NULL){
		PvoidCallback[NVIC_EXTI4]();//or (*PvoidCallback)();
	}
}

