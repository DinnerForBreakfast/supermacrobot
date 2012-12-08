#include "clickpacket.h"

ClickPacket::ClickPacket() : BusPacket()
{
	this->registerItem((void*)&this->code,sizeof(this->code));
	this->registerItem((void*)&this->value,sizeof(this->value));
}
