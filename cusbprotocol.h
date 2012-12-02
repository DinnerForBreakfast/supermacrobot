#ifndef CUSBPROTOCOL_H
#define CUSBPROTOCOL_H

#include <libusb.h>
#include <QObject>

class CUsbProtocol
{
public:
    CUsbProtocol();
    void printdev(libusb_device *dev);


};

#endif // CUSBPROTOCOL_H
