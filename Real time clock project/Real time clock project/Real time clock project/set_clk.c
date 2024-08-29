/*
 * set_clk.c
 *
 * Created: 8/24/2024 5:18:01 PM
 *  Author: Farah
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
extern volatile unsigned char counter_seconds;
extern unsigned char counter_minutes,counter_hours,reading,first_digit,second_digit;

void set_clk ()
{
	_delay_ms(300);
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("Set hour:--");
	do
	{
		second_digit=keybad_check_press();
	} while (second_digit == 0XFF);
	lCD_MOVE_CURSOR(1,10);
	LCD_SEND_CHAR(second_digit);
	_delay_ms(300);
	do
	{
		first_digit=keybad_check_press();
	} while (first_digit == 0XFF);
	lCD_MOVE_CURSOR(1,11);
	LCD_SEND_CHAR(first_digit);
	counter_hours=((second_digit-48)*10)+(first_digit-48);
	second_digit=0xff;
	first_digit=0xff;
	_delay_ms(300);
	
	
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("Set minutes:--");
	do
	{
		second_digit=keybad_check_press();
	} while (second_digit == 0XFF);
	lCD_MOVE_CURSOR(1,13);
	LCD_SEND_CHAR(second_digit);
	_delay_ms(300);
	do
	{
		first_digit=keybad_check_press();
	} while (first_digit == 0XFF);
	lCD_MOVE_CURSOR(1,14);
	LCD_SEND_CHAR(first_digit);
	counter_minutes=((second_digit-48)*10)+(first_digit-48);
	second_digit=0xff;
	first_digit=0xff;
	
	
	_delay_ms(500);
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("Set seconds:--");
	do
	{
		second_digit=keybad_check_press();
	} while (second_digit == 0XFF);
	lCD_MOVE_CURSOR(1,13);
	LCD_SEND_CHAR(second_digit);
	_delay_ms(300);
	do
	{
		first_digit=keybad_check_press();
	} while (first_digit == 0XFF);
	lCD_MOVE_CURSOR(1,14);
	LCD_SEND_CHAR(first_digit);
	counter_seconds=((second_digit-48)*10)+(first_digit-48);
	second_digit=0xff;
	first_digit=0xff;
	_delay_ms(500);
	
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("press 1/set clk ");
	lCD_MOVE_CURSOR(2,6);
	LCD_SEND_STRING("2/set alarm");
}