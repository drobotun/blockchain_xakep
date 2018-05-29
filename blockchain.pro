TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    block.cpp \
    blockchain.cpp \
    stribog.cpp \
    gost_3411_2012/gost_3411_2012_calc.cpp

HEADERS += \
    block.h \
    blockchain.h \
    gost_3411_2012_calc.h \
    stribog.h \
    gost_3411_2012/gost_3411_2012_calc.h \
    gost_3411_2012/gost_3411_2012_const.h
