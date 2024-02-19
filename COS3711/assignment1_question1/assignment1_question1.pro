#-------------------------------------------------
#
# Project created by QtCreator 2024-02-15T14:30:24
#
#-------------------------------------------------

#QT += core: This includes the QtCore module, which provides core non-GUI functionality. This includes data types, threads, QObjects (the base class for all Qt objects), event handling, and more.
#QT += widgets: This includes the QtWidgets module, which provides a set of UI elements to create classic desktop-style user interfaces.
#QT += gui: This includes the QtGui module, which provides the graphical foundation for the QtWidgets module. It’s also used for working with images, fonts, text rendering, and more.

QT       += core
QT       += widgets

QT       -= gui

TARGET = assignment1_question1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    softwarereviewdialog.cpp

HEADERS += \
    softwarereviewdialog.h

OTHER_FILES += \
    stylesheet.qss
