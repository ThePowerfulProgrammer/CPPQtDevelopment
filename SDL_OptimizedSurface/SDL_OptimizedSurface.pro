#-------------------------------------------------
#
# Project created by QtCreator 2024-06-11T18:41:57
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SDL_OptimizedSurface
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


LIBS += -L"C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/lib" -lSDL2

INCLUDEPATH += "C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/include/SDL2"

OTHER_FILES += \
    ../../../../Downloads/05_optimized_surface_loading_and_soft_stretching/05_optimized_surface_loading_and_soft_stretching/stretch.bmp
