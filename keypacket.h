#ifndef KEYPACKET_H
#define KEYPACKET_H

#include <stdint.h>
#include "buspacket.h"

class KeyPacket : public BusPacket
{
public:
	KeyPacket();
	uint16_t code;
	int value;
};

#endif // KEYPACKET_H
