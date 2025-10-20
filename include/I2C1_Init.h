#include "stm32f446xx.h"

#define I2C1_EN     (1U << 21)  
#define GPIOBEN     (1U << 1)  

#define I2C1_CR_EN  (1U << 0)
#define I2C1_SWRST  (1U << 15)

#define FREQ_APB1   42000000U   
#define I2C_FREQ    100000U     

void I2C1_init(void);
