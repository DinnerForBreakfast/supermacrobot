#include "busprotocol.h"

BusProtocol::BusProtocol(QObject *parent) : QObject(parent) {}

BusProtocol::~BusProtocol(){}

void BusProtocol::sendMouseMove(int x, int y) {
	mp.id = MOUSE_MOVE_EVENT;
	mp.x = x;
	mp.y = y;
	this->sendPacket(mp);
}

void BusProtocol::sendKeyEvent(int code, int value) {
	kp.id = KEYBOARD_EVENT;
	kp.code = code;
	kp.value = value;
	this->sendPacket(mp);
}

void BusProtocol::sendMouseClick(int code, int value)
{
	kp.id = MOUSE_CLICK_EVENT;
	kp.code = code;
	kp.value = value;
	this->sendPacket(kp);
}
