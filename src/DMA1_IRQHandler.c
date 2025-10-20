#include "I2C1_DMA1_Init.h"

void DMA1_Stream6_IRQHandler(void){
    if(DMA1->HISR & DMA_HISR_TCIF6){
        DMA1->HIFCR |= DMA_HIFCR_CTCIF6;
        I2C1->CR1 |= I2C_CR1_STOP;
        DMA1_Stream6->CR &= ~DMA_SxCR_EN;
        I2C1->CR2 &= ~I2C_CR2_DMAEN;
        dma_busy = 0;
    }
}