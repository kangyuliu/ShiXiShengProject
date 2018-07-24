/********************************************************************************
** Form generated from reading UI file 'mystopwatch.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTOPWATCH_H
#define UI_MYSTOPWATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyStopWatchClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyStopWatchClass)
    {
        if (MyStopWatchClass->objectName().isEmpty())
            MyStopWatchClass->setObjectName(QStringLiteral("MyStopWatchClass"));
        MyStopWatchClass->resize(600, 400);
        menuBar = new QMenuBar(MyStopWatchClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyStopWatchClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyStopWatchClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyStopWatchClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyStopWatchClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyStopWatchClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyStopWatchClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyStopWatchClass->setStatusBar(statusBar);

        retranslateUi(MyStopWatchClass);

        QMetaObject::connectSlotsByName(MyStopWatchClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyStopWatchClass)
    {
        MyStopWatchClass->setWindowTitle(QApplication::translate("MyStopWatchClass", "MyStopWatch", 0));
    } // retranslateUi

};

namespace Ui {
    class MyStopWatchClass: public Ui_MyStopWatchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTOPWATCH_H
