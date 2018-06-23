#-------------------------------------------------
#
# Project created by QtCreator 2018-06-18T21:57:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ctoolbox.cpp \
    crectobj.cpp \
    cwindowcallback.cpp

HEADERS  += mainwindow.h \
    ctoolbox.h \
    crectobj.h \
    cwindowcallback.h \
    types.h

FORMS    += mainwindow.ui \
    ctoolbox.ui
