#ifndef BUSPACKET_H
#define BUSPACKET_H

#include <stdint.h>
#include "serializable.h"

class BusPacket : public Serializable
{
public:
	BusPacket();
	uint8_t id;
};

#endif // BUSPACKET_H
