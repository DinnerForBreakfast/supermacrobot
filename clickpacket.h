#ifndef CLICKPACKET_H
#define CLICKPACKET_H

#include "buspacket.h"

class ClickPacket : public BusPacket
{
public:
	ClickPacket();
	uint8_t code;
	uint8_t value;
};

#endif // CLICKPACKET_H
