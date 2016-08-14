QT += core
QT -= gui

CONFIG += c++11

TARGET = MAS
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += "C:/opencv/build/include"
LIBS += -LC:\\opencv\\build\\x64\\vc12\\bin\*.dll

SOURCES += main.cpp \
    core/Environment.cpp \
    core/Template.cpp

HEADERS += \
    core/Template.h \
    core/Environment.h



