/*
 * _7seg.c
 *
 * Created: 5/10/2024 1:32:34 PM
 *  Author: Farah
 */ 
#include "DIO.h"
#define CC
void seven_segment_init(unsigned char portname)
{
	DIO_set_port_direction(portname,0xFF);
}

void seven_segment_write(unsigned char portname,unsigned char number)
{
	#ifdef CC
	unsigned char arr[]={0X3F,0X06,0X5B,0x4f,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X77,0X7C,0X39,0X5E,0X79,0X71};
	#else
	unsigned char arr[]={~0X3F,~0X06,~0X5B,~0x4f,~0X66,~0X6D,~0X7D,~0X07,~0X7F,~0X6F,~0X77,~0X7C,~0X39,~0X5E,~0X79,~0X71};
	#endif
	DIO_write_port(portname,arr[number]);
}