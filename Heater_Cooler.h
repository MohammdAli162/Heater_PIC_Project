/* 
 * File:   Heater_Cooler.h
 * Author: smart
 *
 * Created on 01 ?????, 2020, 08:21 ?
 */

#ifndef HEATER_COOLER_H
#define	HEATER_COOLER_H
#define TEMP_MAX 75
#define TEMP_MIN 35
#define INCREASE 1
#define DECREASE 0
#define ON 1
#define OFF 0
#define NORMAL_MODE  0
#define TEMP_SET_MODE  1
#define UP_BUTTON (1<<3)
#define DOWN_BUTTON (1<<4)
#define ON_LED (1<<5)
#define HEATING_L  (1<<6) 
typedef struct {
    char COOLING_SYS;
    char HEATING_SYS;
    char HEATING_COUNT;  
    char Sys_mode;
    char Sys_Count;
}system_T ;   
void SYSTEM_CONTROL(system_T *system,int *T,int *Tn);
void UP_DOWN_B(char MODE,system_T *system,int *Temp);
void Cooling_Sys(system_T *sys);
void Heating_Sys(system_T *sys);
void System_init(void);
void Temp_Change(char choose ,int * TempP);
#endif	/* HEATER_COOLER_H */

