/*
 * SWI_config.h
 *
 *  Created on: Feb 14, 2019
 *      Author: Hanna Nabil
 */

#ifndef SWI_CONFIG_H_
#define SWI_CONFIG_H_

#define SWI_U8_NB 2
u8 SWI_Au8ConnectedPins[SWI_U8_NB]={DIO_U8_PIN_0,DIO_U8_PIN_1};
u8 SWI_Au8ConnectionType[SWI_U8_NB]={SWI_U8_INTERNAL_PULL_UP,SWI_U8_INTERNAL_PULL_UP};

#endif /* SWI_CONFIG_H_ */
