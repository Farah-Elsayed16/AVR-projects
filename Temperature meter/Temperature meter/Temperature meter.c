/*
 * Temperature_meter.c
 *
 * Created: 8/11/2024 1:54:12 AM
 *  Author: abdullah
 */ 


#include "LCD.h"
#include "ADC.h"
int main(void)
{
	//float volt;
	unsigned char  temperature;
	LCD_INIT();
	ADC_INIT();
	LCD_SEND_STRING("Temperature=");
    while(1)
    {
		//if vref = Avcc
		//step = vref / # of levels = 5/ 1024 , volt(mv)=binary from ADC* STEP*1000 , temp=volt(mv)/10=volt*0.4882
		
		//volt = (5.0/1024)*ADC_READ()*1000;   //mv
		//temperature=volt/10;
		
		//temperature=0.48828*ADC_READ();
		
		
		// to increase the accuracy of measuring temperature we will reduse vref to reduse the step between levels , vref=2.56
		temperature=0.25*ADC_READ();
		
		
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
}