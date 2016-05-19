#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T10:38:43
#
#-------------------------------------------------

QT += network

QT -= gui

TARGET = QtWebsocket
TEMPLATE = lib
CONFIG += staticlib

linux-g++{
    64B{
        message( "QtWebsocket: Configuring for amd64")
        SUFFIX = amd64
        DEFINES += USE64B
	DESTDIR = ./
    } else {
        message( "QtWebsocket: Configuring for i386")
        SUFFIX = i386
	DESTDIR = ./
    }
}
linux-g++-64{
    message( "QtWebsocket: Configuring for amd64")
    SUFFIX = amd64
    DEFINES += USE64B
    DESTDIR = ./
}
linux-g++-32{
    message( "QtWebsocket: Configuring for i386")
    DESTDIR = ./
    SUFFIX = i386
}
linux-avr32-g++{
    message( "QtWebsocket: Configuring for Avr32")
    DESTDIR = ./
    QMAKE_CFLAGS_RELEASE -= -O2
    QMAKE_CFLAGS_RELEASE *= -O
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CXXFLAGS_RELEASE *= -O
    SUFFIX = avr
}
linux-arm-gnueabi-g++|linux-armel-gnueabi-g++{
    message( "QtWebsocket: Configuring for ARMv5")
    DEFINES += P2NRGENABLE
    DESTDIR = ./
    SUFFIX = arm
}
linux-armv6-gnueabihf-g++|linux-rpi-gnueabihf-g++{
    message( "QtWebsocket: Configuring for ARMv6 vfp")
    DESTDIR = ./
    SUFFIX = armv6
}
linux-armhf-gnueabi-g++|linux-armG1-gnueabihf-g++{
    message( "QtWebsocket: Configuring for ARMv7")
    DESTDIR = ./
    SUFFIX = armv7
}
linux-armhfandroid-gnueabi-g++{
    message( "QtWebsocket: Configuring for ARMv7 Android")
    DESTDIR = ./ 
    SUFFIX = armv7_android
}
linux-arm-uclibcgnueabi-g++{
    message( "QtWebsocket: Configuring for BCM-97445C")
    DESTDIR = ./
    SUFFIX = bcm
}
linux-arm-gnueabihf-g++|linux-armbcm-gnueabihf-g++{
    message("QtWebsocket: Configuring for BCM-ARMHF")
    DESTDIR = ./
    SUFFIX = bcmhf
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

