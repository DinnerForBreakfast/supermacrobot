#ifndef CEVENTMANAGER_H
#define CEVENTMANAGER_H

#include <QObject>
#include <QVariant>
#include <stdint.h>

class CEventManager : public QObject
{
	Q_OBJECT
public:
	explicit CEventManager(QObject *parent = 0);
	~CEventManager();
private:
	std::map<uint16_t,uint16_t> keymap;
	std::map<uint16_t,uint16_t> mousemap;
signals:
	void mouseMove(int x, int y);
	void mouseClick(int code, int value);
	void keyEvent(int code, int value);

public slots:
	void processEvent(QVariant qv);
	
};

#endif // CEVENTMANAGER_H
