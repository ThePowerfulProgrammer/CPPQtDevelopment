#-------------------------------------------------
#
# Project created by QtCreator 2023-10-17T17:35:24
#
#-------------------------------------------------

QT       += core
QT       += widgets

QT       -= gui

TARGET = workoutPlanner
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    exercise.cpp \
    exercisereader.cpp \
    exercisewriter.cpp \
    exerciselist.cpp \
    exercisedialog.cpp \
    mainwindow.cpp

HEADERS += \
    exercise.h \
    exercisereader.h \
    exercisewriter.h \
    exerciselist.h \
    exercisedialog.h \
    mainwindow.h

OTHER_FILES += \
    documentation.txt
