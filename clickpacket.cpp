#include "clickpacket.h"

ClickPacket::ClickPacket()
{
	this->registerItem((void*)&this->code,sizeof(this->code));
	this->registerItem((void*)&this->value,sizeof(this->value));
}
