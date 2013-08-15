#include "mainwindow.h"
#include "ui_autoplay.h"
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent,Qt::FramelessWindowHint), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	//ui->declarativeView->setSource(QUrl::fromLocalFile(QDir::currentPath().append("/base/Main.qml")));

}

MainWindow::~MainWindow(){
	delete ui;
}

QDeclarativeView* MainWindow::getView()
{
	return ui->declarativeView;
}

void MainWindow::setSource()
{
	ui->declarativeView->setSource(QUrl("qrc:/Main.qml"));
}
