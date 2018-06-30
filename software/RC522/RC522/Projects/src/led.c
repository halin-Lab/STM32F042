#include "led.h"



void led_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_AHBPeriphClockCmd ( LED_PORT_CLK, ENABLE );
  GPIO_InitStructure.GPIO_Pin = LED_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = LED_PIN_MODE;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(LED_PORT, &GPIO_InitStructure);
	
	LED_OFF();
}

