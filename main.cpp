#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QDeclarativeContext>
#include "mainwindow.h"
#include "directorymodel.h"
#include "cmouse.h"
#include "ckeyboard.h"
#include "ceventmanager.h"
#include "inputmeta.h"
#include "keypacket.h"
#include "omnibus.h"
#include "supermacrobot.h"
#include "singleton.h"
#include "cudevenum.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	qmlRegisterType<DirectoryModel>("SuperMacroBot",1,0,"DirModel");
	qRegisterMetaType<input_event>();

	CEventManager *em = &Singleton<CEventManager>::Instance();
	//CUsbProtocol *usb = new CUsbProtocol();

	//init the bus
	int in[BUS_WIDTH] = {0};
	int out[BUS_WIDTH] = {44,23,26,47,46,27,65,22};
	OmniBus *bus = new OmniBus(0,in,45,out);

	QObject::connect(em, SIGNAL(mouseMove(int,int)),
					 bus, SLOT(sendMouseMove(int,int)));

	QObject::connect(em, SIGNAL(keyEvent(int,int)),
					 bus, SLOT(sendKeyEvent(int,int)));

	QObject::connect(em, SIGNAL(mouseClick(int,int)),
					 bus, SLOT(sendMouseClick(int,int)));

	//Cpcap *pcap = new Cpcap();
	//pcap->run();

	CUdevEnum *udev = new CUdevEnum(em);
	udev->go();
	//qDebug() << getenv("QWS_MOUSE_PROTO");

	MainWindow w;
	SuperMacroBot *smb = new SuperMacroBot();

	//ContextProperties for C++ function calls can be loaded before QML
	w.getView()->rootContext()->setContextProperty("superMacroBot",smb);

	QObject::connect(smb, SIGNAL(recordStateChange()),
					 em ,SLOT(toggleRecordState()),
					 Qt::QueuedConnection);

	QObject::connect(em, SIGNAL(recordStateChanged(bool)),
					 smb, SLOT(notifyRecordState(bool)),
					 Qt::QueuedConnection);

	//load QML
	w.setSource();

	//root object for notifications has to be set after the source is QML is loaded.
	smb->setRootObject(w.getView()->rootObject());

	w.show();

    return a.exec();
}
