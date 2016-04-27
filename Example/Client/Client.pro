#-------------------------------------------------
#
# Project created by QtCreator 2013-02-23T08:54:24
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

DESTDIR = ./
OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

INCLUDEPATH += ../../QtWebsocket
DEPENDPATH += ../../QtWebsocket

SOURCES += \
    main.cpp \
    Client.cpp \
    MultiInputDialog.cpp

HEADERS += \
    QWsSocket.h \
    Client.h \
    MultiInputDialog.h

FORMS += Client.ui

win32:CONFIG(release, debug|release): LIBS += -L../../QtWebsocket/release/ -lQtWebsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L../../QtWebsocket/debug/ -lQtWebsocket
else:unix:!symbian: LIBS += -L../../QtWebsocket/ -lQtWebsocket

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += ../../QtWebsocket/release/libQtWebsocket.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += ../../QtWebsocket/debug/libQtWebsocket.a
else:unix:!symbian: PRE_TARGETDEPS += ../../QtWebsocket/libQtWebsocket.a
