#include "omnibus.h"
#include "busprotocol.h"
#include "serializable.h"
#include <QDebug>

OmniBus::OmniBus(int signalIn, int in[BUS_WIDTH],int signalOut, int out[BUS_WIDTH], QObject *parent) :
	BusProtocol(parent)
{
	this->signalIn = new GPIO(signalIn, GPIO::IN);
	this->signalOut = new GPIO(signalOut, GPIO::OUT);
	for(int i = 0;i<BUS_WIDTH;i++){
		if(in[i] > 0){//is it a valid pin?
			pinsIn[i] = new GPIO(in[i], GPIO::IN);
		}else pinsIn[i] = NULL;
		if(out[i] > 0){//is it a valid pin?
			pinsOut[i] = new GPIO(out[i], GPIO::OUT);
		}else pinsOut[i] = NULL;
	}
}

OmniBus::~OmniBus()
{
	delete signalIn;
	delete signalOut;
	for(int i = 0;i<BUS_WIDTH;i++){
		if(pinsIn[i] != NULL){
			delete pinsIn[i];
		}
		if(pinsOut[i] != NULL){
			delete pinsOut[i];
		}
	}
}

uint8_t OmniBus::read()
{
	return 0;
}

void OmniBus::write(uint8_t data)
{
	for(int i = 0;i<BUS_WIDTH;i++){
		pinsOut[i]->setValue(data & (1 << i));
	}
	signalOut->setValue(1);
	signalOut->setValue(0);
}

void OmniBus::sendPacket(BusPacket p)
{
	qDebug("packet size: %i", p.getSize());
	SerialInfo si = p.serialize();
	for(int i = 0;i < si.itemSize;i++){
		write(si.item[i]);
	}
	free(si.item);
}
