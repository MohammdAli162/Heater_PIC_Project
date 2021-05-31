#ifndef CONFIG_877A_H
#define	CONFIG_877A_H

#ifdef	__cplusplus
extern "C" {
#endif

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000

#include <pic.h>
#include "SEG_7.h"
#include "Timer_1.h"
#include "MEMORY_EXT.h"
#include "LM35.h"
#include "Heater_Cooler.h" 


#define SENSOR_READ 4
#define TEMP_NO 10
#define SYS_TICK 25

system_T system;
void PERIPHERALS_INIT(void);
void PORTS_CONFIG(void);
#define GINT_E() (INTCON |=  (1<<7))
#define PINT_E() (INTCON |= (1<<6))
#define EXINT_E() (INTCON |= (1<<4)) 
#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_877A_H */
