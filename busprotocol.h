#ifndef BUSPROTOCOL_H
#define BUSPROTOCOL_H

#include <QObject>
#include "keypacket.h"
#include "mousepacket.h"
#include "clickpacket.h"

#define CONFIG_NEW_DEVICE			1
#define MANUFACTURER_ID				2
#define PROD_ID						3
#define DEVICE_DESCRIPTOR			4
#define CONFIGURATION_DESCRIPTOR	5
#define INTERFACE_DESCRIPTOR		6
#define ENDPOINT_DESCRIPTOR			7
#define STRING_DESCRIPTOR			8
#define CONFIG_FINISHED				9
#define COMMAND_PACKET				16
#define CONFIG_REMOVE_DEVICE		32
#define MOUSE_MOVE_EVENT			40
#define MOUSE_CLICK_EVENT			41
#define KEYBOARD_EVENT				64

class BusProtocol : public QObject
{
	Q_OBJECT
public:
	explicit BusProtocol(QObject *parent = 0);
	~BusProtocol();
	virtual void sendPacket(BusPacket p) = 0;
private:
	KeyPacket kp;
	MousePacket mp;
	ClickPacket cp;
signals:

public slots:
	void sendMouseMove(int x, int y);
	void sendKeyEvent(int code, int value);
	void sendMouseClick(int code, int value);

};
#endif // BUSPROTOCOL_H
