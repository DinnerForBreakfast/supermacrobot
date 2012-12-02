#include <pcap.h>
#include "cpcap.h"
#include <QTextStream>
#include <linux/types.h>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

QTextStream qin(stdin);
QTextStream qout(stdout);

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))


static void listen(u_char* u, const struct pcap_pkthdr* ph, const u_char* buf){
	//Cpcap* blah = (Cpcap*)u;
    for(uint i = 0;i < ph->caplen;i++){
        qout << (char*)buf+i;
    }
    qout << endl;
}


Cpcap::Cpcap(QObject *parent) :QThread(parent){}

Cpcap::~Cpcap(){}

void Cpcap::run(){
    pcap_if_t *allifs, *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    static volatile int keep_listening;
    QString line;
    string devname = "usbmon1";

    qDebug("pcap version: %i.%i",PCAP_VERSION_MAJOR,PCAP_VERSION_MINOR);

    if (pcap_findalldevs(&allifs, errbuf) == -1) {
        qDebug("Can't search for devices. Are permissions set?");
        qDebug("errbuf: %s",errbuf);
    }

    if (allifs == NULL) {
        qDebug("No devices found.");
    }

    int i = 1;
    for (dev = allifs; dev != NULL; dev = dev->next) {
        qDebug("%i. name: %s, description: %s",i++,dev->name, dev->description);
    }

    /*
    line = qin.readLine();

    for(dev = allifs; dev != NULL;dev = dev->next){
        devname = dev->name;
        if(devname == line){
            qDebug("%s selected",dev->name);
            break;
        }
    }
    */

    qDebug("%s selected",devname.c_str());

    handle = pcap_open_live(devname.c_str(),BUFSIZ,1,1000,errbuf);
    if(handle == NULL){
        qDebug("Couldn't open device: %s",devname.c_str());
    }else{
        keep_listening = 1;
        while(keep_listening){
            if(pcap_dispatch(handle,-1,listen,(u_char*)this) < 0){
                qDebug("Error");
                keep_listening = 0;
            }
        }
    }
    pcap_close(handle);
    pcap_freealldevs(allifs);
}
