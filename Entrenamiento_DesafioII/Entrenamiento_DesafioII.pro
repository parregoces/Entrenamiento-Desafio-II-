TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Matriz.cpp \
        main.cpp

HEADERS += \
    Lista.h \
    Matriz.h \
    Nodo.h

DISTFILES += \
    data.txt
