#ifndef SSD1306_STM32_H
#define SSD1306_STM32_H

#include "stm32f4xx.h"
#include <stdint.h>

#define SSD1306_ADDR 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

void SSD1306_Init(void);
void SSD1306_Clear(void);
void SSD1306_UpdateScreen(void);
void SSD1306_UpdateScreen_DMA(void);
void SSD1306_DrawChar(uint8_t x, uint8_t y, char c);
void SSD1306_DrawString(uint8_t x, uint8_t y, const char* str);
void SSD1306_DrawBitmap(uint8_t x, uint8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h);
void SSD1306_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
#endif
