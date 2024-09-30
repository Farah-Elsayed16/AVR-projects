/*
 * LED.h
 *
 * Created: 5/6/2024 11:14:12 AM
 *  Author: FARAH
 */ 


#ifndef LED_H_
#define LED_H_

void LED_INIT(unsigned char portname,unsigned char pinnumber);
void LED_ON(unsigned char portname,unsigned char pinnumber);
void LED_OFF(unsigned char portname,unsigned char pinnumber);
void LED_TOGGLE(unsigned char portname,unsigned char pinnumber);
unsigned char LED_READ_STATUS(unsigned char portname,unsigned char pinnumber);
void LED_set_port_direction(unsigned char portname,unsigned char pinnumber);
void LED_toggle_port(unsigned char portname);




#endif /* LED_H_ */