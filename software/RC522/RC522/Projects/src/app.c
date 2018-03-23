#include "app.h"

uint8_t reply_buf[64];
uint8_t  is_valid=0;
uint8_t app_buf[64] = {0};
extern USB_CORE_HANDLE  USB_Device_dev ;

void app_init(void)
{
	
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
	/*
    app_buf[0] = dat[0];
    app_buf[1] = dat[1];
	*/
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
  if(is_valid !=0)
  {
		//TIM_Cmd(TIM2, DISABLE);
    is_valid = 0;
  //  USBD_HID_SendReport(&USB_Device_dev,app_return,2);
		//turn_degree(2000 - app_buf[1]);
		if(app_buf[0]== APP_STX)
		{
			switch( app_buf[3])
			{
				case APP_REQA:
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

/*
#define APP_VERiFY    0x15
#define APP_READ      0x16
#define APP_WRITE     0x17
*/
