/********************************************************************************
** Form generated from reading UI file 'autoplay.ui'
**
** Created: Tue Jul 30 12:12:55 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOPLAY_H
#define UI_AUTOPLAY_H

#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoPlay
{
public:
    QDeclarativeView *declarativeView;

    void setupUi(QWidget *AutoPlay)
    {
        if (AutoPlay->objectName().isEmpty())
            AutoPlay->setObjectName(QString::fromUtf8("AutoPlay"));
        AutoPlay->resize(800, 480);
        declarativeView = new QDeclarativeView(AutoPlay);
        declarativeView->setObjectName(QString::fromUtf8("declarativeView"));
        declarativeView->setGeometry(QRect(0, 0, 800, 480));
        declarativeView->setSource(QUrl(QString::fromUtf8("")));

        retranslateUi(AutoPlay);

        QMetaObject::connectSlotsByName(AutoPlay);
    } // setupUi

    void retranslateUi(QWidget *AutoPlay)
    {
        AutoPlay->setWindowTitle(QApplication::translate("AutoPlay", "AutoPlay", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_AutoPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOPLAY_H
