#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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

    void createKey(std::string key);

    void createNode(std::string index);

    void makeChild(std::string childIndex, std::string parentIndex);

    void gotoNode(std::string curIndex, std::string newIndex, std::string key);

    bool compareTiles(std::string curKey, std::string refKey, std::string index);

    void removeTile(std::string key, std::string index);

    void removeNode(std::string index);

    void highlightNode(std::string index);

    void highlightTile(std::string key, std::string index);

    void resizeNode(std::string index);

    void respaceNodes();

    void splitNode(std::string index);

    void runAnimationString(std::string instr);

    void callAnimation(char c);

    void lineAnimation(QPushButton* parent, QPushButton* child);

private slots:
    void on_insert_button_clicked();

    void on_btree_radio_button_clicked();

    void on_bplus_radio_button_clicked();

    void on_bstar_radio_button_clicked();

    void on_delete_button_clicked();

    void on_clear_button_clicked();

    void max_degree_combo_index_changed(int index);

    void resetTrees();

    void clearDisplay();

    bool isNumber(std::string string);

    void displayTreeFromQueue(queue<BPlusTreeNode*> q);
    void displayTreeFromQueueFind(queue<BTreeNode*> q, int find_value);
    void displayTreeFromQueueFind(queue<BPlusTreeNode*> q, int find_value);

    void displayTreeFromQueue(queue<BTreeNode*> q);

    void on_find_button_clicked();

    void wheelEvent(QWheelEvent *event);




private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
