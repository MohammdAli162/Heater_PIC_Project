#include "LM35.h"
/*
 THIS API IS USED TO READ FROM LM35 SENSOR 
 * USED ADC 
 */
#define ADJUSTMENT 0.55
int ADC_READ_LM35(void)
{
    float read =(float) READ_ADC();
    read = read * ADJUSTMENT;
    return (int)read;
}

