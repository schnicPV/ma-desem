TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    form.cpp \
    line.cpp \
    rectangle.cpp \
    circle.cpp \
    point.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    form.h \
    line.h \
    rectangle.h \
    circle.h \
    point.h

