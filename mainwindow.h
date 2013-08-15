#ifndef AUTOPLAY_H
#define AUTOPLAY_H

#include <QMainWindow>
#include <QDeclarativeView>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	QDeclarativeView *getView();
	void setSource();

private:
	Ui::MainWindow *ui;
};

#endif // AUTOPLAY_H
