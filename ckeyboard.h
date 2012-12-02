#ifndef CKEYBOARD_H
#define CKEYBOARD_H

#include <QVariant>
#include <QThread>

class CKeyboard : public QThread {
	Q_OBJECT
public:
	explicit CKeyboard(QObject *parent = 0);
	~CKeyboard();
	void run();

private:
	ssize_t keyboard;

signals:
	void keyboardSignal(QVariant qv);

public slots:

};

#endif // CKEYBOARD_H
