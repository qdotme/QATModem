#-------------------------------------------------
#
# Project created by QtCreator 2012-11-03T21:57:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = demo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

unix: DEFINES += _TTY_POSIX_
unix: LIBS += -lqextserialport


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QATModem/ -lQATModem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QATModem/ -lQATModemd
else:unix: LIBS += -L$$OUT_PWD/../../QATModem/ -lQATModem

INCLUDEPATH += $$PWD/../../QATModem
DEPENDPATH += $$PWD/../../QATModem
