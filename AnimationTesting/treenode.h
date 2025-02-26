#ifndef TREENODE_H
#define TREENODE_H

#include <QWidget>

namespace Ui {
class TreeNode;
}

class TreeNode : public QWidget
{
    Q_OBJECT

public:
    explicit TreeNode(QWidget *parent = nullptr);
    ~TreeNode();

private:
    Ui::TreeNode *ui;
};

#endif // TREENODE_H
