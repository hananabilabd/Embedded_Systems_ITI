/*
 * SSD_interface.h
 *
 *  Created on: Feb 14, 2019
 *      Author: KHlood Amin
 */

#ifndef __SSD_INTERFACE_H_
#define __SSD_INTERFACE_H_



u8 SSD_u8DisplayOn(u8 Copy_u8SsdId);
u8 SSD_u8DisplayOff(u8 Copy_u8SsdId);
u8 SSD_u8WriteNumber(u8 Copy_u8SsdId, u8 Copy_SsdData);

#endif 
