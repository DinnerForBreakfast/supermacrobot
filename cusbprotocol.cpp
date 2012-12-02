#include "cusbprotocol.h"
#include <libusb.h>

CUsbProtocol::CUsbProtocol(){
    libusb_device **usbdevs;
    libusb_context *ctx;

    int r;
    ssize_t cnt;
    r = libusb_init(&ctx);

    if(r < 0) {
        qDebug("Init Error %i",r);
    }

    libusb_set_debug(ctx, 3);

    cnt = libusb_get_device_list(ctx, &usbdevs); //get the list of devices
    if(cnt < 0) {
        qDebug("Get Device Error"); //there was an error
    }
    qDebug("%i Devices in list.",(int)cnt); //print total number of usb devices
    ssize_t iii; //for iterating through the list
    for(iii = 0; iii < cnt; iii++) {
        this->printdev(usbdevs[iii]); //print specs of this device
    }
    libusb_free_device_list(usbdevs, 1); //free the list, unref the devices in it
    libusb_exit(ctx); //close the session
}

void CUsbProtocol::printdev(libusb_device *dev) {
    libusb_device_descriptor desc;
    int r = libusb_get_device_descriptor(dev, &desc);
    if (r < 0) {
        qDebug("failed to get device descriptor");
        return;
    }
    qDebug("Number of possible configurations: %i  ",(int)desc.bNumConfigurations);
    qDebug("Device Class: %i  VendorID: %i  ProductID: %i",(int)desc.bDeviceClass,desc.idVendor,desc.idProduct);
    libusb_config_descriptor *config;
    libusb_get_config_descriptor(dev, 0, &config);
    qDebug("Interfaces: %i",(int)config->bNumInterfaces);
    const libusb_interface *inter;
    const libusb_interface_descriptor *interdesc;
    const libusb_endpoint_descriptor *epdesc;
    for(int ii=0; ii<(int)config->bNumInterfaces; ii++) {
        inter = &config->interface[ii];
        qDebug("Number of alternate settings: %i",inter->num_altsetting);
        for(int jj=0; jj<inter->num_altsetting; jj++) {
            interdesc = &inter->altsetting[jj];
            qDebug("Interface Number: %i",(int)interdesc->bInterfaceNumber);
            qDebug("Number of endpoints: %i",(int)interdesc->bNumEndpoints);
            for(int kk=0; kk<(int)interdesc->bNumEndpoints; kk++) {
                epdesc = &interdesc->endpoint[kk];
                qDebug("Descriptor Type: %i",(int)epdesc->bDescriptorType);
                qDebug("EP Address: %i",(int)epdesc->bEndpointAddress);
            }
        }
    }

    libusb_free_config_descriptor(config);
}
