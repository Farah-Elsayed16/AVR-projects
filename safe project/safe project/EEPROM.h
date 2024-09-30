/*
 * EEPROM.h
 *
 * Created: 7/8/2024 1:08:19 AM
 *  Author: Farah
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_WRITE (unsigned short address , unsigned char data);
unsigned char EEPROM_READ (unsigned short address);



#endif /* EEPROM_H_ */