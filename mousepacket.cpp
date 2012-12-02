#include "mousepacket.h"

MousePacket::MousePacket() : BusPacket()
{
	registerItem((void*)&this->x,sizeof(this->x));
	registerItem((void*)&this->y,sizeof(this->y));
}
