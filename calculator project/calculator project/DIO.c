/*
 * DIO.c
 *
 * Created: 5/3/2024 12:44:45 AM
 *  Author: FARAH
 */ 
#include "STD_MACROS.H"
#include <avr/io.h>
//access DDR register to make the pins input or output
// Function Description:Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
void DIO_SETPINDIR (unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case'A':
		case'a':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);   //set the pin whose its number given by (pinnumber) in DDR register as output
		}
		if(direction==0)
		{
			CLEAR_BIT(DDRA,pinnumber);  //set the pin whose its number given by (pinnumber) in DDR register as input
		}
		break;
		case'B':
		case'b':
		if(direction==1)
		{
			SET_BIT(DDRB,pinnumber);  
		}
		if(direction==0)
		{
			CLEAR_BIT(DDRB,pinnumber);
		}
		break;
		case'C':
		case'c':
		if(direction==1)
		{
			SET_BIT(DDRC,pinnumber);   
		}
		if(direction==0)
		{
			CLEAR_BIT(DDRC,pinnumber);
		}
		break;
		case'D':
		case'd':
		if(direction==1)
		{
			SET_BIT(DDRD,pinnumber);   
		}
		if(direction==0)
		{
			CLEAR_BIT(DDRD,pinnumber);
		}
		break;
	}
}
// access PORT register to write the output value that will be on the output pin 
//Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
void DIO_WRITE (unsigned char portname,unsigned char pinnumber, unsigned char outputvalue)
{
	switch(portname)
	{
		case 'A':
		case'a':
		if(outputvalue == 1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLEAR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case'b':
		if(outputvalue == 1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLEAR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case'c':
		if(outputvalue == 1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLEAR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case'd':
		if(outputvalue == 1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLEAR_BIT(PORTD,pinnumber);
		}
		break;
	}
}		
// access PORT register to toggle the output value that appear in the output pin
//	Function Description : Reverse the value of the given pin in the given port.
void DIO_togglepin(unsigned char portname,unsigned char pinnumber)
{
			switch(portname)
			{
				case 'A':
				case 'a':
				TOGGLE_BIT(PORTA,pinnumber);
				break;
				
				case 'B':
				case 'b':
				TOGGLE_BIT(PORTB,pinnumber);
				break;
				
				case 'C':
				case 'c':
				TOGGLE_BIT(PORTC,pinnumber);
				break;
				
				case 'D':
				case 'd':
				TOGGLE_BIT(PORTD,pinnumber);
				break;
			}
}
//Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
//access pin register to know the reading of pin reg in case it is input pin to know the value of the voltage that it received from the input device connected to it
unsigned char DIO_readpin(unsigned char portname,unsigned char bitnumber)
{
	unsigned char reading=0;
	switch(portname)
	{
		case'A':
		case'a':
		reading= READ_BIT(PINA,bitnumber);
		break;
		
		case'B':
		case'b':
		reading= READ_BIT(PINB,bitnumber);
		break;
		
		case'C':
		case'c':
		reading= READ_BIT(PINC,bitnumber);
		break;
		
		case'D':
		case'd':
		reading= READ_BIT(PIND,bitnumber);
		break;	
	}
	return reading;	
}
//	Function Description : set the direction of whole port .
//to set the direction of the whole port (all pins of the port will be input or output )
void DIO_set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case'A':
		case'a':
		DDRA=direction;
		break;
		case'B':
		case'b':
		DDRB=direction;
		break;
		case'C':
		case'c':
		DDRC=direction;
		break;
		case'D':
		case'd':
		DDRD=direction;
		break;
	}
}
//	Function Description : Write the value to all port pins.
void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case'A':
		case'a':
		PORTA=portvalue;
		break;
		case'B':
		case'b':
		PORTB=portvalue;
		break;
		case'C':
		case'c':
		PORTC=portvalue;
		break;
		case'D':
		case'd':
		PORTD=portvalue;
		break;
	}	
}
//	Function Description : read the value of the port .
unsigned char DIO_read_port(unsigned char portname)
{
	unsigned char reading_port=0;
	switch(portname)
	{
		case'A':
		case'a':
		reading_port=PINA;
		break;
		case'B':
		case'b':
		reading_port=PINB;
		break;
		case'C':
		case'c':
		reading_port=PINC;
		break;
		case'D':
		case'd':
		reading_port=PIND;
		break;
		
	}
	return reading_port;
}
//	Function Description : toggle the value of the port that stored in PORT reg if the led connected to output pin will exit to it logic 0 instead of logic 1 .
void DIO_toggle_port(unsigned char portname)
{
	switch(portname)
	{
		case'A':
		case'a':
		PORTA= ~PORTA;   //PORTA^=0xff;
		break;
		case'B':
		case'b':
		PORTB =~PORTB;   
		break;
		case'C':
		case'c':
		PORTC= ~PORTC;   
		break;
		case'D':
		case'd':
		PORTD= ~PORTD;   
		break;	
	}
}
void DIO_CONNECT_PULLUP(unsigned char portname,unsigned char pinnumber,unsigned char connect_pullup)
{
		DIO_WRITE(portname,pinnumber,connect_pullup);
}

void DIO_WRITE_LOW_NIBBLE(unsigned char portname,unsigned char value)
{
	unsigned char i;
	for(i=0;i<=3;i++)
	{
		DIO_WRITE(portname,i,READ_BIT(value,i));
	}
}

void DIO_WRITE_HIGH_NIBBLE(unsigned char portname,unsigned char value)
{
	unsigned char i;
	for(i=4;i<=7;i++)
	{
		DIO_WRITE(portname,i,READ_BIT(value,i-4));
	}
}

void DIO_WRITE_NIBBLE(unsigned char portname,unsigned char startpin,unsigned char value)
{
	unsigned char i;
	for(i=0;i<=3;i++)
	{
		DIO_WRITE(portname,startpin,READ_BIT(value,i));
		startpin++;
	}
}

void DIO_SET_DIR_NIPPLE(unsigned char portname,unsigned char startpin,unsigned char direction)
{
	unsigned char i;
	for(i=0;i<=3;i++)
	{
		DIO_SETPINDIR(portname,startpin,READ_BIT(direction,i));
		startpin++;
	}	
}
