#-------------------------------------------------
#
# Project created by QtCreator 2019-03-07T20:14:08
#
#-------------------------------------------------

QT       += core gui
QT  += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqProject
TEMPLATE = app


SOURCES += main.cpp\
        qqmainwindow.cpp \
    registerwindow.cpp

HEADERS  += qqmainwindow.h \
    registerwindow.h

FORMS    += qqmainwindow.ui

RESOURCES += \
    image.qrc
