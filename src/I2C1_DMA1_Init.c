#include "I2C1_DMA1_Init.h"

volatile uint8_t dma_busy = 0;

void DMA1_I2C1_TX_Init(uint8_t* buffer,uint16_t length){
    DMA1_Stream6->CR &= ~DMA_SxCR_EN;
    while(DMA1_Stream6->CR & DMA_SxCR_EN){}

    DMA1_Stream6->PAR = (uint32_t)&I2C1->DR;
    DMA1_Stream6->M0AR = (uint32_t)buffer;
    DMA1_Stream6->NDTR = length;

    DMA1_Stream6->CR = 0;
    DMA1_Stream6->CR |= DMA_SxCR_DIR_0
                        |DMA_SxCR_MINC
                        |DMA_SxCR_TCIE
                        |DMA_SxCR_CHSEL_0;
    
    DMA1_Stream6->CR |= DMA_SxCR_EN;
    I2C1->CR2 |= I2C_CR2_DMAEN;

    dma_busy = 1;
}