#-------------------------------------------------
#
# Project created by QtCreator 2024-01-20T15:56:39
#
#-------------------------------------------------


QT       += core
QT       += widgets

QT       -= gui

TARGET = GUIBuild1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    exercise.cpp \
    workout.cpp \
    workoutwriter.cpp \
    workoutreader.cpp

HEADERS += \
    exercise.h \
    workout.h \
    workoutwriter.h \
    workoutreader.h
