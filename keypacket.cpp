#include "keypacket.h"

KeyPacket::KeyPacket() : BusPacket()
{
	this->registerItem((void*)&this->code,sizeof(this->code));
	this->registerItem((void*)&this->value,sizeof(this->value));
}
