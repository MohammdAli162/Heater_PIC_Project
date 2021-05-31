#include <xc.h>
#include "Heater_Cooler.h"
void Temp_Change(char choose ,int * TempP){
    int Temp =  *TempP;
    switch(choose){
        case DECREASE:
           if(Temp > TEMP_MIN){
               Temp -= 5;
           }
            break;
        case INCREASE:
             if(Temp < TEMP_MAX){
               Temp += 5;
}
            break;
    }
    *TempP = Temp;
}
void Cooling_Sys(system_T *sys){
    if(sys->Sys_mode == NORMAL_MODE){
    switch(sys->COOLING_SYS){
        case 0:
            PORTC &= ~(1 << 2);
            break;
        case 1:
            PORTC |= (1 << 2);
            break;
    }}
    else{
    //WAIT FOR END THE SETTING
       sys->COOLING_SYS = OFF;
       PORTC &= ~(1 << 2);
    }
}
void Heating_Sys(system_T *sys)
{
     if(sys->Sys_mode == NORMAL_MODE){
     switch(sys->HEATING_SYS){
          case 0:
            PORTC &= ~(1 << 5);
            break;
        case 1:
            PORTC |= (1 << 5);
            break;
 }}
        else{
    //WAIT FOR END THE SETTING
       sys->HEATING_SYS = OFF; 
       PORTC &= ~(1 << 5);
    }
}
void System_init(){
 TRISC &= ~( (1 << 2) | ( 1 << 5));
 PORTC &= ~( (1 << 2) | ( 1 << 5));
}
void UP_DOWN_B(char MODE,system_T *system,int *Temp){
 if(system->Sys_mode == NORMAL_MODE){
    system->Sys_mode = TEMP_SET_MODE;   
    system->COOLING_SYS = OFF;
    system->HEATING_SYS = OFF;
 }
 else if(system->Sys_mode == TEMP_SET_MODE)
 {

 Temp_Change(MODE,Temp);
 system->Sys_Count = 0;
 }
}
void SYSTEM_CONTROL(system_T *system,int *T,int *Tn){
    // the current water temperature is less than the set temperature by 5 degrees
    int Temp = *T;
    int TEMP_NOW = *Tn;
    if(system->Sys_mode == NORMAL_MODE){
    if(TEMP_NOW < (Temp - 5) )    
    {
    //HEATER ON
     system->HEATING_COUNT++;  
     system->HEATING_SYS = ON;
     system->COOLING_SYS = OFF;
     if(system->HEATING_COUNT == 20){
     PORTB ^= HEATING_L;
     system->HEATING_COUNT = 0;
     }     
    }
    else if( (TEMP_NOW < Temp + 5 ) && (system->HEATING_SYS == ON) )
    {
     //HEATER ON
     system->HEATING_COUNT++;  
     system->HEATING_SYS = ON;
     system->COOLING_SYS = OFF;
     if(system->HEATING_COUNT == 20){
     PORTB ^= HEATING_L;
     system->HEATING_COUNT = 0;
     }
    }
    else if(TEMP_NOW > (Temp + 5)   ){
     system->HEATING_COUNT = 0;  
     system->HEATING_SYS = OFF;
     system->COOLING_SYS = ON;
     PORTB |= HEATING_L ;
    }
    else if(( TEMP_NOW > ( Temp - 5 ) )&& (system->COOLING_SYS == ON)){
     system->HEATING_COUNT = 0;  
     system->HEATING_SYS = OFF;
     system->COOLING_SYS = ON;
     PORTB |= HEATING_L ;
    }
    else{
     system->HEATING_COUNT = 0;  
     system->HEATING_SYS = OFF;
     system->COOLING_SYS = OFF;
     PORTB &= ~HEATING_L ;
    }}
    Cooling_Sys(system);
    Heating_Sys(system);
    
}
