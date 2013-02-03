#include "triggers.h"

Triggers::Triggers(QString path) : DAO(path){}

Triggers::~Triggers(){}

bool Triggers::initDatabase()
{
	QSqlQuery query("create table triggers(int type, code int,value int, path varchar(255))", db);
	return query.exec();
}

void Triggers::initQueries()
{
	getAll = new QSqlQuery("SELECT * FROM triggers", db);
	get = new QSqlQuery("SELECT * FROM triggers WHERE code=:code AND value=:value", db);
	insert = new QSqlQuery("INSERT INTO tiggers (code, value, path) VALUES ( ?, ?, ? )", db);
	remove = new QSqlQuery("DELETE FROM triggers WHERE code=? AND value=? AND path=?", db);
}

void Triggers::setTrigger(input_event ie, QString path)
{
	//insert.bindValue(ie.code);
	//insert.bindValue(ie.value);
	//insert.bindValue(path);
	//insert.exec();
}

void Triggers::delTrigger(input_event ie, QString path)
{
	//remove.bindValue(ie.code);
	//remove.bindValue(ie.value);
	//remove.bindValue(path);
}

QSqlQuery *Triggers::getTriggers()
{
	getAll->exec();
	return getAll;
}
