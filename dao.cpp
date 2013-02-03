#include "dao.h"
#include "QDebug"

DAO::DAO(QString path, QString type, QObject *parent) :
	QObject(parent)
{
	db = QSqlDatabase::addDatabase(type);
	db.setDatabaseName(path);
	if (!db.open()) {
		qDebug("Failed to create database ");
		qDebug() << path;
	}else{
		QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table'", db);
		query.exec();
		if(!query.next()){
			initDatabase();
			initQueries();
		}
	}
}

DAO::~DAO()
{
	if(db.isOpen()){
		db.close();
	}
}

bool DAO::initDatabase(){
	return true;
}

bool DAO::initQueries(){
	return true;
}
