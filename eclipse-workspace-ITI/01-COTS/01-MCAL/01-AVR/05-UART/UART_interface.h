/*
 * UART_interface.h
 *
 *  Created on: Apr 25, 2019
 *      Author: Hanna Nabil
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidIntialize(void);
void UART_TransmitData(u8 Data);
u8 UART_ReceiveData(void);
void UART_TransmitString(u8 *arr);

#endif /* UART_INTERFACE_H_ */
