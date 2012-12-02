#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

GPIO::GPIO(unsigned int pin, DIRECTION dir, EDGE edge, PULLUP pullup) {
	this->pin = pin;

	//init pinStr and pinStrlen
	this->pinStrlen = snprintf(this->pinStr, MAX_BUF, "%d", this->pin);
	snprintf(this->pinValuePath, MAX_BUF, SYSFS_GPIO_DIR "/gpio%d/value" , this->pin);
	snprintf(this->pinDirectionPath, MAX_BUF, SYSFS_GPIO_DIR  "/gpio%d/direction", this->pin);
	snprintf(this->pinEdgePath, MAX_BUF, SYSFS_GPIO_DIR "/gpio%d/edge", this->pin);
	snprintf(this->pinPullupPath, MAX_BUF, SYSFS_GPIO_DIR "/gpio%d/active_low", this->pin);


	exportPin();
	if(dir == OUT){
		setDirection(GPIO::OUT);
		setPullup(pullup);
		setValue(0);
	}
	if(dir == IN){
		setDirection(GPIO::IN);
		setPullup(pullup);
		setEdge(edge);
	}

}

GPIO::~GPIO()
{
	unexportPin();
}

int GPIO::openPin()
{
	this->fd = open(this->pinValuePath, O_RDONLY | O_NONBLOCK );
	return this->fd;
}

int GPIO::closePin()
{
	return close(this->fd);
}

int GPIO::exportPin()
{
	this->fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (this->fd < 0) {
		return this->fd;
	}

	write(this->fd, pinStr, pinStrlen);
	close(this->fd);

	return this->fd;
}

int GPIO::unexportPin()
{
	this->fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
	if (this->fd < 0) {
		return this->fd;
	}

	write(this->fd, pinStr, pinStrlen);
	close(this->fd);
	return this->fd;
}

int GPIO::setDirection(DIRECTION dir)
{

	this->fd = open(this->pinDirectionPath, O_WRONLY);
	if (this->fd < 0) {
		return this->fd;
	}

	if (dir == OUT)
		write(this->fd, "out", 4);
	else
		write(this->fd, "in", 3);

	close(this->fd);
	return 0;
}

int GPIO::setValue(unsigned int value)
{
	fd = open(this->pinValuePath, O_WRONLY);
	if (fd < 0) {
		return fd;
	}

	if (value)
		write(fd, "1", 2);
	else
		write(fd, "0", 2);

	close(fd);
	return 0;
}

int GPIO::getValue(unsigned int *value)
{
	char ch;

	fd = open(this->pinValuePath, O_RDONLY);
	if (fd < 0) {
		return fd;
	}

	read(fd, &ch, 1);

	if (ch != '0') {
		*value = 1;
	} else {
		*value = 0;
	}

	close(fd);
	return 0;
}

int GPIO::setEdge(EDGE edge)
{
	fd = open(this->pinEdgePath, O_WRONLY);
	if (fd < 0) {
		return fd;
	}
	if(edge == RISING){
		write(fd, "rising", strlen("rising") + 1);
	}else{
		write(fd, "falling", strlen("falling") + 1);
	}
	close(fd);
	return 0;
}

int GPIO::setPullup(GPIO::PULLUP pullup)
{
	fd = open(this->pinEdgePath, O_WRONLY);
	if (fd < 0) {
		return fd;
	}
	if(pullup == GPIO::ACTIVE_LOW){
		write(fd, "1", 2);
	}else{
		write(fd, "0", 2);
	}
	close(fd);
	return 0;
}
