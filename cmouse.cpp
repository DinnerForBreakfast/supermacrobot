#include "cmouse.h"

Cmouse::Cmouse(const char *devnode, QObject *parent):Device(devnode,parent){}

Cmouse::~Cmouse(){}

void Cmouse::emitSignal(QVariant qv)
{
	emit mouseSignal(qv);
}
