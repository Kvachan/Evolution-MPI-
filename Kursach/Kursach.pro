#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T08:18:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursach
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agent.cpp \
    food.cpp \
    movingfood.cpp \
    agentsenvironment.cpp \
    eaternfoodobserver.cpp

HEADERS  += mainwindow.h \
    abstractagent.h \
    agent.h \
    food.h \
    movingfood.h \
    agentsenvironment.h \
    environmentobserver.h \
    eatenfoodobserver.h

FORMS    += mainwindow.ui
