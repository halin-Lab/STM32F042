/**
******************************************************************************
* @file    app.c
* @author  MCD Application Team
* @version V1.0.0
* @date    31-January-2014
* @brief   This file provides all the Application firmware functions.
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
*
* Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
* You may not use this file except in compliance with the License.
* You may obtain a copy of the License at:
*
*        http://www.st.com/software_license_agreement_liberty_v2
*
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************
*/ 

/* Includes ------------------------------------------------------------------*/ 
#include "usbd_custom_hid_core.h"
#include  "usbd_usr.h"
#include "user_ap0.h"
#include "delay.h"
#include "rc522_config.h"
#include "rc522_function.h"
#include "app.h"
#include "led.h"
#include "beep.h"
uint8_t tog=0;
void toggle_led(void)
{
	if(tog==0)
	{
		tog=1;
					GPIO_SetBits(GPIOF,  GPIO_Pin_0);
	}else if(tog==1)
	{
		tog=0;
			GPIO_ResetBits(GPIOF,  GPIO_Pin_0);
	}
}

void IC_test ( void )
{
  uint8_t ucArray_ID [ 4 ];                                                                                             //先后存放IC卡的类型和UID(IC卡序列号)
	uint8_t ucStatusReturn;                                                                                               //返回状态
  static uint8_t ucLineCount = 0; 
	
	
  while ( 1 )
  {
	
		if ( ( ucStatusReturn = PcdRequest ( PICC_REQALL, ucArray_ID ) ) != MI_OK )                                    //寻卡
			ucStatusReturn = PcdRequest ( PICC_REQALL, ucArray_ID );		                                                 //若失败再次寻卡

		if ( ucStatusReturn == MI_OK  )
		{
			if ( PcdAnticoll ( ucArray_ID ) == MI_OK )                                                                   //防冲撞（当有多张卡进入读写器操作范围时，防冲突机制会从其中选择一张进行操作）
			{
				toggle_led();
				if ( ucLineCount == 17 ) ucLineCount = 0;
			}
		}
  }
}

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/ 
USB_CORE_HANDLE  USB_Device_dev ;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
* @brief  Program entry point
* @param  None
* @retval None
*/
int main(void)
{ 
	systick_delay_init();
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  SYSCFG->CFGR1 |= SYSCFG_CFGR1_PA11_PA12_RMP;
  USBD_Init(&USB_Device_dev,
            &USR_desc, 
            &USBD_HID_cb, 
            &USR_cb);
	RC522_Init();
	PcdReset();
	M500PcdConfigISOType('A');//设置工作方式
	app_init();
	led_init();
	beep_init();
  while (1)
  {
    task();
  }
} 




#ifdef USE_FULL_ASSERT
/**
* @brief  assert_failed
*         Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  File: pointer to the source file name
* @param  Line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  
  /* Infinite loop */
  while (1)
  {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
