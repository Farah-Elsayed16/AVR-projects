/*
 * IncFile1.h
 *
 * Created: 5/3/2024 8:14:36 AM
 *  Author: abdullah
 */ 


// Function Description:Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
void DIO_SETPINDIR (unsigned char portname,unsigned char pinnumber,unsigned char direction);
//Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high)
void DIO_WRITE (unsigned char portname,unsigned char pinnumber, unsigned char outputvalue);
//	Function Description : Reverse the value of the given pin in the given port.
void DIO_togglepin(unsigned char portname,unsigned char pinnumber);
//Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
void DIO_readpin(unsigned char portname,unsigned char pinnumber);
//	Function Description : set the direction of whole port .
void DIO_set_port_direction(unsigned char portname,unsigned char direction);
//	Function Description : Write the value to all port pins.
void DIO_write_port(unsigned char portname,unsigned char portvalue);
//	Function Description : read the value of the port .
unsigned char DIO_read_port(unsigned char portname);
//	Function Description : toogle the value of the port that stored in PORT reg if the led connected to output pin will exit to it logic 0 instead of logic 1 .
void DIO_toggle_port(unsigned char portname);
void DIO_CONNECT_PULLUP(unsigned char portname,unsigned char pinnumber,unsigned char connect_pullup);
void DIO_WRITE_LOW_NIBBLE(unsigned char portname,unsigned char val);
void DIO_WRITE_HIGH_NIBBLE(unsigned char portname,unsigned char val);
void DIO_WRITE_NIBBLE(unsigned char portname,unsigned char startpin,unsigned char value);
void DIO_SET_DIR_NIPPLE(unsigned char portname,unsigned char startpin,unsigned char direction);





