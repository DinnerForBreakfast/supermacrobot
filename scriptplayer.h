#ifndef SCRIPTPLAYER_H
#define SCRIPTPLAYER_H

#include <QVariant>
#include "inputmeta.h"
#include <QThread>
#include <vector>
#include "stdint.h"

class ScriptPlayer : public QThread
{
	Q_OBJECT
public:
	explicit ScriptPlayer(QObject *parent = 0);
	virtual ~ScriptPlayer();
	void run();

private:
	std::vector<autoplay_event>* recording;
	bool go;

signals:
	void inputEvent(QVariant qv);
	void done();

public slots:
	void play(std::vector<autoplay_event>* recording);
	void halt();
	
};

#endif // SCRIPTPLAYER_H
