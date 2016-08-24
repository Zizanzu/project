QT += core
QT -= gui

TEMPLATE = app

TARGET = MAS
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    core/template.cpp \
    core/environment.cpp \
    magent/spider.cpp \
    magent/spidersegmentation.cpp \
    core/config.cpp

HEADERS += \
    core/environment.h \
    core/agent.h \
    core/template.h \
    magent/spider.h \
    magent/agent.h \
    magent/spidersegmentation.h \
    core/segmentation.h \
    magent/mas.h \
    agentsegmentation.h \
    magent/agentsegmentation.h \
    core/spiderinfo.h \
    core/config.h

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

