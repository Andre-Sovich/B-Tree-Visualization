/********************************************************************************
** Form generated from reading UI file 'BTreeNode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTREENODE_H
#define UI_BTREENODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BTreeNode
{
public:

    void setupUi(QWidget *BTreeNode)
    {
        if (BTreeNode->objectName().isEmpty())
            BTreeNode->setObjectName("BTreeNode");
        BTreeNode->resize(400, 300);

        retranslateUi(BTreeNode);

        QMetaObject::connectSlotsByName(BTreeNode);
    } // setupUi

    void retranslateUi(QWidget *BTreeNode)
    {
        BTreeNode->setWindowTitle(QCoreApplication::translate("BTreeNode", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BTreeNode: public Ui_BTreeNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTREENODE_H
