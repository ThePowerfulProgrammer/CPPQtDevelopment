#-------------------------------------------------
#
# Project created by QtCreator 2024-07-30T15:33:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customModelReadOnly
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    personmodel.cpp

HEADERS  += widget.h \
    person.h \
    personmodel.h

FORMS    += widget.ui
