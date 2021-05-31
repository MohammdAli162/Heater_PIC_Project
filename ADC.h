/* 
 * File:   ADC.h
 * Author: smart
 *
 * Created on 01 ?????, 2020, 03:38 ?
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <pic16f877a.h>

#define  ADCS1 (1<<7) //PRESCALER1
#define  ADCS0 (1<<6) //PRESCALER0
#define  CHS2  (1<<5)
#define  CHS1  (1<<4)
#define  CHS0  (1<<3)
#define  GO_BIT    (1<<2)
#define  ADON  (1<<0)

#define  ADFM  (1<<7) 
#define  ADCS2 (1<<6) 
#define  PCFG3 (1<<3)
#define  PCFG1 (1<<2)
#define  PCFG0 (1<<0)
    
void INIT_ADC(void);
int READ_ADC(void);





#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

