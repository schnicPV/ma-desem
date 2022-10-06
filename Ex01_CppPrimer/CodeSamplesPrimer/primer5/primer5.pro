TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vehicle.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vehicle.h

