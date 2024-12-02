#-------------------------------------------------
#
# Project created by QtCreator 2024-12-01T13:10:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ResizeableGraphicsObjects
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    handleitem.cpp \
    resizeablerectitem.cpp

HEADERS  += mainwindow.h \
    handleitem.h \
    resizeablerectitem.h

FORMS    += mainwindow.ui
