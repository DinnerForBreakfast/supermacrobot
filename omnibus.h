#ifndef OMNIBUS_H
#define OMNIBUS_H

#include <QObject>
#include <stdint.h>
#include "gpio.h"
#include "busprotocol.h"

#define BUS_WIDTH 8

class OmniBus : public BusProtocol
{
	Q_OBJECT

public:
	explicit OmniBus(int signalIn, int in[BUS_WIDTH],int signalOut, int out[BUS_WIDTH], QObject *parent = 0);
	~OmniBus();
	uint8_t read();
	void write(uint8_t data);
	void sendPacket(BusPacket p);

private:
	GPIO *pinsIn[BUS_WIDTH];
	GPIO *pinsOut[BUS_WIDTH];
	GPIO *signalIn;
	GPIO *signalOut;

signals:
	
public slots:

};

#endif // OMNIBUS_H
