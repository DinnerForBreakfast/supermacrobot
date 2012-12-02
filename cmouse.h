#ifndef CINPUT_H
#define CINPUT_H

#include <QVariant>
#include <QThread>

class Cmouse : public QThread {
	Q_OBJECT
public:
	explicit Cmouse(QObject *parent = 0);
	~Cmouse();
	void run();

private:
	ssize_t mouse;

signals:
	void mouseSignal(QVariant qv);

public slots:

};
#endif // CINPUT_H
