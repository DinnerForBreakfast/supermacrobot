#include "cudevenum.h"
#include <libudev.h>
#include <QDebug>
#include "device.h"
#include "cmouse.h"
#include "ckeyboard.h"

CUdevEnum::CUdevEnum(CEventManager *em, QObject *parent) : QObject(parent)
{
	this->em = em;
}

CUdevEnum::~CUdevEnum(){}

void CUdevEnum::go(){

    /* Create the udev object */
    udev = udev_new();
    if (!udev) {
            qDebug("Can't create udev\n");
            //return a.exec();
    }

    /* Create a list of the devices in the 'hidraw' subsystem. */
    enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_subsystem(enumerate, "input");
    udev_enumerate_scan_devices(enumerate);
    devices = udev_enumerate_get_list_entry(enumerate);
    /* For each item enumerated, print out its information.
       udev_list_entry_foreach is a macro which expands to
       a loop. The loop will be executed for each member in
       devices, setting dev_list_entry to a list entry
       which contains the device's path in /sys. */
    udev_list_entry_foreach(dev_list_entry, devices) {
            const char *path;

            /* Get the filename of the /sys entry for the device
               and create a udev_device object (dev) representing it */
            path = udev_list_entry_get_name(dev_list_entry);
            dev = udev_device_new_from_syspath(udev, path);

            /* usb_device_get_devnode() returns the path to the device node
               itself in /dev. */
			const char *devnode = udev_device_get_devnode(dev);
			if(devnode == NULL)continue;
			qDebug("Device Node Path: %s", devnode);

			/* The device pointed to by dev contains information about
			   the hidraw device. In order to get information about the
			   USB device, get the parent device with the
			   subsystem/devtype pair of "usb"/"usb_device". This will
			   be several levels up the tree, but the function will find
			   it.*/
			qDebug() << "devtype: " << udev_device_get_property_value(dev,"ID_INPUT_MOUSE");

			if(udev_device_get_property_value(dev,"ID_INPUT_MOUSE")){
				qDebug() << "attaching mouse";
				Cmouse *mouse = new Cmouse(devnode);
				QObject::connect(mouse, SIGNAL(mouseSignal(QVariant)),
								 em,SLOT(processEvent(QVariant)),
								 Qt::QueuedConnection);
				mouse->start();
			}
			if(udev_device_get_property_value(dev,"ID_INPUT_KEYBOARD")){
				qDebug() << "attaching keyboard";
				CKeyboard *keyboard = new CKeyboard(devnode);
				QObject::connect(keyboard, SIGNAL(keyboardSignal(QVariant)),
								 em,SLOT(processEvent(QVariant)),
								 Qt::QueuedConnection);
				keyboard->start();
			}

            dev = udev_device_get_parent_with_subsystem_devtype(
                   dev,
                   "usb",
				   "usb_device");
            if (!dev) {
					qDebug("Unable to find parent usb device.");
					//continue;
			}

            /* From here, we can call get_sysattr_value() for each file
               in the device's /sys entry. The strings passed into these
               functions (idProduct, idVendor, serial, etc.) correspond
               directly to the files in the directory which represents
               the USB device. Note that USB strings are Unicode, UCS2
               encoded, but the strings returned from
               udev_device_get_sysattr_value() are UTF-8 encoded. */
			qDebug("  VID/PID: %s %s",
                    udev_device_get_sysattr_value(dev,"idVendor"),
                    udev_device_get_sysattr_value(dev, "idProduct"));
			qDebug("  Manufacturer:%s\n  Product:%s",
                    udev_device_get_sysattr_value(dev,"manufacturer"),
                    udev_device_get_sysattr_value(dev,"product"));

    }

    /* Free the enumerator object */
    udev_enumerate_unref(enumerate);
    udev_unref(udev);

}

void CUdevEnum::done(int){

}
