/*
 * timer.c
 *
 * Created: 8/11/2024 4:06:22 PM
 *  Author: abdullah
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_MACROS.h"

void timer_CTC_init_interrupt()
{
	//Select ctc mode
	SET_BIT(TCCR0,WGM01);
	//select timer clk
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// load a value in ocr0
	OCR0=80;
	//enable interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

//generating signal in oc0 (PB3) pin in CTC mode 
void timer_wave_NPWM (void)
{
	// set OC0 as output pin
	SET_BIT(DDRB,3);
	// choose CTC mode
	SET_BIT(TCCR0,WGM01);
	//Load value in OCR0
	OCR0=64;
	// select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//toggle OC0 on compare match
	SET_BIT(TCCR0,COM00);
}
// generate PWM signal with specific duty cycle
void timer_wave_FASTPWM (void)
{
	// set OC0 as output pin
	SET_BIT(DDRB,3);
	// choose fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//Load value in OCR0
	OCR0=64;		 //duty cycle=25%
	// select timer clock, prescalar=1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//choose inverting mode
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

void timer_wave_phasecorrect_PWM (void)
{
	// set OC0 as output pin
	SET_BIT(DDRB,3);
	// choose fast PWM mode
	SET_BIT(TCCR0,WGM00); 
	//Load value in OCR0
	OCR0=64;		 //duty cycle=25%
	//select timer clock, prescalar=1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//choose mode
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);	
}