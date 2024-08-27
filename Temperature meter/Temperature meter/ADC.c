/*
 * ADC.c
 *
 * Created: 8/1/2024 3:05:46 PM
 *  Author: abdullah
 */ 


#include "ADC.h"

void ADC_INIT ()
{
	//SET_BIT(ADMUX,REFS0); //configre vref = AVCC
	  //configre vref = 2.56 (internal vref)
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	
	SET_BIT(ADCSRA,ADEN); //enable ADC
	SET_BIT(ADCSRA,ADPS1); //set clk of ADC
	SET_BIT(ADCSRA,ADPS2);
}

unsigned short ADC_READ()
{
	unsigned short read_value;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)== 0);
	SET_BIT(ADCSRA,ADIF);
	read_value=ADCL;
	read_value|=(ADCH<<8);
	return read_value;
}