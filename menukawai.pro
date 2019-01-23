#-------------------------------------------------
#
# Project created by QtCreator 2018-10-03T14:26:21
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = menukawai
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu1.cpp \
    personaje.cpp \
    game.cpp \
    disparos.cpp \
    vida.cpp \
    villanos.cpp \
    proyectiles.cpp \
    trampa.cpp \
    aliens.cpp \
    caida.cpp \
    piedritas.cpp \
    menus2.cpp \
    gemare.cpp \
    histo1.cpp \
    histo2.cpp \
    histo3.cpp \
    histo4.cpp \
    plumas.cpp \
    play2.cpp \
    segundo.cpp \
    espada.cpp \
    prum.cpp \
    jefe.cpp \
    huevi.cpp \
    alien2.cpp

QT+= multimedia

HEADERS += \
        mainwindow.h \
    menu1.h \
    personaje.h \
    game.h \
    disparos.h \
    vida.h \
    villanos.h \
    proyectiles.h \
    trampa.h \
    aliens.h \
    caida.h \
    piedritas.h \
    menus2.h \
    gemare.h \
    histo1.h \
    histo2.h \
    histo3.h \
    histo4.h \
    plumas.h \
    play2.h \
    segundo.h \
    espada.h \
    prum.h \
    jefe.h \
    huevi.h \
    alien2.h

FORMS += \
        mainwindow.ui \
    menu1.ui \
    game.ui \
    menus2.ui \
    histo1.ui \
    histo2.ui \
    histo3.ui \
    histo4.ui \
    play2.ui \
    segundo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    juegokawai.qrc

DISTFILES += \
    música/OmegaVH19_Trim (online-audio-converter.com).mp3 \
    música/OmegaVH19_Trim (online-audio-converter.com).mp3
