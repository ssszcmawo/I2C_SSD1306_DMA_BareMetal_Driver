#include "I2C1_ReadBytes.h"

void i2c_readBytes(uint8_t addr, uint8_t *buf, uint8_t len) {
    volatile uint32_t tmp;

    while (I2C1->SR2 & I2C_SR2_BUSY) {}

    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB)) {}

    I2C1->DR = (addr << 1) | 1;
    while (!(I2C1->SR1 & I2C_SR1_ADDR)) {}

    tmp = I2C1->SR1;
    tmp = I2C1->SR2;

    if (len > 1)
        I2C1->CR1 |= I2C_CR1_ACK;
    else
        I2C1->CR1 &= ~I2C_CR1_ACK;

    for (uint8_t i = 0; i < len; i++) {
        if (i == len - 1)
            I2C1->CR1 &= ~I2C_CR1_ACK;
        while (!(I2C1->SR1 & I2C_SR1_RXNE)) {}
        buf[i] = I2C1->DR;
    }

    I2C1->CR1 |= I2C_CR1_STOP;
}