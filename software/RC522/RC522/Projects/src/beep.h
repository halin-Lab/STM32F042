#ifndef __BEEP_H__
#define __BEEP_H__

#include "stm32f0xx.h"

#define BEEP_PORT_CLK  RCC_AHBPeriph_GPIOB
#define BEEP_PORT      GPIOB
#define BEEP_PIN       GPIO_Pin_1
#define BEEP_PIN_MODE  GPIO_Mode_OUT


#define BEEP_ON()   GPIO_ResetBits(BEEP_PORT,  BEEP_PIN)
#define BEEP_OFF()  GPIO_SetBits(BEEP_PORT,  BEEP_PIN)

void beep_init(void);


#endif

