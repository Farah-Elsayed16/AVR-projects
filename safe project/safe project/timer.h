/*
 * timer.h
 *
 * Created: 8/11/2024 4:06:37 PM
 *  Author: Farah
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void timer_CTC_init_interrupt();
void timer_wave_NPWM (void);
void timer_wave_FASTPWM (void);
void timer1_wave_fastPWM(double value);

#endif /* TIMER_H_ */