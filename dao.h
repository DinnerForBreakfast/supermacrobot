#ifndef DAO_H
#define DAO_H

#include <QObject>
#include <QtSql>

//Database Access Object
class DAO : public QObject
{
	Q_OBJECT
public:
	explicit DAO(QString path, QString type = "QSQLITE", QObject *parent = 0);
	virtual ~DAO();
	bool initDatabase();
	bool initQueries();

protected:
	QSqlDatabase db;

signals:
	
public slots:
	
};

#endif // DAO_H
