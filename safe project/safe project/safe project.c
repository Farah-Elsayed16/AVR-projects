/*
 * safe_project.c
 *
 * Created: 7/26/2024 6:29:53 PM
 *  Author: FARAH
 */ 

#include "LED.h"
#include "LCD.h"
#include "buzzer.h"
#include "keybad.h"
#include "EEPROM.h"
#include "servo.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define EEPROM_STATUS 0X19
#define EEPROM_PASSWORD_LOCATION1 0X20
#define EEPROM_PASSWORD_LOCATION2 0X21
#define EEPROM_PASSWORD_LOCATION3 0X22
#define EEPROM_PASSWORD_LOCATION4 0X23
unsigned char x,i,arr[4],max_trials=3,counter,flag=0;
int main(void)
{
	
	LCD_INIT();
	keybad_init();
	LED_INIT('b',1);
	LED_INIT('b',2);
	buzzer_INIT('b',0);
	if(EEPROM_READ(EEPROM_STATUS) != 1)
	{
	lCD_MOVE_CURSOR(1,3);
	LCD_SEND_STRING("SAFE PROJECT");
	_delay_ms(1000);
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("Set the password:");
	lCD_MOVE_CURSOR(2,1);
	
	while(counter<4)
	{
		x=keybad_check_press();
		if(x != 0xff)
		{
				_delay_ms(50);
				LCD_SEND_CHAR(x);
				_delay_ms(200);
				LCD_SEND_CMD(0X10);
				LCD_SEND_CHAR(0X2A);
				EEPROM_WRITE(EEPROM_PASSWORD_LOCATION1+counter,x);
				counter++;
		}
		_delay_ms(150);	
	}
	EEPROM_WRITE(EEPROM_STATUS,1);
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("password saved!!");
	_delay_ms(1000);
	LCD_CLEAR_SCREEN();
	}	
	else
	{
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("1/check password");
	lCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("2/edit password");
	_delay_ms(2000);
	LCD_CLEAR_SCREEN();
	LCD_SEND_STRING("1 or 2:");
	x=0xff;
	do 
	{
		x=keybad_check_press();
	} while (x == 0xff);
	LCD_SEND_CHAR(x);
	_delay_ms(1000);		
		switch(x)
		{
				case'1':
				while(flag == 0)
				{
				x=0xff;
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("check password:");
				lCD_MOVE_CURSOR(2,1);
				for(i=0;i<=3;i++)
				{
					do
					{
						x=keybad_check_press();
						
					} while (x == 0xff);
					arr[i]=x;
					_delay_ms(50);
					LCD_SEND_CHAR(x);
					_delay_ms(500);
					LCD_SEND_CMD(0X10);
					LCD_SEND_CHAR(0X2A);	
				}
				
			if(arr[0]==EEPROM_READ(EEPROM_PASSWORD_LOCATION1) && arr[1]==EEPROM_READ(EEPROM_PASSWORD_LOCATION2) && arr[2]==EEPROM_READ(EEPROM_PASSWORD_LOCATION3) && arr[3]==EEPROM_READ(EEPROM_PASSWORD_LOCATION4))
			{
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("Right password");
				lCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("Safe opened!!");
				LED_ON('b',2);
				_delay_ms(2000);
				LED_OFF('b',2);
				servo_degree(90);
				flag =1;
			}
			else
			{
				LCD_CLEAR_SCREEN();
				max_trials--;
				if(max_trials != 0)
				{
					
					LCD_SEND_STRING("wrong password");
					lCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("you have ");
					LCD_SEND_CHAR(max_trials+48);
					LCD_SEND_STRING("trials only");
					_delay_ms(1000);
					flag=0;
				}
				else
				{
					LCD_SEND_STRING("wrong password");
					lCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("Safe Closed");
					flag=1;
					LED_ON('b',1);
					buzzer_ON('b',0);
					_delay_ms(1000);
					LED_OFF('b',1);
					buzzer_OFF('b',0);
				}
			}
				}	
				break;		
			case'2':
				LCD_CLEAR_SCREEN();
				LCD_SEND_STRING("Enter Password:");
				lCD_MOVE_CURSOR(2,1);
				for(i=0;i<=3;i++)
				{
					do
					{
						x=keybad_check_press();
						
					} while (x == 0xff);
					arr[i]=x;
					_delay_ms(50);
					LCD_SEND_CHAR(x);
					_delay_ms(500);
					LCD_SEND_CMD(0X10);
					LCD_SEND_CHAR(0X2A);
				}
				
				if(arr[0]==EEPROM_READ(EEPROM_PASSWORD_LOCATION1) && arr[1]==EEPROM_READ(EEPROM_PASSWORD_LOCATION2) && arr[2]==EEPROM_READ(EEPROM_PASSWORD_LOCATION3) && arr[3]==EEPROM_READ(EEPROM_PASSWORD_LOCATION4))
				{
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("Right password");
					_delay_ms(1000);
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("EnterNewPassword:");
					lCD_MOVE_CURSOR(2,1);
					for(i=0;i<=3;i++)
					{
						do 
						{
							x=keybad_check_press();
						} while (x == 0xff);
						_delay_ms(50);
						LCD_SEND_CHAR(x);
						_delay_ms(500);
						LCD_SEND_CMD(0X10);
						LCD_SEND_CHAR(0X2A);
						EEPROM_WRITE(EEPROM_PASSWORD_LOCATION1+i,x);	   
					}
					_delay_ms(1000);
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("Password saved!!");
				}				
				else
				{
					_delay_ms(1000);
					LCD_CLEAR_SCREEN();
					LCD_SEND_STRING("Wrong password!!");
					lCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("Cant change it..");
					LED_ON('b',1);
					_delay_ms(1000);
					LED_OFF('b',1);
				}
			
			break;
			
		}	
				} 
}
