TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Application/buttonmanager.cpp \
    Application/factory.cpp \
    Board/button.cpp

HEADERS += \
    Application/buttonmanager.h \
    Application/factory.h \
    Board/button.h \
    Interfaces/tobuttonmanager.h \
    Interfaces/tobutton.h \
    Interfaces/bstate.h
