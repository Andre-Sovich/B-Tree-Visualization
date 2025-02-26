/********************************************************************************
** Form generated from reading UI file 'treenode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREENODE_H
#define UI_TREENODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeNode
{
public:

    void setupUi(QWidget *TreeNode)
    {
        if (TreeNode->objectName().isEmpty())
            TreeNode->setObjectName("TreeNode");
        TreeNode->resize(400, 300);

        retranslateUi(TreeNode);

        QMetaObject::connectSlotsByName(TreeNode);
    } // setupUi

    void retranslateUi(QWidget *TreeNode)
    {
        TreeNode->setWindowTitle(QCoreApplication::translate("TreeNode", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeNode: public Ui_TreeNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREENODE_H
