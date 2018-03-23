#ifndef __DELAY_H__
#define __DELAY_H__

#include "stm32f0xx.h"


void systick_delay_init(void);
void delay_ms(uint16_t delay);


#endif

