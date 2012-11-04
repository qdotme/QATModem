#include <QCoreApplication>

#include "qatmodem.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QATModem modem("/dev/ttyACM0");
    modem.setBaudRate(BAUD115200);
    modem.setFlowControl(FLOW_HARDWARE);
    modem.open(QIODevice::ReadWrite | QIODevice::Unbuffered);
    modem.initialize();
    modem.connect(&modem, SIGNAL(RING()), &modem, SLOT(initialize()));
    modem.setVCID(1);

    return a.exec();
}
