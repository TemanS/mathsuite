#-------------------------------------------------
#
# Project created by QtCreator 2011-11-29T11:32:15
#
#-------------------------------------------------

QT       += core gui

TARGET = mathsuite
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES +=\
        mathsuite.cpp \
    ../mathtest/mathtest.cpp \
    ../mathtest/defaultdlg.cpp \
    ms-main.cpp \
    ../fractest/fractest.cpp

HEADERS  += mathsuite.h \
    ../mathtest/mathtest.h \
    ../mathtest/defaultdlg.h \
    ../fractest/fractest.h

debug {
    DESTDIR = $$PWD/debug
}

release {
    DESTDIR = $$PWD/release
}

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qpgui/release/ -lqpgui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qpgui/debug/ -lqpgui
else:symbian: LIBS += -lqpgui
else:unix: LIBS += -L$$PWD/../qpgui/ -lqpgui

INCLUDEPATH += $$PWD/../qpgui
DEPENDPATH += $$PWD/../qpgui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../mathpack/release/ -lmathpack
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../mathpack/debug/ -lmathpack
else:symbian: LIBS += -lmathpack
else:unix: LIBS += -L$$PWD/../mathpack/ -lmathpack

INCLUDEPATH += $$PWD/../mathpack
DEPENDPATH += $$PWD/../mathpack


