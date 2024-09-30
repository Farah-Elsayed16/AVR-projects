/*
 * CFile1.c
 *
 * Created: 8/28/2024 10:21:21 PM
 *  Author: farah
 */ 

#include "timer.h"
void servo_degree(signed char degree)
{
	double value;
	if(-90<=degree<0)
	{
		value=((0.5/90)*(90+degree))+1;
	}
	else if(0<=degree<=90)
	{
		value=((0.5/90)*degree)+1.5;
	}
	timer1_wave_fastPWM(value);
}