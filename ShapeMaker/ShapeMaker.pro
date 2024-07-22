#-------------------------------------------------
#
# Project created by QtCreator 2024-07-20T18:38:20
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShapeMaker
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    shapecanvas.cpp

HEADERS  += widget.h \
    shapecanvas.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
