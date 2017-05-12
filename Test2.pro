#-------------------------------------------------
#
# Project created by Wiss 2017-03-18T18:33:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test2
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    mymath.cpp \
    chooser.cpp \
    welcome.cpp \
    tutorial.cpp

HEADERS  += mainwindow.h \
    mymath.h \
    chooser.h \
    welcome.h \
    tutorial.h

FORMS    += mainwindow.ui \
    chooser.ui \
    welcome.ui \
    tutorial.ui

INCLUDEPATH += "/usr/local/include/"

LIBS += `pkg-config --libs opencv`


QMAKE += core
QT += widgets

CONFIG += c++11
QT += multimedia

MOBILITY +=multimedia
