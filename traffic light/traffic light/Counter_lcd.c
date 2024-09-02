/*
 * Counter_lcd.c
 *
 * Created: 8/16/2024 12:11:21 AM
 *  Author: abdullah
 */ 


void count_down(char* counter1 , char* counter)
{
	while(*counter1 > 0)
	{
		if(*counter >= 100)
		{
			*counter=0;
			(*counter1)--;
			lCD_MOVE_CURSOR(1,11);
			LCD_SEND_CHAR(*counter1+48);
			LCD_SEND_CHAR(0X20);
		}
	}
}