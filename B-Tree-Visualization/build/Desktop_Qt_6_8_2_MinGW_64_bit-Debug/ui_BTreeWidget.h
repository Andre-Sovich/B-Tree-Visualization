/********************************************************************************
** Form generated from reading UI file 'BTreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTREEWIDGET_H
#define UI_BTREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BTreeWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *BTreeWidget)
    {
        if (BTreeWidget->objectName().isEmpty())
            BTreeWidget->setObjectName("BTreeWidget");
        BTreeWidget->resize(400, 300);
        pushButton = new QPushButton(BTreeWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 50, 75, 24));
        pushButton_2 = new QPushButton(BTreeWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 240, 75, 24));
        pushButton_3 = new QPushButton(BTreeWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 240, 75, 24));

        retranslateUi(BTreeWidget);

        QMetaObject::connectSlotsByName(BTreeWidget);
    } // setupUi

    void retranslateUi(QWidget *BTreeWidget)
    {
        BTreeWidget->setWindowTitle(QCoreApplication::translate("BTreeWidget", "BTreeWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("BTreeWidget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BTreeWidget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("BTreeWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BTreeWidget: public Ui_BTreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTREEWIDGET_H
