#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iterator>
#include <vector>
#include <stdint.h>

typedef uint16_t szItem;

struct SerialInfo {
	char *item;
	szItem itemSize;
};

class Serializable
{
public:
	Serializable();
	SerialInfo serialize();
	void deserialize(SerialInfo s);
	void registerItem(void *item, szItem itemSize);
	int getSize();

private:
	char *offset;
	SerialInfo me;
	std::vector<SerialInfo> items;

};

#endif // SERIALIZABLE_H

