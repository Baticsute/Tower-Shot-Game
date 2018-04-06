#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T23:41:44
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    tower.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp \
    buildlevel1towericon.cpp \
    level1tower.cpp \
    level2tower.cpp \
    buildlevel2towericon.cpp \
    level3tower.cpp \
    buildlevel3towericon.cpp \
    score.cpp \
    health.cpp \
    Button.cpp

HEADERS  += mainwindow.h \
    tower.h \
    game.h \
    bullet.h \
    enemy.h \
    buildlevel1towericon.h \
    level1tower.h \
    level2tower.h \
    buildlevel2towericon.h \
    level3tower.h \
    buildlevel3towericon.h \
    score.h \
    health.h \
    Button.h

FORMS    +=
