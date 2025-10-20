#include "SHT3x_Read.h"
void SHT3x_read(float* temperature, float* humidity){
    uint8_t buf[6];

    i2c_writeByte(SHT3X_ADDR,0x2C,0x06);

    for(volatile int i = 0; i < 300000; i++);

    i2c_readBytes(SHT3X_ADDR,buf,6);

    uint16_t rawTemp = (buf[0] << 8) | buf[1];
    uint16_t rawHum = (buf[3] << 8) | buf[4];

    *temperature = -45.0f + 175.0f * rawTemp / 65535.0f;
    *humidity = 100.0f * rawHum / 65535.0f;
}