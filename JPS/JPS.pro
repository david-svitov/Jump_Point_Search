#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T20:49:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JPS
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        jps.cpp \
    search.cpp \
    robot.cpp \
    point.cpp \
    map.cpp

HEADERS  += jps.h \
    robot.h \
    point.h \
    map.h

FORMS    += jps.ui
