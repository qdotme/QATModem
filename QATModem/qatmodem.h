#ifndef QATMODEM_H
#define QATMODEM_H

#include "QATModem_global.h"

#include "qextserialport.h"


class QATMODEMSHARED_EXPORT QATModem : public QextSerialPort
{
    Q_OBJECT
public:
    QATModem();
    QATModem(const QString &name);
    void setVCID(unsigned char vcid);
public slots:
    void onDataAvailable();
    void onInitializeOK();
    void initialize();
signals:
    void VCIDNMBR(QString n);
    void OK();
    void RING();
private:
    int m_vcid;

    void parseOK(QByteArray data);
    void parseVCID(QByteArray data);
    void parseRING(QByteArray data);
};

#endif // QATMODEM_H
