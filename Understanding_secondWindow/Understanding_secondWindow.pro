#-------------------------------------------------
#
# Project created by QtCreator 2023-05-31T17:30:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Understanding_secondWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    thirddialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    thirddialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    thirddialog.ui
