#include "buspacket.h"

BusPacket::BusPacket() : Serializable()
{
	registerItem((void*)id, sizeof(id));
}
