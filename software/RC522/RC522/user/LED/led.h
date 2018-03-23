#ifndef __LED_H__
#define __LED_H__

#include "stm32f0xx.h"

#define LED0_ON()   GPIO_ResetBits(GPIOF,  GPIO_Pin_0);
#define LED1_ON()   GPIO_ResetBits(GPIOF,  GPIO_Pin_1);

#define LED0_OFF()  GPIO_SetBits(GPIOF,  GPIO_Pin_0);
#define LED1_OFF() GPIO_SetBits(GPIOF,  GPIO_Pin_1);

	
	
#endif

