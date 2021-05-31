#include "SEG_7.h"
#define _XTAL_FREQ 4000000
#include <pic.h>

#define delay 10
#define DIG_0 0x3F
#define DIG_1 0x06
#define DIG_2 0x5B
#define DIG_3 0x4F
#define DIG_4 0x66
#define DIG_5 0x6D
#define DIG_6 0x7D
#define DIG_7 0x07
#define DIG_8 0x7F
#define DIG_9 0x6F
char SEG_7[] = {DIG_0,DIG_1,DIG_2,
                DIG_3,DIG_4,DIG_5,
                DIG_6,DIG_7,DIG_8,DIG_9};


void SEG_7_DISPLAY(char Digits,char val){
    switch(Digits){
        case 1:
            TRISAbits.TRISA5 = 0; //RA5 OP       
            PORTA |= (1 << (5) );//SET RA5 TO DISPLAY ON DIGIT 1
            PORTD = val;//PUT THE VALUE
            __delay_ms(delay);//DELAY TO BE VISIBLE
            PORTA &= ~(1 << (5) );//CLOSE THE CONTROL 
            break;
        case 2:
            TRISAbits.TRISA4 = 0; 
            PORTA |= (1 << (4) );
            PORTD = val;
            __delay_ms(delay);
            PORTA &= ~(1 << (4) );
            break;    
    }}
void SEG_DISPLAY(int Temp){   
     SEG_7_DISPLAY(2,SEG_7[Temp/10]);
     SEG_7_DISPLAY(1,SEG_7[Temp%10]);
    }
   
