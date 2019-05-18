/*
 * SSD_config.h
 *
 *  Created on: Feb 14, 2019
 *      Author: Khlood Amin
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

//#define SSD_u8_ENABLE_PIN						DIO_u8_PIN_7
#define SSD_u8_SSD_NB							4

#define SSD_DRIVER_U8_LED_TYPE   SSD_u8_COMMON_CATHOD
#define SSD_u8_COMMON_ANODE    DIO_u8_HIGH
#define SSD_u8_COMMON_CATHOD   DIO_u8_LOW  

u8 SSD_u8ASSDType [SSD_u8_SSD_NB] =        {	SSD_u8_COMMON_CATHOD ,
											    SSD_u8_COMMON_CATHOD ,
											    SSD_u8_COMMON_CATHOD ,
											    SSD_u8_COMMON_CATHOD } ;
										  
										  
u8 SSD_Au8SSDCommonPin[ SSD_u8_SSD_NB] = {	    DIO_u8_PIN_17 ,
											    DIO_u8_PIN_16 ,
											    DIO_u8_PIN_1 ,
											    DIO_u8_PIN_2 } ;
											
											
u8 SSD_Au8SSDPort[SSD_u8_SSD_NB ] =      {	    DIO_u8_PORT_A ,
												DIO_u8_PORT_B ,
												DIO_u8_PORT_A ,
												DIO_u8_PORT_A } ;
										   

 


#endif 
