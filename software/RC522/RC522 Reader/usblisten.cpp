#include "usblisten.h"
#include <qdebug.h>
#include <libusb/libusb_dyn.h>

USBListen::USBListen()
{

}


void USBListen::run()
{
    int ReceivedByte=0;
    char ReceivedData[1024];
    while(1)
    {
        ReceivedByte = usb_interrupt_read(Listen, 0x81, ReceivedData,1,100);
        if(ReceivedByte>0)
        {
            qDebug("The no of received byte is %d",ReceivedByte);
            ReceivedData[ReceivedByte]= '\0';
            qDebug("The received data is %s",ReceivedData);
        }
    }
}
