/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *createButton;
    QPushButton *compareButton;
    QPushButton *rightButton;
    QPushButton *leftButton;
    QPushButton *childButton;
    QLineEdit *lineEdit;
    QPushButton *tile2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(150, 60, 75, 24));
        compareButton = new QPushButton(centralwidget);
        compareButton->setObjectName("compareButton");
        compareButton->setGeometry(QRect(240, 60, 75, 24));
        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(420, 60, 75, 24));
        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(330, 60, 75, 24));
        childButton = new QPushButton(centralwidget);
        childButton->setObjectName("childButton");
        childButton->setGeometry(QRect(510, 60, 75, 24));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 20, 113, 22));
        tile2 = new QPushButton(centralwidget);
        tile2->setObjectName("tile2");
        tile2->setGeometry(QRect(340, 220, 50, 50));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        compareButton->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        childButton->setText(QCoreApplication::translate("MainWindow", "child", nullptr));
        tile2->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
