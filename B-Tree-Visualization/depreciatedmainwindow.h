#ifndef DEPRECIATEDMAINWINDOW_H
#define DEPRECIATEDMAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QDialog>
#include <QMessageBox>
#include <QWheelEvent>
#include <vector>
#include <BPlusTree.hh>
#include <BStarTree.hh>
#include <BTree.h>
#include <QPropertyAnimation>
#include <QGraphicsLineItem>

class depreciatedMainWindow
{
public:
    QTextStream out;
    QGraphicsScene scene;
    QPainter painter;
    std::vector<QGraphicsItemGroup*> displayItems;
    QMessageBox inputErrorMsgBox;
    int tree_identifier;
    int max_degree;
    BTree* b_tree;
    BPlusTree* bplus_tree;
    BStarTree* bstar_tree;

    depreciatedMainWindow();
    void displayTreeFromQueue(queue<BPlusTreeNode*> q);
    void displayTreeFromQueueFind(queue<BTreeNode*> q, int find_value);
    void displayTreeFromQueueFind(queue<BPlusTreeNode*> q, int find_value);

    void displayTreeFromQueue(queue<BTreeNode*> q);
};

#endif // DEPRECIATEDMAINWINDOW_H
