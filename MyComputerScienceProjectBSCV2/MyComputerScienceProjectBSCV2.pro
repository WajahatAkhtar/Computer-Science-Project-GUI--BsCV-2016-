#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T14:56:18
#
#-------------------------------------------------

QT       += core gui

TARGET = MyComputerScienceProjectBSCV2
TEMPLATE = app


SOURCES += main.cpp\
        gamemainwindow.cpp \
    player.cpp \
    ball.cpp \
    obsticles_inside_scene.cpp \
    score.cpp \
    scoringitem.cpp

HEADERS  += gamemainwindow.h \
    player.h \
    ball.h \
    obsticles_inside_scene.h \
    score.h \
    scoringitem.h

FORMS    += gamemainwindow.ui

RESOURCES += \
    Pixmap.qrc \
    Sound.qrc
