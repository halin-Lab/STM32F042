#include "led.h"

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//PIN0��PIN1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//����
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//IO��Ƶ�ʴ���50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//û��������������
  
  GPIO_Init(GPIOF, &GPIO_InitStructure);

	GPIO_SetBits(GPIOF,  GPIO_Pin_0);
	GPIO_SetBits(GPIOF,  GPIO_Pin_1);
}