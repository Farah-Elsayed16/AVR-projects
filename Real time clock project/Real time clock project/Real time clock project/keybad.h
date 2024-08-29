/*
 * keybad.h
 *
 * Created: 7/22/2024 8:47:58 PM
 *  Author: Farah
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#define keypad_port 'd'
#define unpressed 0XFF
void keybad_init();
char keybad_check_press();





#endif /* KEYBAD_H_ */