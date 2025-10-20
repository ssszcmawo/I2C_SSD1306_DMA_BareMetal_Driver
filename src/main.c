#include "I2C1_Init.h"
#include "I2C1_WriteByte.h"
#include "I2C1_ReadBytes.h"
#include "SHT3x_Read.h"
#include "ssd1306_stm32.h"
#include "I2C1_DMA1_Init.h"

#include <string.h>



int main(void){
    I2C1_init();

    NVIC_SetPriority(DMA1_Stream6_IRQn, 1);
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);

    SSD1306_Init();
    SSD1306_Clear();

    while(1){
        
    }
}