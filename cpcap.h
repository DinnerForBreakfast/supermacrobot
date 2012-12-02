#ifndef CPCAP_H
#define CPCAP_H

#include <QThread>
#include <pcap.h>

class Cpcap : public QThread
{
    Q_OBJECT
public:
    explicit Cpcap(QObject *parent = 0);
    ~Cpcap();
    void run();
signals:

public slots:

};

#endif // CPCAP_H
