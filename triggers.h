#ifndef TRIGGERS_H
#define TRIGGERS_H

#include <QObject>
#include "inputmeta.h"
#include <QtSql>
#include <vector>
#include "dao.h"

class Triggers : public DAO
{
	Q_OBJECT

public:
	explicit Triggers(QString path);
	~Triggers();
	void setTrigger(autoplay_event ie, QString path);
	void delTrigger(autoplay_event ie, QString path);
	QSqlQuery* getTriggers();
	QSqlQuery* getTrigger(input_event ie);

private:
	QSqlQuery* create;
	QSqlQuery* getAll;
	QSqlQuery* get;
	QSqlQuery* insert;
	QSqlQuery* remove;

	bool initDatabase();
	void initQueries();

signals:
	
public slots:
	
};

#endif // TRIGGERS_H
