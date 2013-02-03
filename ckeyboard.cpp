#include "ckeyboard.h"
#include "inputmeta.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define KEYBOARDFILE "/dev/input/event2"

CKeyboard::CKeyboard(QObject *parent) : QThread(parent){}

CKeyboard::~CKeyboard() {}

void CKeyboard::run() {
	keyboard = open(KEYBOARDFILE, O_RDONLY);
	ioctl(keyboard, EVIOCGRAB, 1);
	struct autoplay_event ie;
	QVariant qv;
	while(read(keyboard, &ie, sizeof(struct input_event))){
		qv = QVariant::fromValue(ie);
		emit keyboardSignal(qv);
	}
	close(keyboard);
}
