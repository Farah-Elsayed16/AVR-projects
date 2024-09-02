/*
 * traffic_light.c
 *
 * Created: 8/15/2024 12:53:09 AM
 *  Author: Farah
 */ 

#include "LED.h"
#include "LCD.h"
#include "timer.h"
#include "Counter_lcd.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned short counter;
unsigned char red_counter=7,yellow_counter=5,green_counter=10,counter1;
/*
int main(void)
{
	LCD_INIT();
	timer_CTC_init_interrupt();
	LED_INIT('d',0);
	LED_INIT('d',1);
	LED_INIT('d',2);

    while(1)
    {
		LCD_SEND_STRING("remaining 10 sec");
		LED_ON('d',0);
		green_counter=10;
		while(green_counter > 0)
		{
			if(counter >= 100)
			{
				green_counter--;
				lCD_MOVE_CURSOR(1,11);
				LCD_SEND_CHAR(green_counter+48);
				LCD_SEND_CHAR(0X20);
				counter=0;
			}
		}
		_delay_ms(500);
		LCD_CLEAR_SCREEN();
		LCD_SEND_STRING("remaining 5 sec");
		LED_OFF('d',0);
		LED_ON('d',1);
		yellow_counter=5;
		while(yellow_counter > 0)
		{
			if(counter >= 100)
			{
				yellow_counter--;
				lCD_MOVE_CURSOR(1,11);
				LCD_SEND_CHAR(yellow_counter+48);
				LCD_SEND_CHAR(0X20);
				counter=0;
			}
		}
		_delay_ms(500);
		LCD_CLEAR_SCREEN();
		LCD_SEND_STRING("remaining 7 sec");
		LED_OFF('d',1);
		LED_ON('d',2);
		red_counter=7;
		while(red_counter > 0)
		{
			if(counter >= 100)
			{
				red_counter--;
				lCD_MOVE_CURSOR(1,11);
				LCD_SEND_CHAR(red_counter+48);
				LCD_SEND_CHAR(0X20);
				counter=0;
			}
		}
		
    }
}
*/


//another way to implement this project
int main()
{
	LCD_INIT();
	timer_CTC_init_interrupt();
	LED_INIT('d',0);
	LED_INIT('d',1);
	LED_INIT('d',2);
	while(1)
	{
		
		LCD_SEND_STRING("remaining 10 sec");
		LED_ON('d',0);
		counter1=10;
			count_down(&counter1,&counter);
		counter1=5;
		_delay_ms(500);
		LCD_CLEAR_SCREEN();
		LCD_SEND_STRING("remaining 5 sec");
		LED_OFF('d',0);
		LED_ON('d',1);
			count_down(&counter1,&counter);
		counter1=7;
		_delay_ms(500);
		LCD_CLEAR_SCREEN();
		LCD_SEND_STRING("remaining 7 sec");
		LED_OFF('d',1);
		LED_ON('d',2);
			count_down(&counter1,&counter);	
		_delay_ms(500);
		LCD_CLEAR_SCREEN();
	}	
	
}


ISR(TIMER0_COMP_vect)
{
	counter++;
}

