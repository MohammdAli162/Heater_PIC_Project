/* 
 * File:   MEMORY_EXT.h
 * Author: smart
 *
 * Created on 02 ?????, 2020, 12:24 ?
 */

#ifndef MEMORY_EXT_H
#define	MEMORY_EXT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "I2C.h"
    
    void MEMORY_EXT_INIT(void);
    void MEMORY_EXT_WRITE(char ADD, char DATA);
    char MEMORY_EXT_READ(char ADD);


// Define 24LC i2c device address
#define Device_Address_EEPROM  0xA0

#ifdef	__cplusplus
}
#endif

#endif	/* MEMORY_EXT_H */

