#define SHT3X_ADDR 0x44
#include <stdint.h>
#include "I2C1_WriteByte.h"
#include "I2C1_ReadBytes.h"

void SHT3x_read(float* temperature, float* humidity);