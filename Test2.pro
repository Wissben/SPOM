#-------------------------------------------------
#
# Project created by QtCreator 2017-03-18T18:33:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test2
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    selector.cpp \
    method.cpp

HEADERS  += mainwindow.h \
    selector.h \
    method.h

FORMS    += mainwindow.ui \
    selector.ui

INCLUDEPATH += "/usr/local/include/"

LIBS += `pkg-config --libs opencv`


QMAKE += core
QT += widgets

