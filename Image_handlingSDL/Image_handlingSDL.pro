#-------------------------------------------------
#
# Project created by QtCreator 2024-06-14T18:45:54
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Image_handlingSDL
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


LIBS += -L"C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/lib" -lSDL2
LIBS += -L"C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/i686-w64-mingw32/lib" -lSDL2_image


INCLUDEPATH += "C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2-devel-2.30.3-mingw/SDL2-2.30.3/i686-w64-mingw32/include/SDL2"
INCLUDEPATH += "C:/Users/ashis/OneDrive/Desktop/SDL Development/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/i686-w64-mingw32/include/SDL2"

OTHER_FILES += \
    ../../../../Downloads/06_extension_libraries_and_loading_other_image_formats/06_extension_libraries_and_loading_other_image_formats/loaded.png
