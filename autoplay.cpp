#include "autoplay.h"
#include "ui_autoplay.h"
#include <QMainWindow>

AutoPlay::AutoPlay(QWidget *parent) : QMainWindow(parent,Qt::FramelessWindowHint), ui(new Ui::AutoPlay) {
	ui->setupUi(this);
	//ui->declarativeView->setSource(QUrl::fromLocalFile(QDir::currentPath().append("/base/Main.qml")));
	ui->declarativeView->setSource(QUrl("qrc:/Main.qml"));
}

AutoPlay::~AutoPlay(){
    delete ui;
}
