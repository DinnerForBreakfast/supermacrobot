#ifndef MOUSEPACKET_H
#define MOUSEPACKET_H

#include "buspacket.h"

class MousePacket : public BusPacket
{
public:
	MousePacket();
	uint16_t x;
	uint16_t y;
};

#endif // MOUSEPACKET_H
