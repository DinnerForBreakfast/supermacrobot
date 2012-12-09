#ifndef KEYPACKET_H
#define KEYPACKET_H

#include <stdint.h>
#include "buspacket.h"

class KeyPacket : public BusPacket
{
public:
	KeyPacket();
	uint16_t code;
	uint16_t value;
};

#endif // KEYPACKET_H
