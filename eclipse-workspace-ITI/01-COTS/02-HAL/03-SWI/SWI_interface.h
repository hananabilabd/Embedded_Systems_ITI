/*
 * SWI_interface.h
 *
 *  Created on: Feb 14, 2019
 *      Author: Hanna Nabil
 */

#ifndef SWI_INTERFACE_H_
#define SWI_INTERFACE_H_

#define SWI_U8_INTERNAL_PULL_UP   0
#define SWI_U8_EXTERNAL_PULL_UP   1
#define SWI_U8_EXTERNAL_PULL_DOWN 2
#define SWI_U8_KEY_PRESSED        1
#define SWI_U8_KEY_NOT_PRESSED    0
u8 SWI_u8GetSwitchState(u8 Copy_u8ID,u8* Pcopy_u8SwitchState);

#endif /* SWI_INTERFACE_H_ */
