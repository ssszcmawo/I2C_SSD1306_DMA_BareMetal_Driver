#include "I2C1_Init.h"

void I2C1_init(void) {
    RCC->AHB1ENR |= GPIOBEN;

    GPIOB->MODER &= ~((3U << 16) | (3U << 18));
    GPIOB->MODER |=  ((2U << 16) | (2U << 18));

    GPIOB->OTYPER |= ((1U << 8) | (1U << 9));

    GPIOB->OSPEEDR |= ((3U << 16) | (3U << 18));

    GPIOB->PUPDR &= ~((3U << 16) | (3U << 18));

    GPIOB->AFR[1] &= ~((0xF << 0) | (0xF << 4));
    GPIOB->AFR[1] |= ((4 << 0) | (4 << 4));

    RCC->APB1ENR |= I2C1_EN;

    I2C1->CR1 |= I2C1_SWRST;
    I2C1->CR1 &= ~I2C1_SWRST;

    I2C1->CR2 = 42;                      
    I2C1->CCR = FREQ_APB1 / (2 * I2C_FREQ); 
    I2C1->TRISE = 43;                    

    I2C1->CR1 |= I2C1_CR_EN;
}