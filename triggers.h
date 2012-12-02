#ifndef TRIGGERS_H
#define TRIGGERS_H

#include <QObject>
#include <Qt/qsqldatabase.h>
#include "inputmeta.h"

class Triggers : public QObject
{
	Q_OBJECT
public:
	explicit Triggers(QObject *parent = 0);
	~Triggers();
	void setTrigger(input_event ie, QString file);
	QString getTrigger (input_event ie);
	bool isTrigger(input_event ie);
	void delTrigger(input_event ie);
private:
	QSqlDatabase db;
signals:
	
public slots:
	
};

#endif // TRIGGERS_H
