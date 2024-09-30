/*
 * timer.c
 *
 * Created: 8/11/2024 4:06:22 PM
 *  Author: Farah
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

void timer2_overflow_init_interrupt()
{
	//select timer clk
	SET_BIT(ASSR,AS2);
	//select prescalar
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	//enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);	
}

void timer1_wave_fastPWM(double value)
{
	/* set OC0 as output pin */
	SET_BIT(DDRD,5);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS11);
	/* load a value in OCR1A,ICR1 */
	ICR1=19999;
	OCR1A=(value*1000)-1;
}