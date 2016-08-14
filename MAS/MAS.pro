QT += core
QT -= gui

CONFIG += c++11

TARGET = MAS
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

<<<<<<< HEAD
SOURCES += main.cpp \
    core/Environment.cpp

HEADERS += \
    core/Template.h \
    core/Environment.h
=======
SOURCES += main.cpp

HEADERS += \
    environment.h \
    spider.h \
    agent.h
>>>>>>> origin/master
