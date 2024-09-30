/*
 * CFile1.c
 *
 * Created: 6/23/2024 8:02:29 PM
 *  Author: abdullah
 */ 


#include "DIO.h"
//make the buzzer in this port output pin
void buzzer_INIT(unsigned char portname,unsigned char pinnumber)
{
	DIO_SETPINDIR(portname,pinnumber,1);
}
//write on this on logic high
void buzzer_ON(unsigned char portname,unsigned char pinnumber)
{
	DIO_WRITE(portname,pinnumber,1);
}
//write on this on logic low
void buzzer_OFF(unsigned char portname,unsigned char pinnumber)
{
	DIO_WRITE(portname,pinnumber,0);
}
//TOGGLE the output of the buzzer
void buzzer_TOGGLE(unsigned char portname,unsigned char pinnumber)
{
	DIO_togglepin(portname,pinnumber);
}
unsigned char buzzer_READ_STATUS(unsigned char portname,unsigned char pinnumber)
{
	return DIO_readpin(portname,pinnumber);
}
void buzzer_set_port_direction(unsigned char portname,unsigned char direction)
{
	DIO_set_port_direction(portname,direction);
}
void buzzer_toggle_port(unsigned char portname)
{
	DIO_toggle_port(portname);
}