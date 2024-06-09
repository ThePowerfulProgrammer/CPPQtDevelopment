#-------------------------------------------------
#
# Project created by QtCreator 2024-06-08T21:20:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SDL_HandlingKeyboardInput
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp



LIBS += -L"C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/lib" -lSDL2

INCLUDEPATH += "C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/include/SDL2"

OTHER_FILES += \
    ../../../../Downloads/04_key_presses/04_key_presses/down.bmp \
    ../../../../Downloads/04_key_presses/04_key_presses/left.bmp \
    ../../../../Downloads/04_key_presses/04_key_presses/press.bmp \
    ../../../../Downloads/04_key_presses/04_key_presses/right.bmp \
    ../../../../Downloads/04_key_presses/04_key_presses/up.bmp
