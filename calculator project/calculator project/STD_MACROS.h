/*
 * IncFile1.h
 *
 * Created: 5/3/2024 12:46:58 AM
 *  Author: farah
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


#define SET_BIT(reg,bit)      reg|=(1<<bit)
#define CLEAR_BIT(reg,bit)      reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit)   reg^=(1<<bit)
#define READ_BIT(reg,bit)     ((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)         reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))



#endif /* INCFILE1_H_ */