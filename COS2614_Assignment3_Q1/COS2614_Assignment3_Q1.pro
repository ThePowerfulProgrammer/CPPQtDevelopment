#-------------------------------------------------
#
# Project created by QtCreator 2023-08-20T14:05:45
#
#-------------------------------------------------

QT       += core
QT       += widgets
QT       -= gui

TARGET = COS2614_Assignment3_Q1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    transaction.cpp \
    deposit.cpp \
    withdrawal.cpp \
    balanceenquiry.cpp \
    savingsaccount.cpp

HEADERS += \
    transaction.h \
    deposit.h \
    withdrawal.h \
    balanceenquiry.h \
    savingsaccount.h
