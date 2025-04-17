/********************************************************************************
** Form generated from reading UI file 'qttreenodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTREENODEWIDGET_H
#define UI_QTTREENODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTreeNodeWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *QtTreeNodeWidget)
    {
        if (QtTreeNodeWidget->objectName().isEmpty())
            QtTreeNodeWidget->setObjectName("QtTreeNodeWidget");
        QtTreeNodeWidget->resize(400, 300);
        label = new QLabel(QtTreeNodeWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 120, 49, 16));

        retranslateUi(QtTreeNodeWidget);

        QMetaObject::connectSlotsByName(QtTreeNodeWidget);
    } // setupUi

    void retranslateUi(QWidget *QtTreeNodeWidget)
    {
        QtTreeNodeWidget->setWindowTitle(QCoreApplication::translate("QtTreeNodeWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("QtTreeNodeWidget", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtTreeNodeWidget: public Ui_QtTreeNodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTREENODEWIDGET_H
