#include "treenode.h"
#include "ui_treenode.h"

TreeNode::TreeNode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TreeNode)
{
    ui->setupUi(this);
}

TreeNode::~TreeNode()
{
    delete ui;
}
