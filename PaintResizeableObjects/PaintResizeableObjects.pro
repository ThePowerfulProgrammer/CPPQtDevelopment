#-------------------------------------------------
#
# Project created by QtCreator 2024-12-03T11:40:59
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TARGET = PaintResizeableObjects
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    resizeablerect.cpp \
    circleadjustitem.cpp

OTHER_FILES += \
    todo.txt

HEADERS += \
    dialog.h \
    resizeablerect.h \
    circleadjustitem.h
