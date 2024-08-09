#-------------------------------------------------
#
# Project created by QtCreator 2024-08-02T21:09:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomModelsTableModel
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp\
        person.cpp\
        personmodel.cpp \
    persondelegate.cpp \
    stareditor.cpp \
    stardelegate.cpp


HEADERS  += widget.h person.h personmodel.h \
    persondelegate.h \
    stareditor.h \
    stardelegate.h

FORMS    += widget.ui
