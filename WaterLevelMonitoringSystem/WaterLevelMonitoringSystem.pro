#-------------------------------------------------
#
# Project created by QtCreator 2024-06-07T18:49:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WaterLevelMonitoringSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    indicator.cpp \
    watertank.cpp

HEADERS  += widget.h \
    indicator.h \
    watertank.h

FORMS    += widget.ui
