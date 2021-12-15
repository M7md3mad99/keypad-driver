/*
 * keypad.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Mohammed Emad
 */

#include"keypad.h"
#include"DIO_DD.h"
#include"LCD.h"
#include<stdio.h>
u8 KEYPAD_VALUES[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void KEYPAD_INIT(void)
{
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,col3,output);
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,col2,output);
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,col1,output);
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,row1,input);
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,row2,input);
 DIO_SET_PIN_DIRECTION(KEYPAD_PORT,row3,input);
 DIO_SET_PIN_VALUE(KEYPAD_PORT,row1,pull_up);
 DIO_SET_PIN_VALUE(KEYPAD_PORT,row2,pull_up);
 DIO_SET_PIN_VALUE(KEYPAD_PORT,row3,pull_up);
}
u8 KEYPAD_GET_PRESSED_VALUE(void)
{
	u8 row_reading=0;
	u8 result=255;
 for(u8 col_counter=col1;col_counter<=col3;col_counter++)
 {
	 DIO_SET_PIN_VALUE(KEYPAD_PORT,col1,high);
     DIO_SET_PIN_VALUE(KEYPAD_PORT,col2,high);
	 DIO_SET_PIN_VALUE(KEYPAD_PORT,col3,high);
	 DIO_SET_PIN_VALUE(KEYPAD_PORT,col_counter,low);
 for(u8 row_counter =row1;row_counter<=row3;row_counter++)
 {
	 DIO_GET_PIN_VALUE(KEYPAD_PORT,row_counter,&row_reading);

	 if(row_reading == low)
	 {
		result=KEYPAD_VALUES[row_counter-row1][col_counter];
	 _delay_ms(200);
	 }
 }

 }

return result;
}
