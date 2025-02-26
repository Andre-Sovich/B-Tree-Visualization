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
#include <optional>
#include <BPlusTree.hh>
#include <BStarTree.hh>
#include <BTree.h>

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
    //All variables needed in the display functions and theif defaults.
    int oldHeight;
    int currentY;
    int minX;
    int maxX;
    int currentDx;
    int currentX;
    int rectWidth;
    int rectHeight;
    int gapSize;
    int layerLevel;
    int height;
    int parentIndex;
    int childIndex;
    int currentParentDx;
    int parentLength;
    vector<int> prevXs;
    vector<int> currentXs;
    int max_degree;
    BTree* b_tree;
    BPlusTree* bplus_tree;
    BStarTree* bstar_tree;

private slots:
    void on_insert_button_clicked();

    void on_delete_textbox_copyAvailable(bool b);

    void on_btree_radio_button_clicked();

    void on_bplus_radio_button_clicked();

    void on_bstar_radio_button_clicked();

    void on_delete_button_clicked();

    void on_clear_button_clicked();

    void max_degree_combo_index_changed(int index);

    void resetTrees();

    void clearDisplay();

    bool isNumber(std::string string);

    QGraphicsRectItem* makeRectangle(int width, int height);

    string makeNodeText(BTreeNode currentNode);

    string makeNodeText(BPlusTreeNode currentNode);

    QGraphicsTextItem* makeQString(string input);

    void updateLayer(vector<int>& previousXs, vector<int>& currentXs, BPlusTreeNode* currentNode, BPlusTreeNode*& oldParent);

    void updateLayer(vector<int>& prevXs, vector<int>& currentXs, BTreeNode* currentNode, BTreeNode*& oldParent);

    void updateIndexes(vector<int>& prevXs, vector<int>& currentXs, BPlusTreeNode*& currentNode, BPlusTreeNode*& oldParent);

    void updateIndexes(vector<int>& prevXs, vector<int>& currentXs, BTreeNode*& currentNode, BTreeNode*& oldParent);

    void initializeVariables();

    void drawLines(vector<int>& prevXs, vector<int>& currentXs, BTreeNode*& oldParent);

    void drawLines(vector<int>& prevXs, vector<int>& currentXs, BPlusTreeNode*& oldParent);

    void displayTreeFromQueue(queue<BPlusTreeNode*> q, std::optional<int> find_value);

    void displayTreeFromQueue(queue<BTreeNode*> q, std::optional<int> find_value);

    void on_find_button_clicked();

    void wheelEvent(QWheelEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
