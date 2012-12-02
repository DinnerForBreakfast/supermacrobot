
#include "serializable.h"
#include <stdlib.h>
#include <string.h>

Serializable::Serializable()
{
	this->me.itemSize = 0;
}

void Serializable::registerItem(void *item, szItem itemSize){
	SerialInfo i;
	i.item = (char*)item;
	i.itemSize = itemSize;
	items.push_back(i);
	me.itemSize += itemSize;
}

int Serializable::getSize()
{
	return me.itemSize;
}

SerialInfo Serializable::serialize()
{
	me.item = (char*)malloc(me.itemSize);
	this->offset = this->me.item;
	std::vector<SerialInfo>::iterator i;
	for(i = items.begin(); i != items.end(); i++){
		memcpy(this->offset, i->item, i->itemSize);
		this->offset += i->itemSize;
	}
	return me;
}

void Serializable::deserialize(SerialInfo s)
{
	this->offset = s.item;
	std::vector<SerialInfo>::iterator i;
	for(i = items.begin(); i != items.end(); i++){
		memcpy(i->item, this->offset, i->itemSize);
		this->offset += i->itemSize;
	}
	free(s.item);
}
