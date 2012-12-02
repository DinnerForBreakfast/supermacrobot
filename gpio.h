#ifndef GPIO_H
#define GPIO_H

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define MAX_BUF 255


class GPIO {

public:
	enum DIRECTION
	{
		OUT,
		IN
	};

	enum EDGE
	{
		RISING,
		FALLING
	};

	enum PULLUP
	{
		ACTIVE_HIGH,
		ACTIVE_LOW
	};

	GPIO(unsigned int pin, DIRECTION dir, EDGE edge = GPIO::RISING, PULLUP pullup = ACTIVE_HIGH);
	~GPIO();

	int openPin();
	int closePin();
	int exportPin();
	int unexportPin();
	int setDirection(DIRECTION dir);
	int setEdge(EDGE edge);
	int setPullup(PULLUP pullup);
	int setValue(unsigned int value);
	int getValue(unsigned int *value);

private:
	//pin number
	unsigned int pin;
	//pin file descriptor
	int fd;
	//pin value path
	char pinValuePath[MAX_BUF];
	//pin number as string
	char pinStr[MAX_BUF];
	//character length of pinStr
	int pinStrlen;
	//pin direction path
	char pinDirectionPath[MAX_BUF];
	//pin edge path
	char pinEdgePath[MAX_BUF];
	//pin pullup path
	char pinPullupPath[MAX_BUF];

};

#endif // GPIO_H
