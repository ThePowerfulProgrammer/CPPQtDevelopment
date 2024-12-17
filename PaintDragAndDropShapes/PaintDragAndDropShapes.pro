#-------------------------------------------------
#
# Project created by QtCreator 2024-12-09T12:26:06
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TARGET = PaintDragAndDropShapes
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    paintdialog.cpp \
    shapelist.cpp \
    dragenabledview.cpp

HEADERS += \
    paintdialog.h \
    shapelist.h \
    dragenabledview.h

RESOURCES += \
    images.qrc
