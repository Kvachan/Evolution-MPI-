#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T08:18:47
#
#-------------------------------------------------


QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursach
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agent.cpp \
    food.cpp \
    movingfood.cpp \
    agentsenvironment.cpp \
    eaternfoodobserver.cpp \
    neuron.cpp \
    links.cpp \
    neuralnetworks.cpp \
    neuralnetworkdrivenagent.cpp \
    optimizableneuralnetworks.cpp \
    globalfunctions.cpp \
    kvrandom.cpp \
    mapelement.cpp \
    chromosomescomparator.cpp \
    fitness.cpp \
    chromosome.cpp \
    iterartionlistener.cpp \
    population.cpp \
    geneticalgorithm.cpp \
    launcher.cpp \
    tournamentenvironmentfitness.cpp

HEADERS  += mainwindow.h \
    abstractagent.h \
    agent.h \
    food.h \
    movingfood.h \
    agentsenvironment.h \
    environmentobserver.h \
    eatenfoodobserver.h \
    neuralnetworkdrivenagent.h \
    neuralnetworks.h \
    neuron.h \
    thresholdfunction.h \
    links.h \
    optimizableneuralnetwork.h \
    kvRandom.h \
    mapelement.h \
    geneticalgorithm.h \
    chromosomescomprator.h \
    fitness.h \
    chromosome.h \
    iterationlistener.h \
    population.h \
    tournamentenvironmentfitness.h

FORMS    += mainwindow.ui

