#ifndef __APP_H__
#define __APP_H__

#include "usbd_custom_hid_core.h"
#include  "usbd_usr.h"
#include "user_ap0.h"
#include "delay.h"
#include "rc522_config.h"
#include "rc522_function.h"


#define APP_STX   0xaa
#define APP_ETX   0x55



//cmd
//0x0x for system
//0x1x for M1
#define  APP_REQA        0x11  
#define  APP_AnticollA   0x12
#define APP_SELECTA      0x13
#define APP_HALTA        0x14
#define APP_GET_CARD     0x10

#define APP_VERiFY       0x15
#define APP_READ         0x16
#define APP_WRITE        0x17


void app_init(void);
void send_reply(uint8_t cmd,uint8_t *data,uint8_t lenght,uint8_t status);
void task(void);
void get_buf(uint8_t *dat);
void set_valid(uint8_t value);
void led_task_start(uint16_t timer);
void led_1ms_task(void);
void TIM_Config(void);

void beep_1ms_task(void);

void beep_task_start(uint16_t timer);
	
void  get_card_task(void);
void get_card_task_enable(void);
#endif
