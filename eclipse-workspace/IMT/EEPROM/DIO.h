/*
 * DIO.h
 *
 *  Created on: Nov 25, 2017
 *      Author: Mina Medhat
 */

#ifndef DIO_H_
#define DIO_H_
 void DIOSetPortDirection (u8 portnumber, u8 value);
void DIOSetPortValue (u8 portnumber, u8 value);
void DIOSetPinDirection (u8 portnumber,u8 Pinnumber,u8 value);
void DIOSetPinValue (u8 portnumber,u8 Pinnumber,u8 value);
u8 DIOGetPinValue (u8 portnumber , u8 Pinnumber);

#endif /* DIO_H_ */
