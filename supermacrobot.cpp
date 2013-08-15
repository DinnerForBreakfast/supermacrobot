#include "supermacrobot.h"
#include "QDebug"
#include "QMetaObject"

SuperMacroBot::SuperMacroBot(QObject *parent) :
	QObject(parent)
{
}

void SuperMacroBot::setRootObject(QGraphicsObject *root)
{
	this->root = root;
}

void SuperMacroBot::notifyRecordState(bool state)
{
	QVariant msg = state;
	QVariant returnedValue;
	QMetaObject::invokeMethod(root, "notifyRecordStateChanged",Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, msg));
}

void SuperMacroBot::toggleRecordState()
{
	emit recordStateChange();
}
