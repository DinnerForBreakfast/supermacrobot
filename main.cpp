#include <QtGui/QApplication>
#include <qdeclarative.h>
#include "autoplay.h"
#include "directorymodel.h"
#include "cmouse.h"
#include "ckeyboard.h"
#include "ceventmanager.h"
#include "inputmeta.h"
#include "keypacket.h"
#include "omnibus.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	qmlRegisterType<DirectoryModel>("com.autoplay", 1, 0, "DirModel");
	qRegisterMetaType<input_event>();

	Cmouse *mouse = new Cmouse();
	CKeyboard *keyboard = new CKeyboard();
	CEventManager *em = new CEventManager();
	QObject::connect(mouse, SIGNAL(mouseSignal(QVariant)),em,SLOT(processEvent(QVariant)),Qt::QueuedConnection);
	QObject::connect(keyboard, SIGNAL(keyboardSignal(QVariant)),em,SLOT(processEvent(QVariant)),Qt::QueuedConnection);
	//CUsbProtocol *usb = new CUsbProtocol();

	int in[BUS_WIDTH] = {0};
	int out[BUS_WIDTH] = {44,23,26,47,46,27,65,22};
	OmniBus *bus = new OmniBus(0,in,45,out);

	QObject::connect(em, SIGNAL(mouseMove(int,int)), bus, SLOT(sendMouseMove(int,int)));
	QObject::connect(em, SIGNAL(keyEvent(int,int)), bus, SLOT(sendKeyEvent(int,int)));
	//Cpcap *pcap = new Cpcap();
	//pcap->run();
	mouse->start();
	keyboard->start();

	AutoPlay w;
	w.show();

    return a.exec();
}
