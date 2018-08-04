#-------------------------------------------------
#
# Project created by QtCreator 2018-07-27T21:37:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = freeDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    toolboxdialog.cpp \
    model/cshape.cpp \
    model/cline.cpp \
    factory/cshapefactory.cpp \
    modelImpl/csegmentshape.cpp \
    model/idgenerator.cpp \
    modelImpl/cshapeidgenerator.cpp \
    modelImpl/cshapeselect.cpp \
    modelImpl/cshapebase.cpp \
    modelImpl/cdistance.cpp

HEADERS  += mainwindow.h \
    toolboxdialog.h \
    model/cshape.h \
    model/cline.h \
    factory/cshapefactory.h \
    model.h \
    modelImpl/csegmentshape.h \
    model/idgenerator.h \
    modelImpl/cshapeidgenerator.h \
    modelImpl/cshapeselect.h \
    datadefinepub.h \
    modelImpl/cshapebase.h \
    modelImpl/cdistance.h

FORMS    += mainwindow.ui \
    toolboxdialog.ui
