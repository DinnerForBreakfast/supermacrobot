#include "device.h"
#include "inputmeta.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//#define MOUSEFILE "/dev/input/event3"

Device::Device(const char *devnode, QObject *parent) : QThread(parent)
{
	this->devnode = devnode;
}

Device::~Device(){}

void Device::run() {
	devHandle = open(devnode, O_RDONLY);
	ioctl(devHandle, EVIOCGRAB, 1);
	struct autoplay_event ie;
	QVariant qv;
	while(read(devHandle, &ie, sizeof(struct autoplay_event))){
		qv = QVariant::fromValue(ie);
		emitSignal(qv);
	}
	close(devHandle);
}
