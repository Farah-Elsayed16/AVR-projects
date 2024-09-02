/*
 * simple_game.c
 *
 * Created: 8/14/2024 2:33:27 PM
 *  Author: Farah
 */ 

#include "LCD.h"
#include "keybad.h"
#include "timer.h"
#include <avr/interrupt.h>
volatile unsigned short counter;
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	unsigned char x;
	LCD_INIT();
	keybad_init();
	timer_CTC_init_interrupt();
	LCD_SEND_STRING("3+?=8");
		do
		{
			x=keybad_check_press();
			if(counter >= 1000)
			{
				LCD_CLEAR_SCREEN();
				lCD_MOVE_CURSOR(2,4);
				LCD_SEND_STRING("Time Over");
				break;
			}
		} while (x == 0XFF);
		lCD_MOVE_CURSOR(2,4);
		if(x == '5')
		{
			LCD_SEND_STRING("Well done");
		}
		if(x != '5' && x != 0XFF)
		{
			LCD_SEND_STRING("Wrong answer");
		}
		_delay_ms(2000);
		LCD_CLEAR_SCREEN();		
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}