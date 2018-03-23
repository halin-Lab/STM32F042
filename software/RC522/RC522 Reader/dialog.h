#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "libusb/libusb_dyn.h"
#include "usb_listen.h"

#define MaxDev   10
namespace Ui {
class Dialog;
}

struct LibUSB{
    struct usb_dev_handle *DevHandle;
    char isOpen;
};

#define RC522_STX  0xaa
#define RC522_ETX  0x55

#define RC522_CMD_REQA       0x11
#define RC522_CMD_ANTICOLLA  0x12
#define RC522_CMD_SELECT     0x13
#define RC522_CMD_HALTA      0x14

#define RC522_CMD_VERiFY    0x15
#define RC522_CMD_READ      0x16
#define RC522_CMD_WRITE     0x17

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_LED1_stateChanged(int arg1);


    void get_usb_data(unsigned char *dat,unsigned int len);

    void on_DevOpen_clicked();

    void on_REQA_clicked();

    void on_AnticollA_clicked();

    void on_select_clicked();

    void on_halta_clicked();

    void on_Verify_clicked();

    void on_section_read_clicked();

    void on_section_write_clicked();

    void on_key_textChanged(const QString &arg1);

    bool Check_hex(QString hex);
private:
    Ui::Dialog *ui;
    struct usb_bus *bus;
    struct usb_device *dev;
    struct usb_device *FoundedDev[MaxDev];
    int FoundedDev_nubmer;
    int Current_Dev;
    struct LibUSB CurrenDev;
    struct usb_dev_handle *Dev;
    struct usb_dev_handle *LEDudev;
    struct usb_dev_handle *libusb_device;
    USB_Listen Reveiver;
};

#endif // DIALOG_H
