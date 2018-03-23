#include "user_ap0.h"
#include  "usbd_usr.h"
#include "usbd_custom_hid_core.h"

extern USB_CORE_HANDLE  USB_Device_dev ;


uint8_t app_return[2] = {'1','2'};
uint16_t PrescalerValue = 0;
