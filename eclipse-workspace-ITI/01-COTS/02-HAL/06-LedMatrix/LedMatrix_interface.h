/*
 * LedMatrix_interface.h
 *
 *  Created on: Mar 10, 2019
 *      Author: Hanna Nabil
 */

#ifndef LEDMATRIX_INTERFACE_H_
#define LEDMATRIX_INTERFACE_H_

#define LEDMATRIX_u8_ACTIVE_COL     0
#define LEDMATRIX_u8_ACTIVE_ROW     1
#define LEDMATRIX_u8_LOW            0
#define LEDMATRIX_u8_HIGH           1

void LedMatrix_voidInitialize(void);
u8 LedMatrix_u8draw(u8 arr[]);
u8 LedMatrix_u8drawForSeconds(u8 arr[],u8 seconds);

#endif /* LEDMATRIX_INTERFACE_H_ */
