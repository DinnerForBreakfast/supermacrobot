#include "ckeyboard.h"
#include <device.h>

#define KEYBOARDFILE "/dev/input/event2"

CKeyboard::CKeyboard(const char *devnode, QObject *parent): Device(devnode, parent){}

CKeyboard::~CKeyboard(){}

void CKeyboard::emitSignal(QVariant qv)
{
	emit keyboardSignal(qv);
}
