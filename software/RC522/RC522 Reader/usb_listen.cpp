#include "usb_listen.h"

USB_Listen::USB_Listen(QObject *parent) :
    QThread(parent)
{
   stopped = false;
}

void USB_Listen::SetDev(usb_dev_handle *dev)
{
    Listenor = dev;
   // Ok2Run = 1;
}


void USB_Listen::run()
{
    int ReceivedByte=0;
    unsigned char ReceivedData[64];
    while(stopped == false)
    {

        ReceivedByte = usb_bulk_read(Listenor, 0x81, (char *)ReceivedData,64,1000);
       if(ReceivedByte>0)
        {
            qDebug("The nom of received byte is %d",ReceivedByte);
            ReceivedData[ReceivedByte]= '\0';
            qDebug("The received data is %s",ReceivedData);
            emit received(ReceivedData,ReceivedByte);

        }else{
            qDebug("No data");
       }
    }
    qDebug("Thread exit");
}

void USB_Listen::stop()
{
    stopped = true;
}
