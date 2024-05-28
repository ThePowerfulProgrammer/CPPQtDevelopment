#-------------------------------------------------
#
# Project created by QtCreator 2024-05-28T09:14:21
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SDL_ImageRendering
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


LIBS += -L"C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/lib" -lSDL2

INCLUDEPATH += "C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/include/SDL2"

OTHER_FILES += \
    ../../../../Downloads/02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen/hello_world.bmp
