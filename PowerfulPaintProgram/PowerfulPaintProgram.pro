#-------------------------------------------------
#
# Project created by QtCreator 2024-12-12T09:12:48
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TARGET = PowerfulPaintProgram
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    canvas.cpp \
    dialog.cpp

HEADERS += \
    canvas.h \
    dialog.h

RESOURCES += \
    images.qrc
