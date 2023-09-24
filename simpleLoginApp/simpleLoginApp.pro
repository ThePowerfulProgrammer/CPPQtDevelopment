#-------------------------------------------------
#
# Project created by QtCreator 2023-06-01T18:45:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simpleLoginApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    sortdialog.cpp \
    finddialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    sortdialog.h \
    finddialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    sortdialog.ui \
    finddialog.ui

RESOURCES += \
    pictures.qrc
