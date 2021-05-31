#include <pic.h>
#include "I2C.h"

#include "config_877A.h"

void I2C_Master_Wait()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_INIT_MASTER(void){

    SDA_DIR = 1;    // Make SDA and
    SCK_DIR = 1;    // SCK pins input
    SSPADD = (_XTAL_FREQ/(4*I2C_SPEED))-1;
    SSPSTAT = 0;    // Slew Rate control is disabled
    SSPCON  = 0x28;    // Select and enable I2C in master mode
}

char I2C_SEND_B(char DATA)
{
    I2C_Master_Wait();
    SSPBUF = DATA;
    while(!PIR1bits.SSPIF);//WAIT FOR COMPLETE
    PIR1bits.SSPIF = 0;
    return SSPCON2bits.ACKSTAT ;           
}

void I2C_START_BIT()
{
    I2C_Master_Wait();
   SSPCON2bits.SEN = 1;// Start Condition Enabled
    while(SSPCON2bits.SEN);//WAIT FOR COMPLETE
    PIR1bits.SSPIF = 0;
}
void I2C_STOP_BIT()
{
    I2C_Master_Wait();
   SSPCON2bits.PEN = 1;// Start Condition Enabled
    while(SSPCON2bits.PEN);//WAIT FOR COMPLETE
    PIR1bits.SSPIF = 0;
}
void  I2C_Send_NACK(){
    I2C_Master_Wait();
    SSPCON2bits.ACKDT = 1;      // 1 means NACK
    while(SSPCON2bits.ACKEN);    // Wait for it to complete
    PIR1bits.SSPIF = 0;      // Clear the flag bit
}
char I2C_READ_DATA(){
    I2C_Master_Wait();
    SSPCON2bits.RCEN = 1;//ENABLE RECIEVE
    
    while(SSPCON2bits.RCEN);//WAIT FOR COMPLETE
    I2C_Master_Wait();
    PIR1bits.SSPIF = 0;  
    return (SSPBUF);
}

void I2C_ReStart(void)
{
    I2C_Master_Wait();
    SSPCON2bits.RSEN = 1;      // Send Restart bit
    while(SSPCON2bits.RSEN);//WAIT FOR COMPLETE
    PIR1bits.SSPIF = 0;
}

