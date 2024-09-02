/*
 * Electronic_voting_machine_project.c
 *
 * Created: 7/26/2024 2:18:24 PM
 *  Author: abdullah
 */ 


#include "button.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
unsigned char counter1,counter2,counter3,counter4,reset;
int main(void)
{

	LCD_INIT();
	lCD_MOVE_CURSOR(1,3);
	LCD_SEND_STRING("EVM Project");
	_delay_ms(2000);
	LCD_CLEAR_SCREEN();
	button_init('d',6);
	button_init('d',5);
	button_init('d',4);
	/*button_init('b',0);
	button_init('b',1);
	button_init('b',2);
	button_init('b',3);
	button_init('b',4);*/
	LCD_SEND_STRING("A=");
	lCD_MOVE_CURSOR(1,9);
	LCD_SEND_STRING("B=");
	lCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("C=");
	lCD_MOVE_CURSOR(2,9);
	LCD_SEND_STRING("D=");
	lCD_MOVE_CURSOR(1,3);
	LCD_SEND_CHAR(reset+48);
	lCD_MOVE_CURSOR(1,11);
	LCD_SEND_CHAR(reset+48);
	lCD_MOVE_CURSOR(2,3);
	LCD_SEND_CHAR(reset+48);
	lCD_MOVE_CURSOR(2,11);
	LCD_SEND_CHAR(reset+48);
    while(1)
    {
		if(button_read('d',6) == 1)
		{
			_delay_ms(150);
			counter1++;
			lCD_MOVE_CURSOR(1,3);
			if(counter1 < 10)
			{
				LCD_SEND_CHAR(counter1+48);
			}
			else
			{			
			LCD_SEND_CHAR((counter1/10)+48);
			LCD_SEND_CHAR((counter1%10)+48);
			}
		}		
		else if(button_read('d',5) == 1)
		{
			_delay_ms(150);
			counter2++;
			lCD_MOVE_CURSOR(1,11);
			if(counter2 < 10)
			{
				LCD_SEND_CHAR(counter2+48);
			}
			else
			{
				LCD_SEND_CHAR((counter2/10)+48);
				LCD_SEND_CHAR((counter2%10)+48);
			}	
		}
		/*
		else if(button_read('b',2) == 1)
		{
			_delay_ms(150);
			counter3++;
			lCD_MOVE_CURSOR(2,3);
			LCD_SEND_CHAR((counter3/10)+48);
			LCD_SEND_CHAR((counter3%10)+48);
		}
		
		else if(button_read('b',3) == 1)
		{
			_delay_ms(150);
			counter4++;
			lCD_MOVE_CURSOR(2,11);
			LCD_SEND_CHAR((counter4/10)+48);
			LCD_SEND_CHAR((counter4%10)+48);
		
		}*/
		else if(button_read('d',4) == 1)
		{
			_delay_ms(150);
			LCD_CLEAR_SCREEN();
			LCD_SEND_STRING("A=");
			lCD_MOVE_CURSOR(1,9);
			LCD_SEND_STRING("B=");
			lCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING("C=");
			lCD_MOVE_CURSOR(2,9);
			LCD_SEND_STRING("D=");
			lCD_MOVE_CURSOR(1,3);
			LCD_SEND_CHAR(reset+48);
			lCD_MOVE_CURSOR(1,11);
			LCD_SEND_CHAR(reset+48);
			lCD_MOVE_CURSOR(2,3);
			LCD_SEND_CHAR(reset+48);
			lCD_MOVE_CURSOR(2,11);
			LCD_SEND_CHAR(reset+48);
			counter1=counter2=counter3=counter4=0;
		}
			_delay_ms(150);	
}
}