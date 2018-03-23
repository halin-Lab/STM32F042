#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T16:00:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ListUsb_2
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    libusb/libusb_dyn.c \
    usb_listen.cpp

HEADERS  += dialog.h \
    libusb/libusb_dyn.h \
    usb_listen.h

FORMS    += dialog.ui


