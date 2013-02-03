#include "script.h"

Script::Script(QString path, QObject *parent) :
	QObject(parent)
{
	//sGetAll = "SELECT * FROM script";
	//sInsert = "INSERT INTO script (code, value, time) VALUES ( ?, ?, ? )";

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(path);
	if (!db.open()) {
		qDebug("Failed to create database.");
	}else{
		QSqlQuery query;
		query.exec("SELECT name FROM sqlite_master WHERE type='table'");
		if(!query.next()){
			QSqlQuery query;
			query.exec("create table script(code int,value int, path varchar(255))");
		}
	}
}

Script::~Script()
{
	if(db.isOpen()){
		db.close();
	}
}
