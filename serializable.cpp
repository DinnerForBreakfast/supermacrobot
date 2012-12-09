
#include "serializable.h"
#include <stdlib.h>
#include <string.h>
#include <QDebug>

Serializable::Serializable()
{
	this->me.itemSize = 0;
}

void Serializable::registerItem(void *item, szItem itemSize){
	Serialized i;
	i.item = (char*)item;
	i.itemSize = itemSize;
	items.push_back(i);
	me.itemSize += itemSize;
}

int Serializable::getSize()
{
	return me.itemSize;
}

void Serializable::initSerialized(Serialized *s)
{
	s->item = (char*)malloc(getSize());
}

void Serializable::destroySerialized(Serialized *s)
{
	free(s->item);
}

void Serializable::serialize(Serialized *s)
{
	this->offset = s->item;
	std::vector<Serialized>::iterator i;
	for(i = items.begin(); i != items.end(); i++){
		memcpy(this->offset, i->item, i->itemSize);
		this->offset += i->itemSize;
	}
}

void Serializable::deserialize(Serialized *s)
{
	this->offset = s->item;
	std::vector<Serialized>::iterator i;
	for(i = items.begin(); i != items.end(); i++){
		memcpy(i->item, this->offset, i->itemSize);
		this->offset += i->itemSize;
	}
}
