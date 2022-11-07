TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

DEFINES += TC_QTCONSOLE

include(xf.pri)

INCLUDEPATH += \
	. \
	xf \

SOURCES += \
	main.cpp \
	blinker.cpp \
    button.cpp \
    buttonmanager.cpp \
    factory.cpp \
    testbench.cpp

HEADERS += \
	blinker.h \
    button.h \
    interface.h \
    buttonmanager.h \
    factory.h \
    testbench.h

