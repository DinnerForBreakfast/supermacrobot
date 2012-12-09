#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iterator>
#include <vector>
#include <stdint.h>

typedef uint16_t szItem;

struct Serialized {
	char *item;
	szItem itemSize;
};

class Serializable
{
public:
	Serializable();
	void serialize(Serialized *si);
	void deserialize(Serialized *s);
	void registerItem(void *item, szItem itemSize);
	int getSize();
	void initSerialized(Serialized *s);
	void destroySerialized(Serialized *s);

private:
	char *offset;
	Serialized me;
	std::vector<Serialized> items;

};

#endif // SERIALIZABLE_H

