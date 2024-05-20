#-------------------------------------------------
#
# Project created by QtCreator 2024-05-03T15:54:37
#
#-------------------------------------------------

QT       += core

QT       += gui

QT       += widgets

QT       += sql

TARGET = databaseInteraction
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32: LIBS += -L$$PWD/../../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include
DEPENDPATH += $$PWD/../../../../../../Program Files/MySQL/MySQL Connector C 6.1/include
