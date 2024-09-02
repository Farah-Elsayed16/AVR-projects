/*
 * calculator_project.c
 *
 * Created: 7/27/2024 3:18:47 PM
 *  Author: abdullah
 */ 


#include "keybad.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	keybad_init();
	LCD_INIT();
	signed char i;
	unsigned char operator,x[2],y[2],equal,on_off;
	int result, result1,result2;
	int number1,number2;
	lCD_MOVE_CURSOR(1,4);
	LCD_SEND_STRING("Calculator");
	_delay_ms(1000);
	LCD_CLEAR_SCREEN();
	while(1)
	{
		for(i=1;i>=0;i--)
		{
		do 
		{
		_delay_ms(150);
		 x[i]=keybad_check_press();
		} while (x[i] == 0xff);
			_delay_ms(150);
		   LCD_SEND_CHAR(x[i]);
		}		   
	if((x[0] == '+') || (x[0]=='-') || (x[0]=='*') || (x[0]=='/'))
	{
		operator=x[0];
		x[0]=x[1];
		x[1]='0';   //dont write it 0 only it must be a char as it subtracted then from 48
	}
	else
	{
		do
		{
			_delay_ms(150);
			operator=keybad_check_press();
			
		} while (operator == 0xff);
		_delay_ms(150);
		LCD_SEND_CHAR(operator);
	}
		
		for(i=1;i>=0;i--)
		{
	   do 
	   {
		   _delay_ms(150);
		    y[i]=keybad_check_press();
	   } while (y[i] == 0xff);
	   _delay_ms(150);
	   LCD_SEND_CHAR(y[i]);
	   }		
	   _delay_ms(500);
	   
	   if(y[0] == '=')
	   {
		   equal=y[0];
		   y[0]=y[1];
		   y[1]='0';
	   }
	  // LCD_SEND_STRING("=");
	  else
	  {
	   do
	   {
		   _delay_ms(150);
		   equal=keybad_check_press();
	   } while (equal == 0xff);
	   _delay_ms(150);
	   LCD_SEND_CHAR(equal);
	   }	   
	   number1=((x[1]-48)*10)+(x[0]-48);
	   number2=((y[1]-48)*10)+(y[0]-48);
	   
	   switch(operator)
	   {
		  case '+':
				result=number1+number2;
				LCD_SEND_CHAR((result/10)+48);
				LCD_SEND_CHAR((result%10)+48);
		  /*
				result=(x[1]-48)+(y[1]-48);
				result1=result%10;
				result2=(x[0]-48)+(y[0]-48)+(result/10);
				LCD_SEND_CHAR(result2+48);
				LCD_SEND_CHAR(result1+48);*/
				break;
				
		case '-':
				if(number1>number2)
				{
					result=number1-number2;
					LCD_SEND_CHAR((result/10)+48);
					LCD_SEND_CHAR((result%10)+48);
				}
				else
				{
					result=number2-number1;
					LCD_SEND_CHAR(0x2D);
					LCD_SEND_CHAR((result/10)+48);
					LCD_SEND_CHAR((result%10)+48);
					
				}
				break;
		case '*':
				result=number1*number2;
				if((result/100) == 0)
				{
					LCD_SEND_CHAR((result/10)+48);
					LCD_SEND_CHAR((result%10)+48);
				}
				else if((result/1000) == 0)
				{
					LCD_SEND_CHAR((result/100)+48);
					result1=result%100;
					LCD_SEND_CHAR((result1/10)+48);
					LCD_SEND_CHAR((result1%10)+48);
				}
				else
				{
					LCD_SEND_CHAR((result/1000)+48);
					result1=result%1000;
					LCD_SEND_CHAR((result1/100)+48);
					result2=result1%100;
					LCD_SEND_CHAR((result2/10)+48);
					LCD_SEND_CHAR((result2%10)+48);
				}
				break;
				
		case '/':
				result=number1/number2;
				LCD_SEND_CHAR((result/10)+48);
				LCD_SEND_CHAR((result%10)+48);
				break;
		default:
			lCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING("invaild operator");
			break;  
	   }
	   
	   //_delay_ms(3000);
	   //LCD_CLEAR_SCREEN();
	   
	   
	   do
	   {
		   _delay_ms(150);
		   on_off=keybad_check_press();
	   } while (on_off == 0xff);
	    _delay_ms(150);
	   if(on_off == '#')
	   {
		LCD_CLEAR_SCREEN();   
	   }
	   
	   }	   
	   		   		    
}