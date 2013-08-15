#ifndef CEVENTMANAGER_H
#define CEVENTMANAGER_H

#include <QObject>
#include <QVariant>
#include <stdint.h>
#include <QtSql>
#include "inputmeta.h"
#include "scriptplayer.h"


class CEventManager : public QObject
{
	Q_OBJECT
public:
	explicit CEventManager(QObject *parent = 0);
	~CEventManager();
	bool playbackState;

private:
	CEventManager *em;
	std::vector<autoplay_event> *recording;
	std::map<uint16_t,uint16_t> keymap;
	std::map<uint16_t,uint16_t> mousemap;
	void initDefaultKeymap();
	ScriptPlayer* player;
	uint64_t time_event;
	uint64_t time_last_event;
	uint64_t calcUsec(time_t secs, __suseconds_t usecs);
	void record(autoplay_event ae);
	bool recordState;

signals:
	void mouseMove(int x, int y);
	void mouseClick(int code, int value);
	void keyEvent(int code, int value);
	void recordStateChanged(bool state);
	void recordingStart();
	void recordingEnd();

public slots:
	void processEvent(QVariant qv);
	void scriptFinished();
	void toggleRecordState();
	
};

#endif // CEVENTMANAGER_H
