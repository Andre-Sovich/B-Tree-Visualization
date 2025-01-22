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

    void displayTreeFromQueue(queue<BPlusTreeNode*> q);

    void displayTreeFromQueueFind(queue<BPlusTreeNode*> q, int find_value);

    void displayTreeFromQueue(queue<BTreeNode*> q);

    void displayTreeFromQueueFind(queue<BTreeNode*> q, int find_value);

    void on_find_button_clicked();

    void wheelEvent(QWheelEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
