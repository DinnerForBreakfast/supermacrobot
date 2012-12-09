#include "busprotocol.h"

BusProtocol::BusProtocol(QObject *parent) : QObject(parent) {
	kp.initSerialized(&skp);
	mp.initSerialized(&smp);
	cp.initSerialized(&scp);
}

BusProtocol::~BusProtocol(){}

void BusProtocol::sendKeyEvent(int code, int value) {
	kp.id = KEYBOARD_EVENT;
	kp.code = code;
	kp.value = value;
	kp.serialize(&skp);
	this->sendPacket(&skp);
}

void BusProtocol::sendMouseMove(int x, int y) {
	mp.id = MOUSE_MOVE_EVENT;
	mp.x = x;
	mp.y = y;
	mp.serialize(&smp);
	this->sendPacket(&smp);
}

void BusProtocol::sendMouseClick(int code, int value)
{
	cp.id = MOUSE_CLICK_EVENT;
	cp.code = code;
	cp.value = value;
	cp.serialize(&scp);
	this->sendPacket(&scp);
}
