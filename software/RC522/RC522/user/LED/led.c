#include "led.h"

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//PIN0，PIN1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO口频率带宽50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//没有上拉下拉电阻
  
  GPIO_Init(GPIOF, &GPIO_InitStructure);

	GPIO_SetBits(GPIOF,  GPIO_Pin_0);
	GPIO_SetBits(GPIOF,  GPIO_Pin_1);
}