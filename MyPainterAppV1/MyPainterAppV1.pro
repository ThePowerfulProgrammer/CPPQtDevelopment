#-------------------------------------------------
#
# Project created by QtCreator 2024-07-23T08:47:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPainterAppV1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp

HEADERS  += mainwindow.h \
    canvas.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    images/Triangle.png
