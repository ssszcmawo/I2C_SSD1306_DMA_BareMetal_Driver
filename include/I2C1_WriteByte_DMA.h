#include "stm32f446xx.h"
#include "I2C1_DMA1_Init.h"
void i2c_writeBytes_DMA(uint8_t addr,uint8_t reg,uint8_t* data,uint16_t len);
