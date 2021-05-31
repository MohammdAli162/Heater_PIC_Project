/*
 * File:   main.c
 * Author: MA
 *
 * Created on 30 ?????, 2020, 12:45 ?
 */
#include "config_877A.h"
#define ADDRESS 0X00A    
int Temp = 60;
int TEMP_NOW ;
char STATE = OFF;
char Cycles = 0;
char Temp_Times = 0;
int Temp_degree = 0;


void __interrupt() ISR(void)
{
    //ON_OFF INTERRUPT
    if ((INTCON & (1 << 1)) != OFF) //External Interrupt detected
    {
        if(STATE == OFF){
            PORTB |= ON_LED;
            Timer1_Reload();
            TIMER1_ON();
            STATE = ON;
          while((PORTB &  1  ) == OFF);
       }
        else if(STATE == ON){                       
            PORTB  &= ~ON_LED;
            TIMER1_OFF();
            STATE = OFF;
           STATE = OFF;
           system.HEATING_COUNT = 0;
           system.COOLING_SYS = OFF;
           system.HEATING_SYS = OFF;
           system.Sys_mode = NORMAL_MODE;
           system.Sys_Count = 0;
            Cooling_Sys(&system);
            Heating_Sys(&system);
            while((PORTB &  1  ) == OFF);
        }
       INTCONbits.INTF = 0;
    }
    //TIMER 1 INTERRUBT
      if ((PIR1 &(1 << 0 ) )!= OFF){
             TIMER0_OFF();
            SYSTEM_CONTROL(&system,&Temp,&TEMP_NOW);
            Cycles++;
            // IF THE CYCLES IS 4 IT MEANS THE TIME 100msec SO GET A NEW READING
        if(Cycles == SENSOR_READ){
        //READ SENSOR 
            Temp_degree += ADC_READ_LM35();//SUMMING TEMP
            Temp_Times++;//INCREASE VAR 
         if(Temp_Times == 9){
             TEMP_NOW = Temp_degree/TEMP_NO;//CALULATING AVERAGE
             Temp_Times = 0;//reseting the values to zero again
             Temp_degree = 0;  
         }
            Cycles = 0;
        }
        if(( PORTB &  UP_BUTTON  ) == 0){
        //CHANGE THE MODE OR TEMP           
         UP_DOWN_B(INCREASE,&system,&Temp);  
        while((PORTB &  UP_BUTTON  ) == 0);//WAIT FOR RELEASE
        }
        else if((PORTB &  DOWN_BUTTON  ) == 0){
         //CHANGE THE MODE OR TEMP
         UP_DOWN_B(DECREASE,&system,&Temp);
        while((PORTB &  DOWN_BUTTON  ) == 0);//WAIT FOR RELEASE
        }       
        Timer1_Reload();//REALOAD THE TIMER AGAIN 
        PIR1 &= ~(1<<0);//CLEAR THE INTERRUPT GLAG 
        TIMER1_ON();//WORK THE TIMER AGAIN  
    }  

}
void main(void) {
    //INITIALZE THE STRUCT 
STATE = OFF;
system.HEATING_COUNT = 0;
system.COOLING_SYS = OFF;
system.HEATING_SYS = OFF;
system.Sys_mode = NORMAL_MODE;
system.Sys_Count = 0;
    //PORTB CONFIG
    PORTS_CONFIG();
    PERIPHERALS_INIT();
    
    Temp = MEMORY_EXT_READ(ADDRESS);
    //make sure that the reading isnot a garbage 
    if(Temp > TEMP_MAX || Temp < TEMP_MIN || ( (Temp%5) != 0)){
        Temp = 60;
        MEMORY_EXT_WRITE(ADDRESS,Temp);    
    }
    TEMP_NOW = Temp;
//INTERRUPT CONFIG
     //ENABLE GLOBAL PRIPHERAL INTERRUPT EXTERNAL 
    GINT_E();
    PINT_E();
    EXINT_E();
    while(1){
        if(STATE == OFF){
            //sleep mode
            SLEEP();                  
        }
        else { 
        if(system.Sys_mode == NORMAL_MODE){
        SEG_DISPLAY(TEMP_NOW);
        system.Sys_Count = 0;
             }//CLOSE IF NORMAL
        else if(system.Sys_mode == TEMP_SET_MODE){
         system.Sys_Count++;
        if(system.Sys_Count == 40 || system.Sys_Count == 80 || system.Sys_Count == 120 || system.Sys_Count == 160 || system.Sys_Count == 5*40){
        //BLINK THE 2 7 SEG
            __delay_ms(100);
        }//CLOSE IF 
        else if(system.Sys_Count == (40 * 6)){
            system.Sys_Count = 0;
            MEMORY_EXT_WRITE(ADDRESS,Temp);
            system.Sys_mode = NORMAL_MODE;
        }
        else{
        SEG_DISPLAY(Temp);
        }
    }//CLOSE IF TEMP_SET_MODE
    }//CLOSE IF STATE == ON
    }
    return;
}










