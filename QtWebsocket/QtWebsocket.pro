#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T10:38:43
#
#-------------------------------------------------

QT += network

QT -= gui

TARGET = QtWebsocket
TEMPLATE = lib
CONFIG += staticlib prop

linux-g++{
    64B{
        SUFFIX = amd64
    } else {
        SUFFIX = i386
    }
}
linux-g++-64{
    SUFFIX = amd64
}
linux-g++-32{
    SUFFIX = i386
}
linux-avr32-g++{
    QMAKE_CFLAGS_RELEASE -= -O2
    QMAKE_CFLAGS_RELEASE *= -O
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CXXFLAGS_RELEASE *= -O
    SUFFIX = avr
}
linux-arm-gnueabi-g++|linux-armel-gnueabi-g++{
    SUFFIX = arm
}
linux-armv6-gnueabihf-g++|linux-rpi-gnueabihf-g++{
    SUFFIX = armv6
}
linux-armhf-gnueabi-g++|linux-armG1-gnueabihf-g++{
    SUFFIX = armv7
}
linux-armhfandroid-gnueabi-g++{
    SUFFIX = armv7_android
}
linux-arm-uclibcgnueabi-g++{
    SUFFIX = bcm
}
linux-arm-gnueabihf-g++|linux-armbcm-gnueabihf-g++{
    SUFFIX = bcmhf
}

CONFIG(prop) {
    DESTDIR = ../../../libs/$${SUFFIX}
} else {
    DESTDIR = ./bin/$${SUFFIX}
}

OBJECTS_DIR = $${DESTDIR}/.obj$${SUFFIX}
MOC_DIR = $${DESTDIR}/.moc$${SUFFIX}
RCC_DIR = $${DESTDIR}/.rcc$${SUFFIX}
UI_DIR = $${DESTDIR}/.ui$${SUFFIX}

SOURCES += \
    QWsServer.cpp \
    QWsSocket.cpp \
    QWsHandshake.cpp \
    QWsFrame.cpp \
    QTlsServer.cpp \
    functions.cpp

HEADERS += \
    QWsServer.h \
    QWsSocket.h \
    QWsHandshake.h \
    QWsFrame.h \
    QTlsServer.h \
    functions.h \
    WsEnums.h

