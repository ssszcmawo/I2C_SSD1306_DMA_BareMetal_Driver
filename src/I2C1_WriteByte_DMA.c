#include "I2C1_WriteByte_DMA.h"


void i2c_writeBytes_DMA(uint8_t addr,uint8_t reg,uint8_t* data,uint16_t len){
    volatile uint32_t tmp;

    while(I2C1->SR2 & I2C_SR2_BUSY){}

    I2C1->CR1 |= I2C_CR1_START;
    while(!(I2C1->SR1 & I2C_SR1_SB)){}

    I2C1->DR = addr << 1;
    while(!(I2C1->SR1 & I2C_SR1_ADDR)){}
    
    tmp = I2C1->SR1;
    tmp = I2C1->SR2;

    while(!(I2C1->SR1 & I2C_SR1_TXE)){}
    I2C1->DR = reg;
    

    DMA1_I2C1_TX_Init(data,len);

    while(dma_busy){}
}