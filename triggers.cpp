#include "triggers.h"

Triggers::Triggers(QObject *parent) :
	QObject(parent)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(":memory:");
	if (!db.open()) {
		qDebug("Failed to create database.");
	}
}

Triggers::~Triggers()
{
	if(db.isOpen()){
		db.close();
	}
}

void Triggers::setTrigger(input_event ie, QString file)
{
}

QString Triggers::getTrigger(input_event ie)
{
}

bool Triggers::isTrigger(input_event ie)
{
	return false;
}

void Triggers::delTrigger(input_event ie)
{
}
