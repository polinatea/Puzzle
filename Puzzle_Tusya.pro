#-------------------------------------------------
#
# Project created by QtCreator 2020-05-31
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

Config += resources_big
TARGET = Puzzle_Tusya
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    Game.cpp \


HEADERS  += mainwindow.h \
    form.h \
    Game.h \


FORMS    += mainwindow.ui \
    form.ui

RESOURCES += \
    tusya.qrc
