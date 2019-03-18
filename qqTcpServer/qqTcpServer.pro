#-------------------------------------------------
#
# Project created by QtCreator 2019-03-17T11:55:58
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qqTcpServer
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp

HEADERS  += tcpserver.h
