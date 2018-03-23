#ifndef USB_LISTEN_H
#define USB_LISTEN_H

#include <QThread>
#include "libusb/libusb_dyn.h"

class USB_Listen : public QThread
{
    Q_OBJECT
public:
    explicit USB_Listen(QObject *parent = 0);
    void SetDev(usb_dev_handle *dev);
    void stop();
signals:
        void received(unsigned char *dat,unsigned int len);

public slots:

protected:
    void run();
private:
    usb_dev_handle *Listenor;
    bool stopped;

};

#endif // USB_LISTEN_H
