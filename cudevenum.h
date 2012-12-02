#ifndef CUDEVENUM_H
#define CUDEVENUM_H

#include <QObject>

class CUdevEnum : public QObject {
    Q_OBJECT
private:
    struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;
    struct udev_device *dev;
public:
    explicit CUdevEnum(QObject *parent = 0);
    ~CUdevEnum();
    void go();
signals:
    void allDone(int);
public slots:
    void done(int);
};

#endif // CUDEVENUM_H
