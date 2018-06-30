#include "app.h"
#include "led.h"
#include "beep.h"

uint8_t reply_buf[64];
uint8_t  is_valid=0;
uint8_t app_buf[64] = {0};
extern USB_CORE_HANDLE  USB_Device_dev ;

void app_init(void)
{
	TIM_Config();
}

void send_reply(uint8_t cmd,uint8_t *data,uint8_t lenght,uint8_t status)
{
	uint8_t index=0,i=0;
	reply_buf[0] = APP_STX;
	reply_buf[1] = 0x00;
	reply_buf[2] = lenght;
	reply_buf[3] = cmd;
	reply_buf[4] = status;
	index = 5;
	for(i=0;i<lenght;i++)
	{
		reply_buf[index] = data[i];
		index ++;
	}
	reply_buf[index] = APP_ETX;
	
	for(index++;index<64;index++)
		reply_buf[index] = 0;
	USBD_HID_SendReport(&USB_Device_dev,reply_buf,64);
}

void get_buf(uint8_t *dat)
{
		uint8_t i=0;
	for(i=0;i<64;i++)
		app_buf[i] = dat[i];
    is_valid = 1;
}


void set_valid(uint8_t value)
{
  is_valid = value;
}

uint8_t card_type[2];
uint8_t ucArray_ID [ 4 ]; 
uint8_t readed[16];
void task(void)
{
                                                                                             //先后存放IC卡的类型和UID(IC卡序列号)
	uint8_t ucStatusReturn;      
	uint8_t temp=0;
	get_card_task();
  if(is_valid !=0)
  {
    is_valid = 0;
		if(app_buf[0]== APP_STX)
		{
			switch( app_buf[3])
			{
				case APP_REQA:
					led_task_start(100);
					if((ucStatusReturn = PcdRequest(PICC_REQALL,card_type))!= MI_OK)  //寻卡
							ucStatusReturn = PcdRequest ( PICC_REQALL, card_type );	
					if(ucStatusReturn == MI_OK)
						send_reply(APP_REQA,card_type,2,0x00);
					else
						send_reply(APP_REQA,card_type,0,0x01);
					break;
					
				case APP_AnticollA:
					if(PcdAnticoll(ucArray_ID) == MI_OK)
					{
						send_reply(APP_AnticollA,ucArray_ID,4,0x00);
					}else
					{
						send_reply(APP_AnticollA,ucArray_ID,0,0x01);
					}
					break;
				case APP_SELECTA:
					if(PcdSelect(ucArray_ID) ==MI_OK)
					{
						send_reply(APP_SELECTA,ucArray_ID,0,0x00);
					}else
					{
						send_reply(APP_SELECTA,ucArray_ID,0,0x01);
					}
					break;
					
				case APP_GET_CARD:
					get_card_task_enable();
					break;
				case APP_HALTA:
					PcdHalt();
				send_reply(APP_HALTA ,ucArray_ID,0,0x00);
					break;
				
				case APP_VERiFY:
					if(app_buf[5] == 0x01)
						temp = 0x60;
					else 
						temp = 0x61;
					if(PcdAuthState (temp,app_buf[4],&app_buf[6],ucArray_ID)== MI_OK)
					{
						send_reply(APP_VERiFY,ucArray_ID,0,0x00);
					}else{
						send_reply(APP_VERiFY,ucArray_ID,0,0x01);
					}
					break;
				case APP_READ:
						if(PcdRead(app_buf[4],readed)==MI_OK)
						{
							send_reply(APP_READ,readed,16,0x00);
						}else
						{
							send_reply(APP_READ,readed,0,0x01);
						}
					break;
				case APP_WRITE:
						if(PcdWrite (app_buf[4],&app_buf[5])==MI_OK)
						{
							send_reply(APP_WRITE,app_buf,0,0x00);
						}else{
							send_reply(APP_WRITE,app_buf,0,0x01);
						}
					break;
				default:
					break;
			}
		}
  }
}


uint8_t get_card_flag=0;

void get_card_task_enable(void)
{
		get_card_flag = 1;
}

void  get_card_task(void)
{            
	uint8_t ucStatusReturn;  
	
	if(get_card_flag )
	{
		get_card_flag=0;
			if ((ucStatusReturn = PcdRequest (PICC_REQALL,ucArray_ID) )!= MI_OK)//寻卡
				ucStatusReturn = PcdRequest (PICC_REQALL,ucArray_ID);//若失败再次寻卡

			if ( ucStatusReturn == MI_OK  )
			{
				if ( PcdAnticoll(ucArray_ID) == MI_OK )//防冲撞（当有多张卡进入读写器操作范围时，防冲突机制会从其中选择一张进行操作）
				{
					if(PcdSelect(ucArray_ID) ==MI_OK)
					{
						send_reply(APP_GET_CARD,ucArray_ID,4,0x00);
						led_task_start(100);
						return;
					}else
					{
						send_reply(APP_GET_CARD,ucArray_ID,0,0x01);
					}
				}
			}
			PcdHalt();
	}
	
}
/*
#define APP_VERiFY    0x15
#define APP_READ      0x16
#define APP_WRITE     0x17
*/



void TIM14_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM14, TIM_IT_Update) != RESET)
	{
		led_1ms_task();
		beep_1ms_task();
		TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
	}
}


uint16_t PrescalerValue = 0;


void TIM_Config(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);

  /* Enable the TIM3 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM14_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
    /* -----------------------------------------------------------------------
    TIM3 Configuration: Output Compare Timing Mode:
    
    In this example TIM3 input clock (TIM3CLK) is set to APB1 clock (PCLK1),  
      => TIM3CLK = PCLK1 = SystemCoreClock = 48 MHz
          
    To get TIM3 counter clock at 6 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = (PCLK1 /6 MHz) - 1

    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f0xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */   
  PrescalerValue = (uint16_t) (SystemCoreClock  / 1000000) - 1;


  TIM_TimeBaseStructure.TIM_Period = 1000;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);
  
  TIM_PrescalerConfig(TIM14, PrescalerValue, TIM_PSCReloadMode_Immediate);
 
  TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);

	TIM_Cmd(TIM14, ENABLE);
  
}

uint16_t led_counter = 0;
uint16_t beep_counter = 0;

void led_1ms_task(void)
{
	if(led_counter !=0)
	{
		led_counter --;
		if(led_counter ==0)
		{
			LED_OFF();
		}
	}
}

void led_task_start(uint16_t timer)
{
	LED_ON();
	led_counter = timer;
}



void beep_1ms_task(void)
{
	if(beep_counter !=0)
	{
		beep_counter --;
		if(beep_counter ==0)
		{
			BEEP_OFF();
		}
	}
}

void beep_task_start(uint16_t timer)
{
	BEEP_ON();
	beep_counter = timer;
}


