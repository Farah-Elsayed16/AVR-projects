/*
 * CFile1.c
 *
 * Created: 5/6/2024 8:59:19 PM
 *  Author: Farah
 */ 

void button_init(unsigned char portname,unsigned char pinnumber)
{
	DIO_SETPINDIR(portname,pinnumber,0);
}

unsigned char button_read(unsigned char portname,unsigned char pinnumber)
{
	return DIO_readpin(portname,pinnumber);
}