#-------------------------------------------------
#
# Project created by QtCreator 2012-11-03T16:04:44
#
#-------------------------------------------------

QT       -= gui

TARGET = QATModem
TEMPLATE = lib

DEFINES += QATMODEM_LIBRARY

SOURCES += qatmodem.cpp

HEADERS += qatmodem.h\
        QATModem_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

unix:LIBS += -lqextserialport
unix:DEFINES += _TTY_POSIX_

header_files.files = qatmodem.h \
                     QATModem_global.h

unix:header_files.path = /usr/include/QATModem
INSTALLS += header_files
