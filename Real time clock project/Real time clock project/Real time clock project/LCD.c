/*
 * LCD.c
 *
 * Created: 7/19/2024 10:34:04 AM
 *  Author: FARH ELSAYED
 */ 

#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_INIT ()
{
	_delay_ms(200);
	#ifdef eight_bit_mode
	DIO_set_port_direction(port_data,0XFF);
	DIO_SETPINDIR(port_control,RS,1);
	DIO_SETPINDIR(port_control,EN,1);
	DIO_SETPINDIR(port_control,R_W,1);
	DIO_WRITE(port_control,R_W,0);
	LCD_SEND_CMD(eight_bit);   //function set
	LCD_SEND_CMD(Display_on_Cursor_on);  //display on/off control
	LCD_CLEAR_SCREEN();
	LCD_SEND_CMD(Entry_Mode);
	#else
	#if defined HIGH_NIPPLE
	DIO_SETPINDIR(port_data,4,1);
	DIO_SETPINDIR(port_data,5,1);
	DIO_SETPINDIR(port_data,6,1);
	DIO_SETPINDIR(port_data,7,1);
	#elif defined LOW_NIPPLE
	DIO_SETPINDIR(port_data,0,1);
	DIO_SETPINDIR(port_data,1,1);
	DIO_SETPINDIR(port_data,2,1);
	DIO_SETPINDIR(port_data,3,1);
	#else
	DIO_SET_DIR_NIPPLE(port_data,start_pin,0xFF);   //write 0 for low nipple ,write  4 for high nipple 
	#endif
	DIO_SETPINDIR(port_control,RS,1);
	DIO_SETPINDIR(port_control,EN,1);
	//DIO_SETPINDIR(port_control,R_W,1);
	//DIO_WRITE(port_control,R_W,0);
	LCD_Return_home();
	LCD_SEND_CMD(four_bit);
	LCD_SEND_CMD(Display_on_Cursor_on);
	LCD_CLEAR_SCREEN();
	LCD_SEND_CMD(Entry_Mode);
	#endif	
}

void LCD_SEND_CHAR (unsigned char data)
{
	#ifdef eight_bit_mode
	DIO_write_port(port_data,data);
	DIO_WRITE(port_control,RS,1);
	enable();
	#else 
	#ifdef HIGH_NIPPLE
	DIO_WRITE(port_control,RS,1);
	DIO_WRITE_HIGH_NIBBLE(port_data,data>>4);
	enable();
	DIO_WRITE_HIGH_NIBBLE(port_data,data);
	enable();
	#elif defined LOW_NIPPLE
	DIO_WRITE(port_control,RS,1);
	DIO_WRITE_LOW_NIBBLE(port_data,data>>4);
	enable();
	DIO_WRITE_LOW_NIBBLE(port_data,data);
	enable();
	#else
	DIO_WRITE(port_control,RS,1);
	DIO_WRITE_NIBBLE(port_data,start_pin,data>>4);
	enable();
	DIO_WRITE_NIBBLE(port_data,start_pin,data);
	enable();
	#endif
		
	#endif
}

void LCD_SEND_CMD (unsigned char cmd)
{
	#ifdef eight_bit_mode
	DIO_write_port(port_data,cmd);
	DIO_WRITE(port_control,RS,0);
	enable();
	_delay_ms(1);   // time that the lcd execute the cmd ,all cmds take 1ms expect clear screen and return home so i made them in separated functions
	#else 
	#if defined HIGH_NIPPLE
	DIO_WRITE(port_control,RS,0);
	DIO_WRITE_HIGH_NIBBLE(port_data,cmd>>4);
	enable();
	DIO_WRITE_HIGH_NIBBLE(port_data,cmd);
	enable();
	#elif defined LOW_NIPPLE
	DIO_WRITE(port_control,RS,0);
	DIO_WRITE_LOW_NIBBLE(port_data,cmd>>4);
	enable();
	DIO_WRITE_LOW_NIBBLE(port_data,cmd);
	enable();
	#else
	DIO_WRITE(port_control,RS,0);
	DIO_WRITE_NIBBLE(port_data,start_pin,cmd>>4);
	enable();
	DIO_WRITE_NIBBLE(port_data,start_pin,cmd);
	enable();
	_delay_ms(1);  //write this and if the cmd is clear screen or return home write after it delay 10 ms or do not write it in the function and after calling this function in main make a delay
	#endif
	#endif

}

void LCD_CLEAR_SCREEN()
{
	LCD_SEND_CMD(clear_screen);
	_delay_ms(10);
}

void LCD_Return_home()
{
	LCD_SEND_CMD(Return_Home);
	_delay_ms(10);
}

void lCD_MOVE_CURSOR (unsigned char row,unsigned char column)
{
	char cmd;
	if(row<1 || row>2 || column<1 || column>16)  // any invalid case
	{
		cmd=0X80;
	}
	else if(row == 1)
	{
		cmd=0X80+column-1;
	}
	else
	{
		cmd=0XC0+column-1;
	}
	LCD_SEND_CMD(cmd);
}

void LCD_SEND_STRING (const char* ptr)
{
	while((*ptr) != '\0')
	{
		LCD_SEND_CHAR(*ptr);
		ptr++;
		_delay_ms(1);
	}
}	
void enable()
{
	DIO_WRITE(port_control,EN,1);
	_delay_ms(2);
	DIO_WRITE(port_control,EN,0);
	_delay_ms(2);
}