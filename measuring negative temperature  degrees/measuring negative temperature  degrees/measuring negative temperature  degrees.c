/*
 * measuring_negative_temperature__degrees.c
 *
 * Created: 8/13/2024 11:52:15 PM
 *  Author: Farah
 */ 


#include "LCD.h"
#include "ADC.h"
int main(void)
{
	unsigned short temperature,voltage;
	LCD_INIT();
	ADC_INIT();
	LCD_SEND_STRING("Temperature=");
    while(1)
    {
		voltage=2.5*ADC_READ();
		if((voltage-1000.0) >= 0)    //voltage - offset added
		{
			temperature=(voltage-1000)/10;
			lCD_MOVE_CURSOR(1,13);
			if(temperature < 10)
			{
				LCD_SEND_CHAR(temperature+48);
			}
			else if(temperature < 100 )
			{
				LCD_SEND_CHAR((temperature/10)+48);
				LCD_SEND_CHAR((temperature%10)+48);
			}
			else
			{
				LCD_SEND_CHAR((temperature/100)+48);
				LCD_SEND_CHAR(((temperature/10)%10)+48);
				LCD_SEND_CHAR((temperature%10)+48);
			}
			LCD_SEND_CHAR(0XDF);   // to write a degree on LCD
			LCD_SEND_CHAR('C');
			LCD_SEND_CHAR(0X20);	
		}			
		else
		{
			temperature=(1000-voltage)/10;
			lCD_MOVE_CURSOR(1,13);
			LCD_SEND_CHAR('-');
			if(temperature < 10)
			{
				LCD_SEND_CHAR(temperature+48);
			}
			else if(temperature < 100 )
			{
				LCD_SEND_CHAR((temperature/10)+48);
				LCD_SEND_CHAR((temperature%10)+48);
			}
			LCD_SEND_CHAR(0XDF);   // to write a degree on LCD
			LCD_SEND_CHAR('C');
			LCD_SEND_CHAR(0X20);	
		}			
    }
}





