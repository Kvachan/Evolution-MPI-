#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T02:09:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursach
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    predator.cpp \
    food.cpp \
    plant_eating.cpp \
    environment.cpp

HEADERS  += mainwindow.h \
    basicagent.h \
    predator.h \
    food.h \
    plant_eating.h \
    environment.h

FORMS    += mainwindow.ui

QMAKE_LFLAGS
