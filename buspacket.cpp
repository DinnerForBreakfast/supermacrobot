#include "buspacket.h"

BusPacket::BusPacket() : Serializable()
{
	registerItem((void*)&this->id, sizeof(id));
}
