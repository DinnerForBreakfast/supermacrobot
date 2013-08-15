#ifndef DEVICE_H
#define DEVICE_H

#include <QThread>
#include <QVariant>

class Device : public QThread {
	Q_OBJECT
public:
	explicit Device(const char *devnode, QObject *parent = 0);
	virtual ~Device();
	void run();
	virtual void emitSignal(QVariant qv) = 0;

private:
	ssize_t devHandle;
	const char *devnode;
	
};

#endif // DEVICE_H
