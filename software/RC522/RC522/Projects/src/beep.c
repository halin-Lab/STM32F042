#include "beep.h"



void beep_init(void)
{
	  // SPI_InitTypeDef  SPI_InitStructure 
  GPIO_InitTypeDef GPIO_InitStructure;
  

	//!< Configure SPI_RC522_SPI pins: CS 
	RCC_AHBPeriphClockCmd ( BEEP_PORT_CLK, ENABLE );
  GPIO_InitStructure.GPIO_Pin = BEEP_PIN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = BEEP_PIN_MODE;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(BEEP_PORT, &GPIO_InitStructure);
	BEEP_OFF();
}

