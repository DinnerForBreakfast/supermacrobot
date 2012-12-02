#include "cmouse.h"
#include "inputmeta.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MOUSEFILE "/dev/input/event2"

Cmouse::Cmouse(QObject *parent) : QThread(parent) {}

Cmouse::~Cmouse(){}

void Cmouse::run() {
	mouse = open(MOUSEFILE, O_RDONLY);
	ioctl(mouse, EVIOCGRAB, 1);
	struct input_event ie;
	QVariant qv;
	while(read(mouse, &ie, sizeof(struct input_event))){
		qv = QVariant::fromValue(ie);
		emit mouseSignal(qv);
	}
	close(mouse);
}
