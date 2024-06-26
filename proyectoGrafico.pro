QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomba.cpp \
    destruibles.cpp \
    enemigo.cpp \
    explosion.cpp \
    main.cpp \
    mainwindow.cpp \
    personaje.cpp \
    solidos.cpp

HEADERS += \
    bomba.h \
    destruibles.h \
    enemigo.h \
    explosion.h \
    mainwindow.h \
    personaje.h \
    solidos.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

RC_ICONS = icono.ico

QT += multimedia

