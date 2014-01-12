
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mathsuite
TEMPLATE = app

INCLUDEPATH += $$PWD/../../include
INCLUDEPATH += $$PWD/../../mathtest/src
INCLUDEPATH += $$PWD/../../fractest/src

DEPENDPATH += $$PWD/../../lib

LIBS += -L$$PWD/../../lib/ -lmathpack
LIBS += -L$$PWD/../../lib/ -lqpgui

SOURCES += \
    mathsuite.cpp \
    ms-main.cpp \
    ../../mathtest/src/mathtest.cpp \
    ../../mathtest/src/defaultdlg.cpp \
    ../../fractest/src/fractest.cpp

HEADERS  += \
    mathsuite.h \
    ../../mathtest/src/mathtest.h \
    ../../mathtest/src/defaultdlg.h \
    ../../fractest/src/fractest.h

debug {
    DESTDIR = ../debug
}

release {
    DESTDIR = ../release
}
