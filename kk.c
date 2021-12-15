/*
 * kk.c
 *
 *  Created on: Oct 23, 2021
 *      Author: Mohammed Emad
 */
#include"keypad.h"
#include"DIO_DD.h"
#include"LCD.h"
#include<stdio.h>
int main(void)
{ u8 result;
	LCD_INIT();
 KEYPAD_INIT();
 while(1)
 {
	 result=KEYPAD_GET_PRESSED_VALUE();
	 if(result!=255)
	 {
		 LCD_SEND_DATA(result);
	 }
 }
}

