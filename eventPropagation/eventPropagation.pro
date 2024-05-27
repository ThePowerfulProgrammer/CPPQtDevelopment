#-------------------------------------------------
#
# Project created by QtCreator 2024-05-27T09:44:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eventPropagation
TEMPLATE = app

CONFIG += c++11



SOURCES += main.cpp\
        widget.cpp \
    parentbutton.cpp \
    childbutton.cpp

HEADERS  += widget.h \
    parentbutton.h \
    childbutton.h

FORMS    += widget.ui
