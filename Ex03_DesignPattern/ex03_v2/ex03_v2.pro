TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Application/buttonmanager.cpp \
        Application/factory.cpp \
        Board/button.cpp \
        Interfaces/bstate.cpp \
        main.cpp

HEADERS += \
    Application/buttonmanager.h \
    Application/factory.h \
    Board/button.h \
    Interfaces/bstate.h \
    Interfaces/to_button.h \
    Interfaces/to_buttonmanager.h
