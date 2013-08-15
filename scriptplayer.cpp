#include "scriptplayer.h"
#include "QDebug"

ScriptPlayer::ScriptPlayer(QObject *parent) :
	QThread(parent)
{
	go = false;
}

ScriptPlayer::~ScriptPlayer()
{
}

void ScriptPlayer::run()
{
	std::vector<autoplay_event>::iterator i;
	i = recording->begin();
	for(i = recording->begin(); i!= recording->end(); i++){
		if(!go)break;
		qDebug() << "playback delay:" << i->delay;
		usleep(i->delay);
		QVariant qv = QVariant::fromValue(*i);
		emit inputEvent(qv);
	}
	emit done();
}

void ScriptPlayer::play(std::vector<autoplay_event>* recording)
{
	this->recording = recording;
	go = true;
	this->run();
}

void ScriptPlayer::halt()
{
	go = false;
}
