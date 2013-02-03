#include "cmouse.h"
#include "inputmeta.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MOUSEFILE "/dev/input/event3"

Cmouse::Cmouse(QObject *parent) : QThread(parent) {}

Cmouse::~Cmouse(){}

void Cmouse::run() {
	mouse = open(MOUSEFILE, O_RDONLY);
	ioctl(mouse, EVIOCGRAB, 1);
	struct autoplay_event ie;
	QVariant qv;
	while(read(mouse, &ie, sizeof(struct input_event))){
		qv = QVariant::fromValue(ie);
		emit mouseSignal(qv);
	}
	close(mouse);
}
