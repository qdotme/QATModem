#include "qatmodem.h"

#include <QDebug>
#include <QTimer>

QATModem::QATModem()
{
}

QATModem::QATModem(const QString &name) : QextSerialPort(name)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onDataAvailable()));
    timer->start(100);
}

void QATModem::initialize() {
    connect(this, SIGNAL(OK()), this, SLOT(onInitializeOK()));
    write(QByteArray("ATZ\r\n"));
}

void QATModem::setVCID(unsigned char vcid) {
    write(QByteArray("AT+VCID=").append('0'+vcid).append('\r').append('\n'));
    m_vcid = vcid;
}

void QATModem::onDataAvailable()
{
    if (bytesAvailable() > 0) {
        QByteArray data = readAll();
        qDebug() << data;
        parseOK(data);
        parseRING(data);
        if (m_vcid == 1)
            parseVCID(data);
    }
}

void QATModem::onInitializeOK()
{
    disconnect(SIGNAL(OK()), this, SLOT(onInitializeOK()));
    setVCID(m_vcid);
}

void QATModem::parseOK(QByteArray data) {
    if (data.indexOf("OK") >= 0)
        emit OK();
}

void QATModem::parseRING(QByteArray data) {
    if (data.indexOf("RING") >= 0)
        emit RING();
}

void QATModem::parseVCID(QByteArray data) {
    int nmbr, nmbre;
    nmbr  = data.indexOf("NMBR=");
    if (nmbr < 0)
        return;
    nmbr += 5;
    nmbre = data.indexOf("\r\n", nmbr);
    if (nmbre < 0)
        return;
    if (nmbre - nmbr == 0)
        return;
    QString n = data.mid(nmbr, nmbre-nmbr);
    qDebug() << "Extracted #" << n;
    emit VCIDNMBR(n);
    QTimer::singleShot(2000, this, SLOT(initialize()));
}
