#include "busprotocol.h"

BusProtocol::BusProtocol(QObject *parent) : QObject(parent) {}

BusProtocol::~BusProtocol(){}

void BusProtocol::sendKeyEvent(int code, int value) {
	kp.id = KEYBOARD_EVENT;
	kp.code = code;
	kp.value = value;
	this->sendPacket(kp);
}

void BusProtocol::sendMouseMove(int x, int y) {
	mp.id = MOUSE_MOVE_EVENT;
	mp.x = x;
	mp.y = y;
	this->sendPacket(mp);
}

void BusProtocol::sendMouseClick(int code, int value)
{
	cp.id = MOUSE_CLICK_EVENT;
	cp.code = code;
	cp.value = value;
	this->sendPacket(cp);
}
