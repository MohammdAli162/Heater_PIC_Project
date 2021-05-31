#include "ADC.h"
#include <xc.h>
void INIT_ADC(){   
 /*
 * START ADC
 * SELECT CHANNEL 2
 * FOSC/16
  * VREF+ VDD    VREF- VSS
  * AN5:AN7 ARE DIGITAL
 */ 
	//ADCON0 = ADON | CHS0 | ADCS0;
    ADCON0 = 0x51; 
    //ADCON1 = PCFG1 | ADCS2;
    ADCON1 = 0x42;
}
int READ_ADC()
{
    int read;
	ADCON0 = 0x51;            	// CONFIGURA CONVERSOR A/D
    for(int i = 0; i < 10;i++); //DELAY 
    GO = 1 ;//SET BIT TO START CONVERTING 
    while(GO == 1);// WAIT TO FINISH
    read = ((((unsigned int)ADRESH) << 2)|(ADRESL >> 6));
    return read;//READING THE VALUE
}


