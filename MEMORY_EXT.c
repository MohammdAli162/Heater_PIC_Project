#include <pic16f877a.h>

#include "MEMORY_EXT.h"
void MEMORY_EXT_INIT(void){
    I2C_INIT_MASTER();
}
void MEMORY_EXT_WRITE(char ADD, char DATA){
    I2C_START_BIT();
      // Send i2c address of 24LC64 with write command
    while(I2C_SEND_B(Device_Address_EEPROM + 0) == 1)// Wait until device is free
    {
        I2C_ReStart();
    }
    I2C_SEND_B(ADD >> 8);
    I2C_SEND_B((unsigned char)ADD);
    I2C_SEND_B(DATA);
    I2C_STOP_BIT();
}
char MEMORY_EXT_READ(char ADD){
    int data;
    I2C_START_BIT();
   // Send i2c address of 24LC64 with write command
    while(I2C_SEND_B(Device_Address_EEPROM + 0) == 1)// Wait until device is free
    {
        I2C_ReStart();
    }
    I2C_SEND_B(ADD >> 8);
    I2C_SEND_B((unsigned char)ADD);
     I2C_START_BIT();
    I2C_SEND_B(Device_Address_EEPROM + 1);
    data = I2C_READ_DATA();
    I2C_Send_NACK();                  // Give NACK to stop reading
    I2C_STOP_BIT();
    return data;
}


