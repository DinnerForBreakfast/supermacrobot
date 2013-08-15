#ifndef CINPUT_H
#define CINPUT_H

#include <device.h>
#include <QVariant>

class Cmouse : public Device {
	Q_OBJECT
public:
	Cmouse(const char *devnode, QObject *parent = 0);
	~Cmouse();

private:
	void emitSignal(QVariant qv);

signals:
	void mouseSignal(QVariant qv);
};
#endif // CINPUT_H
