TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        button.cpp \
        buttonmanager.cpp \
        factory.cpp \
        main.cpp

HEADERS += \
    bstate.h \
    button.h \
    buttonmanager.h \
    factory.h \
    to_button.h \
    to_buttonmanager.h
