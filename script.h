#ifndef SCRIPT_H
#define SCRIPT_H

#include <QObject>
#include <QtSql>
#include "inputmeta.h"

class Script : public QObject
{
	Q_OBJECT
public:
	explicit Script(QString path, QObject *parent = 0);
	~Script();
	void insert(input_event ie);
private:
	QSqlDatabase db;
	QSqlQuery *sqlInsert;
	QSqlQuery *sqlGet;
signals:
	void scriptSignal(QVariant qv);
public slots:
	
};

#endif // SCRIPT_H
