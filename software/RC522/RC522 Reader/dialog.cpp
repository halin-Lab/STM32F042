#include "dialog.h"
#include "ui_dialog.h"
#include "libusb/libusb_dyn.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tab_2->setAutoFillBackground(true);
    ui->tab->setAutoFillBackground(true);
    ui->tab_3->setAutoFillBackground(true);
    ui->tab_4->setAutoFillBackground(true);
    QPalette palette;
    QColor color(240,240,240);
    palette.setColor(QPalette::Background,color);

    CurrenDev.isOpen = 0;
    CurrenDev.DevHandle = NULL;
}
Dialog::~Dialog()
{
    Reveiver.stop();
    Reveiver.wait();
    usb_close(libusb_device);
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    usb_init();
    usb_find_busses(); // find all busses //
    usb_find_devices(); // find all connected devices //
    int i=0;
    struct usb_dev_handle *udev;
    int ret;
    char string[100];
    FoundedDev_nubmer=0;

    ui->comboBox->clear();
    for (bus = usb_busses; bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            FoundedDev[i]=dev;//bus->devices;
            udev=usb_open(FoundedDev[i]);
            if(udev)
            {
                if (FoundedDev[i]->descriptor.iProduct)
                {
                    ret = usb_get_string_simple(udev, FoundedDev[i]->descriptor.iProduct, string, sizeof(string));
                    if (ret > 0)
                        ui->comboBox->addItem(string);
                    else
                        qDebug("- Unable to fetch product string\n");
                }
                usb_close(udev);
                i++;
            }
         }
     }
    FoundedDev_nubmer=i;
}



void Dialog::on_comboBox_currentIndexChanged(int index)
{
    if(index>-1)
    {
        Current_Dev=index;
        char Comstring[100];
       // int Comret;
        struct usb_dev_handle *Comudev;
        Comudev=usb_open(FoundedDev[Current_Dev]);
        usb_get_string_simple(Comudev, FoundedDev[Current_Dev]->descriptor.iProduct, Comstring, sizeof(Comstring));
        ui->DeviceName->setText(Comstring);
        usb_get_string_simple(Comudev,FoundedDev[Current_Dev]->descriptor.iManufacturer,Comstring,sizeof(Comstring));
        ui->Vender->setText(Comstring);
        usb_get_string_simple(Comudev,FoundedDev[Current_Dev]->descriptor.iSerialNumber,Comstring,sizeof(Comstring));
        ui->Serial->setText(Comstring);
        ui->VenderID->setText(QString::number(FoundedDev[Current_Dev]->descriptor.idVendor));
        ui->ProductID->setText(QString::number(FoundedDev[Current_Dev]->descriptor.idProduct));
        ui->USB->setText(QString::number(FoundedDev[Current_Dev]->descriptor.bcdUSB));
    }
}


void Dialog::on_LED1_stateChanged(int arg1)
{
    char SendData[2];
    if(arg1==0)
    {
        qDebug()<<"LED off";
        SendData[0]='1';//LED Close command
        SendData[1]='1';
        usb_bulk_write(libusb_device, 1, SendData, 2,100);
    }else if(arg1==2)
    {
        qDebug()<<"LED ON";
        SendData[0]='0';//LED Open command
        SendData[1]='1';
        usb_bulk_write(libusb_device, 1, SendData, 2,100);
    }
}








void Dialog::on_DevOpen_clicked()
{
    char Qd[100];
    //int re;

    libusb_device = usb_open(FoundedDev[Current_Dev]);
    usb_get_string_simple(libusb_device, FoundedDev[Current_Dev]->descriptor.iProduct, Qd, sizeof(Qd));
    if(usb_set_configuration(libusb_device, 1))
    {
        qDebug()<<"Set Configuration Faile";
    }

    if (usb_claim_interface(libusb_device, 0) < 0)
    {
        qDebug()<<"Set Interface Faile";
    }
    qDebug()<<"The device is :"<<Qd;

    if (Reveiver.isRunning()) {
        qDebug("isRuning");

    }else
    {
        qDebug("Start listenor");
        connect(&Reveiver,&USB_Listen::received,this,get_usb_data);
        Reveiver.SetDev(libusb_device);
        Reveiver.start();
    }
}


void  Dialog::get_usb_data(unsigned char *dat,unsigned int len)
{
    QString rece = "";
   // ui->textBrowser->append(rece+"\r\n");
    qDebug("get usb data\r\n");
    if(dat[0] == RC522_STX)
    {
        qDebug("fount data\r\n");
        switch(dat[3])
        {
         case RC522_CMD_REQA:
            if(dat[4] == 0x00 && dat[2] == 0x02)
            {
            rece.sprintf("Card Type:%x %x",dat[5],dat[6]);
            }else if(dat[4] == 0x01 && dat[2] ==0x00)
            {
            rece = "req faile";
            }
            ui->base_msg->append(rece);
            qDebug("The req\r\n");
            break;
         case RC522_CMD_ANTICOLLA:
            if(dat[4] == 0x00 && dat[2] == 0x04)
            {
            rece.sprintf("ID:%x %x %x %x",dat[5],dat[6],dat[7],dat[8]);
            }else if(dat[4] == 0x01 && dat[2] ==0x00)
            {
            rece = "anticoll faile";
            }
            ui->base_msg->append(rece);
            break;
         case RC522_CMD_SELECT :
            if(dat[4] == 0x00 && dat[2] == 0x00)
            {
            rece = "Select card success";
            }else if(dat[4] == 0x01 && dat[2] ==0x00)
            {
            rece = "Select card faile";
            }
            ui->base_msg->append(rece);
            break;
         case RC522_CMD_HALTA:
            if(dat[4] == 0x00 && dat[2] == 0x00)
            {
            rece = "halt success";
            }else if(dat[4] == 0x01 && dat[2] ==0x00)
            {
            rece = "halt card faile";
            }
            ui->base_msg->append(rece);
            break;

        case RC522_CMD_VERiFY:
           if(dat[4] == 0x00 && dat[2] == 0x00)
           {
           rece = "Verify success";
           }else if(dat[4] == 0x01 && dat[2] ==0x00)
           {
           rece = "Verify card faile";
           }
           ui->rw->append(rece);
           break;

          default:
            break;
        }
    }
}

void Dialog::on_REQA_clicked()
{
    unsigned char req_cmd[5]= {RC522_STX,0x00,0x00,RC522_CMD_REQA,RC522_ETX};
    usb_bulk_write(libusb_device, 1, (char *)req_cmd, 5,100);
}

void Dialog::on_AnticollA_clicked()
{
    unsigned char anticolla_cmd[5]= {RC522_STX,0x00,0x00,RC522_CMD_ANTICOLLA,RC522_ETX};
    usb_bulk_write(libusb_device, 1,(char *) anticolla_cmd, 5,100);
}

void Dialog::on_select_clicked()
{
    unsigned char select_cmd[5]= {RC522_STX,0x00,0x00,RC522_CMD_SELECT,RC522_ETX};
    usb_bulk_write(libusb_device, 1, (char *)select_cmd, 5,100);
}

void Dialog::on_halta_clicked()
{
    unsigned char halta_cmd[5]= {RC522_STX,0x00,0x00,RC522_CMD_HALTA,RC522_ETX};
    usb_bulk_write(libusb_device, 1, (char *)halta_cmd, 5,100);
}


bool Dialog::Check_hex(QString hex)
{
    int i=0;
    for(;i<hex.length();i++)
    {
        if((hex.at(i)>='0' && hex.at(i)<='9') || (hex.at(i)>='A' && hex.at(i)<='F') || (hex.at(i)>='a' && hex.at(i)<='f'))
        {
            continue;
        }else{
            return false;
        }
    }
    return true;
}
#define KEY_LEN_BLANK   17
/*
 * #define RC522_CMD_VERiFY    0x15
#define RC522_CMD_READ      0x16
#define RC522_CMD_WRITE     0x17
*/
void Dialog::on_Verify_clicked()
{
    qDebug("Str's len:%d\r\n",ui->key->text().length());
    char valid_key[6] ={0};
    //header id length cmd sention a/b key
    unsigned char verify_key_cmd[13]= {RC522_STX,0x00,0x07,RC522_CMD_VERiFY,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,RC522_ETX};

    int sention = ui->section->currentIndex();
    verify_key_cmd[4] = sention;
    if(ui->key4a->isChecked())
    {
        verify_key_cmd[5] = 0x01;
    }else if(ui->key4b->isChecked())
    {
        verify_key_cmd[5] = 0x02;
    }
    bool ok;
    if(ui->key->text().length() == KEY_LEN_BLANK)
    {
        QString sention_key=ui->key->text();
        if(sention_key.at(2) == ' ' && sention_key.at(5) == ' ' &&  sention_key.at(8) == ' ' && sention_key.at(11) == ' ' && sention_key.at(14) == ' ')
        {
            QList <QString> key_byte = sention_key.split(' ');
            int i=6;
            for(QString key_atom:key_byte)
            {
                qDebug()<<key_atom;
                if(key_atom.length()==2)
                {
                    if(Check_hex(key_atom))
                    {
                        verify_key_cmd[i] = key_atom.toInt(&ok,16);
                        qDebug("The str 2 hex is:%x",valid_key[i]);
                        i++;
                    }else{
                        qDebug("key format error\r\n");
                        return;
                    }
                }else
                    return;
            }
        }
    }else
        return;
    usb_bulk_write(libusb_device, 1, (char *)verify_key_cmd, 13,100);
}

void Dialog::on_section_read_clicked()
{
    unsigned char read_cmd[6]= {RC522_STX,0x00,0x00,RC522_CMD_READ,0x00,RC522_ETX};
    read_cmd[4] = ui->block->currentIndex();
    usb_bulk_write(libusb_device, 1, (char *)read_cmd, 6,100);
}

void Dialog::on_section_write_clicked()
{
    unsigned char write_cmd[22]= {RC522_STX,0x00,0x00,RC522_CMD_WRITE,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,RC522_ETX};
    write_cmd[4] = ui->block->currentIndex();
    usb_bulk_write(libusb_device, 1, (char *)write_cmd, 22,100);
}

void Dialog::on_key_textChanged(const QString &arg1)
{
    QString tex =arg1;
    qDebug()<< tex;
}
