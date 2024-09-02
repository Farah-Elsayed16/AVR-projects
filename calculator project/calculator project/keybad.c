/*
 * keybad.c
 *
 * Created: 7/22/2024 8:47:43 PM
 *  Author: abdullah
 */ 

#include"DIO.h"
#include "keybad.h"
unsigned char i;
void keybad_init()
{
	
	/*for(i=0;i<4;i++)
	{
		DIO_SETPINDIR(keypad_port,i,1);
		DIO_SETPINDIR(keypad_port,i+4,0);
		DIO_CONNECT_PULLUP(keypad_port,i+4,1);
	}*/
	
	DIO_SETPINDIR(keypad_port,0,1);
	DIO_SETPINDIR(keypad_port,1,1);
	DIO_SETPINDIR(keypad_port,2,1);
	DIO_SETPINDIR(keypad_port,3,1);
	DIO_SETPINDIR(keypad_port,4,0);
	DIO_SETPINDIR(keypad_port,5,0);
	DIO_SETPINDIR(keypad_port,6,0);
	DIO_SETPINDIR(keypad_port,7,0);
	DIO_CONNECT_PULLUP(keypad_port,4,1);
	DIO_CONNECT_PULLUP(keypad_port,5,1);
	DIO_CONNECT_PULLUP(keypad_port,6,1);
	DIO_CONNECT_PULLUP(keypad_port,7,1);	
	
}

 char keybad_check_press()
{
	//hardware
	char arr[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','/'},{'*','0','#','='}};
	//protus
	//char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	unsigned char row,coloumn,x;
	unsigned char return_val=unpressed;
	for(row=0;row<4;row++)
	{
		DIO_WRITE(keypad_port,0,1);
		DIO_WRITE(keypad_port,1,1);
		DIO_WRITE(keypad_port,2,1);
		DIO_WRITE(keypad_port,3,1);
		DIO_WRITE(keypad_port,row,0);
		for(coloumn=0;coloumn<4;coloumn++)
		{
			x=DIO_readpin(keypad_port,(coloumn+4));
			if(x == 0)
			{
				return_val=arr[row][coloumn];
				break;
			}
		}
		if(x==0)
		{
			break;
		}
	}
	return return_val;	
}