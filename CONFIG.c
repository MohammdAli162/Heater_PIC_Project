#include "config_877A.h"
    void PORTS_CONFIG(){
    OPTION_REGbits.INTEDG = 0;//falling egde for external interrupt
    TRISB = 0;//port b all op
    TRISB |= (1 << 0) | UP_BUTTON |DOWN_BUTTON;//B0 / B3 / B4 IS INPUT
    TRISD = 0;//port d is op 
    PORTB  &= ~(ON_LED | HEATING_L);//CLOSE ON/OFF LED AND HEATER LED
    PORTD = 0;
}
void PERIPHERALS_INIT(){
 Timer1_init();
 System_init();
 MEMORY_EXT_INIT();
 INIT_ADC();
}
