#ifndef __LED_H__
#define __LED_H__

#include "stm32f0xx.h"

#define LED_PORT_CLK  RCC_AHBPeriph_GPIOF
#define LED_PORT      GPIOF
#define LED_PIN       GPIO_Pin_0
#define LED_PIN_MODE  GPIO_Mode_OUT


#define LED_ON()   GPIO_ResetBits(LED_PORT,  LED_PIN)
#define LED_OFF()  GPIO_SetBits(LED_PORT,  LED_PIN)

void led_init(void);
#endif

