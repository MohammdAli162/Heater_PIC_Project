/* 
 * File:   Timer_1.h
 * Author: smart
 *
 * Created on 30 ?????, 2020, 04:22 ?
 */

#ifndef TIMER_1_H
#define	TIMER_1_H
#include <xc.h>
#include<pic.h>
#define TIMER1_ON()  (T1CON |= ( 1 << 0))//ENABLE TIMER
#define TIMER1_OFF() (T1CON &= ~( 1 << 0))//DESAPLE TIMER
#define TIMER0_ON()  (INTCON |= ( 1 << 5))//ENABLE TIMER
#define TIMER0_OFF() (INTCON &= ~( 1 << 5))//DISAPLE TIMER
void Timer1_init(void);
//25 MS
#define TIMER1_H 0XF3
#define TIMER1_L 0XCB
#define Timer1_Reload()  TMR1L = TIMER1_L;\
                         TMR1H = TIMER1_H
                                 
void Timer0_init(void);
void Timer0_Reload(void);
#endif	/* TIMER_1_H */

