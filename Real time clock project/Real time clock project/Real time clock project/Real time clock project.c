/*
 * Real_time_clock_project.c
 *
 * Created: 8/18/2024 5:02:30 AM
 *  Author: Farah
 */ 

#include "7seg.h"
#include "keybad.h"
#include "LCD.h"
#include "button.h"
#include "timer.h"
#include "DIO.h"
#include "set_clk.h"
#include "LED.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned char counter_seconds,flag;
unsigned char counter_minutes,counter_hours,reading,first_digit,second_digit,end_alarm,x;
int main(void)
{
	LED_INIT('a',3);
	button_init('a',1);
	seven_segment_init('b');
	keybad_init();
	LCD_INIT();
	timer2_overflow_init_interrupt();
	DIO_SETPINDIR('c',0,1);
	DIO_SETPINDIR('c',1,1);
	DIO_SETPINDIR('c',2,1);
	DIO_SETPINDIR('c',3,1);
	DIO_SETPINDIR('c',4,1);
	DIO_SETPINDIR('c',5,1);
		LCD_SEND_STRING("press 1/set clk ");
		lCD_MOVE_CURSOR(2,6);
		LCD_SEND_STRING("2/set alarm");
    while(1)
    {
		reading=keybad_check_press();
		if(reading != 0XFF)
		{
			if(reading == '1')
			{
				TIMSK|=(1<<TOIE2);
				flag=0;
				set_clk();
			}
			else if(reading == '2')
			{
				TIMSK|=(1<<TOIE2);
				end_alarm=0;
				flag=1;
				set_clk();
			}
			else
			{
				_delay_ms(500);
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("Wrong Choice");
				_delay_ms(500);
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("press 1/set clk ");
				lCD_MOVE_CURSOR(2,6);
				LCD_SEND_STRING("2/set alarm");
			}
			
		}
				DIO_WRITE('c',0,0);
				DIO_WRITE('c',1,1);
				DIO_WRITE('c',2,1);
				DIO_WRITE('c',3,1);
				DIO_WRITE('c',4,1);
				DIO_WRITE('c',5,1);
				seven_segment_write('b',counter_seconds%10);
				_delay_ms(5);
				DIO_WRITE('c',0,1);
				DIO_WRITE('c',1,0);
				DIO_WRITE('c',2,1);
				DIO_WRITE('c',3,1);
				DIO_WRITE('c',4,1);
				DIO_WRITE('c',5,1);
				seven_segment_write('b',counter_seconds/10);
				_delay_ms(5);
				DIO_WRITE('c',0,1);
				DIO_WRITE('c',1,1);
				DIO_WRITE('c',2,0);
				DIO_WRITE('c',3,1);
				DIO_WRITE('c',4,1);
				DIO_WRITE('c',5,1);
				seven_segment_write('b',counter_minutes%10);
				_delay_ms(5);
				DIO_WRITE('c',0,1);
				DIO_WRITE('c',1,1);
				DIO_WRITE('c',2,1);
				DIO_WRITE('c',3,0);
				DIO_WRITE('c',4,1);
				DIO_WRITE('c',5,1);
				seven_segment_write('b',counter_minutes/10);
				_delay_ms(5);
				DIO_WRITE('c',0,1);
				DIO_WRITE('c',1,1);
				DIO_WRITE('c',2,1);
				DIO_WRITE('c',3,1);
				DIO_WRITE('c',4,0);
				DIO_WRITE('c',5,1);
				seven_segment_write('b',counter_hours%10);
				_delay_ms(5);
				DIO_WRITE('c',0,1);
				DIO_WRITE('c',1,1);
				DIO_WRITE('c',2,1);
				DIO_WRITE('c',3,1);
				DIO_WRITE('c',4,1);
				DIO_WRITE('c',5,0);
				seven_segment_write('b',counter_hours/10);
				_delay_ms(5);

			if(flag == 0)
			{
				if(counter_seconds >= 60)
				{
					counter_seconds=0;
					counter_minutes++;
				}
				if(counter_minutes >= 60)
				{
					counter_minutes=0;
					counter_hours++;
				}
				if(counter_hours == 24)
				{
					counter_hours=0;
				}
				
				if(button_read('a',1) == 1)
				{
					counter_seconds=counter_minutes=counter_hours=0;
				}	
			}
			else if(flag == 1 && end_alarm ==0 )
			{
				if(counter_seconds==0 && counter_minutes==0 && counter_hours==0 )
				{
					TIMSK&=(~(1<<TOIE2));
					/*LED_ON('a',3);
					_delay_ms(2000);
					LED_OFF('a',3);*/
					end_alarm=1;
					flag=0;
				}
				if(counter_seconds == 0)
				{
					if(counter_minutes != 0)
					{
						counter_seconds=60;
						counter_minutes--;
					}
				}
				if(counter_minutes == 0)
				{
					if(counter_hours != 0 && counter_seconds== 0)
					{
						counter_minutes=60;
						counter_hours--;
					}
				}
			}
			while(end_alarm == 1)
			{
				x=button_read('a',1);
				if(x == 1)
				{
					LED_OFF('a',3);
					end_alarm=0;
					break;
				}
				else
				{
					LED_TOGGLE('a',3);
					_delay_ms(100);
				}
			}					
		}    
}


ISR(TIMER2_OVF_vect)
{
	if(flag == 0)
	{
		counter_seconds++;
	}
	else if(flag == 1)
	{
		counter_seconds--;
	}
}