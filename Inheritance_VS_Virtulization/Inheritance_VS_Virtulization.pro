#-------------------------------------------------
#
# Project created by QtCreator 2024-12-20T13:00:42
#
#-------------------------------------------------

QT       += core widgets

QT       -= gui

TARGET = Inheritance_VS_Virtulization
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    student.cpp \
    undergrad.cpp \
    gradstudent.cpp

RESOURCES += \
    images.qrc

OTHER_FILES += \
    typical_Inheritance.png

HEADERS += \
    student.h \
    undergrad.h \
    gradstudent.h
