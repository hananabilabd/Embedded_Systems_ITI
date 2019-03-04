/*
 * SSD_interface.h
 *
 *  Created on: Feb 13, 2019
 *      Author: Hanna Nabil
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_U8_COMMON_CATHODE  0
#define SSD_U8_COMMON_ANODE    1
#define SSD_U8_STATE_HIGH 1
#define SSD_U8_STATE_LOW  0
u8 SSD_u8DisplayON(u8 Copy_u8ID);
u8 SSD_u8DisplayOFF(u8 Copy_u8ID);
u8 SSD_u8WriteNumber(u8 Copy_u8ID,u8 Copy_u8Number);
u8 SSD_u8WriteDashChar(u8 Copy_u8ID,u8 Copy_u8DashChar);

#endif /* SSD_INTERFACE_H_ */
