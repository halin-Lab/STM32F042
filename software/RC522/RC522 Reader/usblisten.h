#ifndef USBLISTEN_H
#define USBLISTEN_H

#include <QThread>
#include <libusb/libusb_dyn.h>

class USBListen : public QThread
{
    Q_OBJECT
public:
    USBListen(QObject *parent = 0);
protected:
    void run();

private:
    usb_dev_handle *Listen;
};

#endif // USBLISTEN_H
