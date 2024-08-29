/*
 * LED.c
 *
 * Created: 5/6/2024 11:13:55 AM
 *  Author: FARAH
 */ 
#include "DIO.h"
//make the led in this port output pin
void LED_INIT(unsigned char portname,unsigned char pinnumber)
{
	DIO_SETPINDIR(portname,pinnumber,1);
}
//write on this on logic high
void LED_ON(unsigned char portname,unsigned char pinnumber)
{
	DIO_WRITE(portname,pinnumber,1);
}
//write on this on logic low
void LED_OFF(unsigned char portname,unsigned char pinnumber)
{
	DIO_WRITE(portname,pinnumber,0);
}
//TOGGLE the output of the led
void LED_TOGGLE(unsigned char portname,unsigned char pinnumber)
{
	DIO_togglepin(portname,pinnumber);
}
unsigned char LED_READ_STATUS(unsigned char portname,unsigned char pinnumber)
{
	return DIO_readpin(portname,pinnumber);
}
void LED_set_port_direction(unsigned char portname,unsigned char direction)
{
	DIO_set_port_direction(portname,direction);
}
void LED_toggle_port(unsigned char portname)
{
	DIO_toggle_port(portname);
}