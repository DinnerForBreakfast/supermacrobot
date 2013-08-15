#ifndef SUPERMACROBOT_H
#define SUPERMACROBOT_H

#include <QObject>
#include <QGraphicsObject>

class SuperMacroBot : public QObject
{
	Q_OBJECT
public:
	explicit SuperMacroBot(QObject *parent = 0);
	void setRootObject(QGraphicsObject *root);

private:
	QGraphicsObject *root;

signals:
	void recordStateChange();

public slots:
	//Toggle record state from QML
	void toggleRecordState();

	//Notify QML of record state change
	void notifyRecordState(bool state);

};

#endif // SUPERMACROBOT_H
