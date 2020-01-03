#-------------------------------------------------
#
# Project created by QtCreator 2018-12-24T21:03:42
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGame
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    player.cpp \
    gameui.cpp \
    addhealth.cpp \
    gameover.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    health.h \
    score.h \
    player.h \
    gameui.h \
    addhealth.h \
    gameover.h

FORMS    += \
    gameui.ui \
    gameover.ui \
    gameui.ui \
    gameover.ui

RESOURCES += \
    resources.qrc
