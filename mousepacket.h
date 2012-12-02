#ifndef MOUSEPACKET_H
#define MOUSEPACKET_H

#include "buspacket.h"

class MousePacket : public BusPacket
{
public:
	MousePacket();
	int x;
	int y;
};

#endif // MOUSEPACKET_H
