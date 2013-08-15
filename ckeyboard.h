#ifndef CKEYBOARD_H
#define CKEYBOARD_H

#include "device.h"
#include <QVariant>

class CKeyboard : public Device {
	Q_OBJECT
public:
	CKeyboard(const char *devnode, QObject *parent = 0);
	~CKeyboard();

private:
	void emitSignal(QVariant qv);

signals:
	void keyboardSignal(QVariant qv);
};

#endif // CKEYBOARD_H
