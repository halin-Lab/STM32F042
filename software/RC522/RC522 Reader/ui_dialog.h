/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *DeviceName;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Vender;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Serial;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *VenderID;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *ProductID;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *USB;
    QWidget *tab;
    QCheckBox *LED1;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QTextBrowser *base_msg;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *REQA;
    QPushButton *AnticollA;
    QPushButton *select;
    QPushButton *halta;
    QWidget *tab_4;
    QTextBrowser *rw;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *key;
    QRadioButton *key4a;
    QRadioButton *key4b;
    QPushButton *Verify;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QWidget *layoutWidget11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *section;
    QComboBox *block;
    QPushButton *section_read;
    QPushButton *section_write;
    QPushButton *DevOpen;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(560, 432);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 75, 23));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(160, 20, 211, 22));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 60, 531, 361));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 40, 401, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        DeviceName = new QLineEdit(layoutWidget);
        DeviceName->setObjectName(QStringLiteral("DeviceName"));
        DeviceName->setReadOnly(true);

        horizontalLayout->addWidget(DeviceName);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 90, 401, 26));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Vender = new QLineEdit(layoutWidget1);
        Vender->setObjectName(QStringLiteral("Vender"));
        Vender->setReadOnly(true);

        horizontalLayout_2->addWidget(Vender);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 140, 401, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        Serial = new QLineEdit(layoutWidget2);
        Serial->setObjectName(QStringLiteral("Serial"));
        Serial->setReadOnly(true);

        horizontalLayout_3->addWidget(Serial);

        layoutWidget3 = new QWidget(tab_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 190, 401, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        VenderID = new QLineEdit(layoutWidget3);
        VenderID->setObjectName(QStringLiteral("VenderID"));
        VenderID->setReadOnly(true);

        horizontalLayout_4->addWidget(VenderID);

        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(50, 240, 401, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        ProductID = new QLineEdit(layoutWidget4);
        ProductID->setObjectName(QStringLiteral("ProductID"));
        ProductID->setReadOnly(true);

        horizontalLayout_5->addWidget(ProductID);

        layoutWidget5 = new QWidget(tab_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(50, 290, 401, 26));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        USB = new QLineEdit(layoutWidget5);
        USB->setObjectName(QStringLiteral("USB"));
        USB->setReadOnly(true);

        horizontalLayout_6->addWidget(USB);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        LED1 = new QCheckBox(tab);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(10, 10, 109, 26));
        QFont font;
        font.setFamily(QStringLiteral("Aparajita"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        LED1->setFont(font);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 10, 281, 20));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 501, 291));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 10, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        base_msg = new QTextBrowser(tab_3);
        base_msg->setObjectName(QStringLiteral("base_msg"));
        base_msg->setGeometry(QRect(10, 40, 511, 291));
        layoutWidget6 = new QWidget(tab_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 10, 501, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        REQA = new QPushButton(layoutWidget6);
        REQA->setObjectName(QStringLiteral("REQA"));

        horizontalLayout_7->addWidget(REQA);

        AnticollA = new QPushButton(layoutWidget6);
        AnticollA->setObjectName(QStringLiteral("AnticollA"));

        horizontalLayout_7->addWidget(AnticollA);

        select = new QPushButton(layoutWidget6);
        select->setObjectName(QStringLiteral("select"));

        horizontalLayout_7->addWidget(select);

        halta = new QPushButton(layoutWidget6);
        halta->setObjectName(QStringLiteral("halta"));

        horizontalLayout_7->addWidget(halta);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        rw = new QTextBrowser(tab_4);
        rw->setObjectName(QStringLiteral("rw"));
        rw->setGeometry(QRect(10, 160, 501, 171));
        layoutWidget7 = new QWidget(tab_4);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(11, 11, 491, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        key = new QLineEdit(layoutWidget7);
        key->setObjectName(QStringLiteral("key"));

        horizontalLayout_8->addWidget(key);

        key4a = new QRadioButton(layoutWidget7);
        key4a->setObjectName(QStringLiteral("key4a"));
        key4a->setChecked(true);

        horizontalLayout_8->addWidget(key4a);

        key4b = new QRadioButton(layoutWidget7);
        key4b->setObjectName(QStringLiteral("key4b"));

        horizontalLayout_8->addWidget(key4b);

        Verify = new QPushButton(layoutWidget7);
        Verify->setObjectName(QStringLiteral("Verify"));

        horizontalLayout_8->addWidget(Verify);

        layoutWidget8 = new QWidget(tab_4);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(13, 78, 391, 22));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget8);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        lineEdit_4 = new QLineEdit(layoutWidget8);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_10->addWidget(lineEdit_4);

        layoutWidget9 = new QWidget(tab_4);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(13, 134, 391, 22));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget9);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_12->addWidget(label_10);

        lineEdit_6 = new QLineEdit(layoutWidget9);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_12->addWidget(lineEdit_6);

        layoutWidget10 = new QWidget(tab_4);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(13, 106, 391, 22));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget10);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_11->addWidget(label_6);

        lineEdit_5 = new QLineEdit(layoutWidget10);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_11->addWidget(lineEdit_5);

        layoutWidget11 = new QWidget(tab_4);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(13, 50, 391, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget11);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget11);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        lineEdit_3 = new QLineEdit(layoutWidget11);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_9->addWidget(lineEdit_3);

        widget = new QWidget(tab_4);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(430, 50, 77, 106));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        section = new QComboBox(widget);
        section->setObjectName(QStringLiteral("section"));

        verticalLayout->addWidget(section);

        block = new QComboBox(widget);
        block->setObjectName(QStringLiteral("block"));

        verticalLayout->addWidget(block);

        section_read = new QPushButton(widget);
        section_read->setObjectName(QStringLiteral("section_read"));

        verticalLayout->addWidget(section_read);

        section_write = new QPushButton(widget);
        section_write->setObjectName(QStringLiteral("section_write"));

        verticalLayout->addWidget(section_write);

        tabWidget->addTab(tab_4, QString());
        DevOpen = new QPushButton(Dialog);
        DevOpen->setObjectName(QStringLiteral("DevOpen"));
        DevOpen->setGeometry(QRect(410, 20, 75, 23));

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "RC522 Reader", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "\346\237\245\346\211\276USB\350\256\276\345\244\207", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\350\256\276 \345\244\207 \345\220\215 \347\247\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\345\216\202       \345\225\206\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\345\272\217   \345\210\227  \345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", "\345\216\202   \345\225\206  ID\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "\344\272\247   \345\223\201  ID\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "USB\345\215\217\350\256\256\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        LED1->setText(QApplication::translate("Dialog", "LED1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "LED\345\217\212\346\214\211\351\224\256\346\216\247\345\210\266", Q_NULLPTR));
        REQA->setText(QApplication::translate("Dialog", "\345\257\273\345\215\241", Q_NULLPTR));
        AnticollA->setText(QApplication::translate("Dialog", "\351\230\262\345\206\262\347\252\201", Q_NULLPTR));
        select->setText(QApplication::translate("Dialog", "\351\200\211\346\213\251", Q_NULLPTR));
        halta->setText(QApplication::translate("Dialog", "\347\273\210\346\255\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dialog", "\345\237\272\346\234\254\346\223\215\344\275\234", Q_NULLPTR));
        key4a->setText(QApplication::translate("Dialog", "A\347\273\204\345\257\206\347\240\201", Q_NULLPTR));
        key4b->setText(QApplication::translate("Dialog", "B\347\273\204\345\257\206\347\240\201", Q_NULLPTR));
        Verify->setText(QApplication::translate("Dialog", "\351\252\214\350\257\201\345\257\206\345\214\231", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "\345\235\2271", Q_NULLPTR));
        label_10->setText(QApplication::translate("Dialog", "\345\235\2273", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "\345\235\2272", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\345\235\2270", Q_NULLPTR));
        section->clear();
        section->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\346\211\207\345\214\2720", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2721", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2722", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2723", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2724", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2725", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2726", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2727", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2728", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2729", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27210", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27211", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27212", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27213", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27214", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27215", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\27216", Q_NULLPTR)
        );
        block->clear();
        block->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\346\211\207\345\214\2720", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2721", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2722", Q_NULLPTR)
         << QApplication::translate("Dialog", "\346\211\207\345\214\2723", Q_NULLPTR)
        );
        section_read->setText(QApplication::translate("Dialog", "\350\257\273\345\217\226", Q_NULLPTR));
        section_write->setText(QApplication::translate("Dialog", "\345\206\231\345\205\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Dialog", "\350\257\273\345\206\231\346\223\215\344\275\234", Q_NULLPTR));
        DevOpen->setText(QApplication::translate("Dialog", "\346\211\223\345\274\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
