#include "delay.h"

static __IO uint32_t TimingDelay;


void systick_delay_init(void)
{
  if (SysTick_Config(SystemCoreClock / 100000))
  { 
    /* Capture error */ 
    while (1);
  }
}


void delay_ms(uint16_t delay)
{
  TimingDelay = delay;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

