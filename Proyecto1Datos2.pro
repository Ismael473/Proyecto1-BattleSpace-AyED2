#-------------------------------------------------
#
# Project created by QtCreator 2023-03-26T12:42:46
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto1Datos2
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    Score.cpp \
    Health.cpp \
    Button.cpp

HEADERS  += \
    Bullet.h \
    list.hpp \
    Enemy.h \
    Game.h \
    Player.h \
    Score.h \
    Health.h \
    Button.h

FORMS    +=

RESOURCES += \
    res.qrc
