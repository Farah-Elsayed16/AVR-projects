/*
 * buzzer.h
 *
 * Created: 6/23/2024 8:02:46 PM
 *  Author: abdullah
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

void buzzer_INIT(unsigned char portname,unsigned char pinnumber);
void buzzer_ON(unsigned char portname,unsigned char pinnumber);
void buzzer_OFF(unsigned char portname,unsigned char pinnumber);
void buzzer_TOGGLE(unsigned char portname,unsigned char pinnumber);
unsigned char buzzer_READ_STATUS(unsigned char portname,unsigned char pinnumber);
void buzzer_set_port_direction(unsigned char portname,unsigned char pinnumber);
void buzzer_toggle_port(unsigned char portname);




#endif /* BUZZER_H_ */