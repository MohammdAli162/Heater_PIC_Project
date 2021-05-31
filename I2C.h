/* 
 * File:   I2C.h
 * Author: smart
 *
 * Created on 01 ?????, 2020, 02:29 ?
 */

#ifndef I2C_H
#define	I2C_H

#define SDA RC4
#define SCK RC3
#define SDA_DIR TRISC4
#define SCK_DIR TRISC3
#define I2C_SPEED 100000 //SPEED 
char I2C_READ_DATA(void);
char I2C_SEND_B(char);
void I2C_INIT_MASTER(void);
void I2C_STOP_BIT(void);
void I2C_START_BIT(void);
void I2C_Send_NACK(void);  
void I2C_ReStart(void);
#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

