/*
 * EEPROM.c
 *
 * Created: 7/8/2024 1:07:56 AM
 *  Author: abdullah
 */ 

#include "Register_names.h"
#include "STD_MACROS.h"


void EEPROM_WRITE (unsigned short address , unsigned char data)
{
	//SET UP address register
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	//SET UP data register
	EEDR=data;
	//write logical 1 to EEMWE	
	SET_BIT(EECR,EEMWE);
	//START EEPROM to write by setting EEWE by logical 1
	SET_BIT(EECR,EEWE);
	//WAIT for compilation of write process
	while(READ_BIT(EECR,EEWE) == 1);
}

unsigned char EEPROM_READ (unsigned short address)
{
	//SET UP address register
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	//write logical 1 to EERE
	SET_BIT(EECR,EERE);
	//return data from data register
	return EEDR;
}