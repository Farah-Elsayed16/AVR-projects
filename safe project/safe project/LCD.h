/*
 * LCD.h
 *
 * Created: 7/19/2024 10:34:16 AM
 *  Author: Farah
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD_CONFIGURATION.h"

#if defined eight_bit_mode
#define RS				 0
#define R_W				 1
#define EN				 2
#define eight_bit			 0x38
#elif defined four_bit_mode
#define RS				 6
#define R_W				 5
#define EN				 4
#define four_bit			 0x28
//#define HIGH_NIPPLE
//#define start_pin   2
#define LOW_NIPPLE
#endif

#define port_data		'A'  //MC port that connected to LCD data pins  D0-D7 if 8 bit mode or D4-D7 if 4 bit mode
#define port_control	'A'  //MC port that connected to LCD control pins

#define clear_screen		 0X01
#define Return_Home		     0X02
#define Entry_Mode			 0X06
#define Display_on_Cursor_on 0X0E
#define Display_on_Cursor_off 0X0C


void LCD_INIT ();
void LCD_SEND_CHAR (unsigned char data);
void LCD_SEND_CMD (unsigned char cmd);
void LCD_CLEAR_SCREEN();
void LCD_Return_home();
void enable();
void lCD_MOVE_CURSOR (unsigned char row,unsigned char column);
void LCD_SEND_STRING (const char* ptr);

#endif /* LCD_H_ */