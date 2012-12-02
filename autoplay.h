#ifndef AUTOPLAY_H
#define AUTOPLAY_H

#include <QMainWindow>

namespace Ui {
    class AutoPlay;
}

class AutoPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutoPlay(QWidget *parent = 0);
    ~AutoPlay();

private:
    Ui::AutoPlay *ui;
};

#endif // AUTOPLAY_H
