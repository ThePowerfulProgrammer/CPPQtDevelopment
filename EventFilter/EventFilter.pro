#-------------------------------------------------
#
# Project created by QtCreator 2024-05-30T20:32:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EventFilter
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    filter.cpp \
    keyboardfilter.cpp

HEADERS  += widget.h \
    filter.h \
    keyboardfilter.h

FORMS    += widget.ui
