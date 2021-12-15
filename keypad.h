/*
 * keypad.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Mohammed Emad
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include"DIO_DD.H"
#define KEYPAD_PORT PORTA_NUM
#define col1        0
#define col2        1
#define col3        2
#define row1        3
#define row2        4
#define row3        5
void KEYPAD_INIT(void);
u8 KEYPAD_GET_PRESSED_VALUE(void);
#endif /* KEYPAD_H_ */
