#-------------------------------------------------
#
# Project created by QtCreator 2023-09-09T20:26:09
#
#-------------------------------------------------

QT       += core
QT       += widgets

QT       -= gui

TARGET = Assignment3_SubQuestion1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../../Item_reader_writer/Item_reader_writer/item.cpp \
    ../../Item_reader_writer/Item_reader_writer/itemreader.cpp \
    ../../Item_reader_writer/Item_reader_writer/itemwriter.cpp \
    itemlist.cpp \
    itemdialog.cpp \
    mainwindow.cpp

OTHER_FILES += \
    ../../Item_reader_writer/Item_reader_writer/infile.txt

HEADERS += \
    ../../Item_reader_writer/Item_reader_writer/item.h \
    ../../Item_reader_writer/Item_reader_writer/itemreader.h \
    ../../Item_reader_writer/Item_reader_writer/itemwriter.h \
    itemlist.h \
    itemdialog.h \
    mainwindow.h
