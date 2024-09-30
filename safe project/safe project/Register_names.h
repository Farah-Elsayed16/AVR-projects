/*
 * avr.h
 *
 * Created: 7/8/2024 1:55:20 AM
 *  Author: farah
 */ 


#ifndef AVR_H_
#define AVR_H_

#define EEARL *(volatile unsigned char*)(0x3E)
#define EEARH *(volatile unsigned char*)(0x3F)
#define EEDR  *(volatile unsigned char*)(0x3D)
#define EECR  *(volatile unsigned char*)(0x3C)
#define EERE  0
#define EEWE  1
#define EEMWE 2

#endif /* AVR_H_ */