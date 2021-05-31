#include "Timer_1.h"
//2 m sec

#define TIMER0 200



void Timer1_init()
{
T1CON |= (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2) |(1<<1); //8 PRESCALER
T1CON &= ~(1 << 1);//
Timer1_Reload();
PIE1 |= (1 << 0);//ENABLE INTERRUPT
}


