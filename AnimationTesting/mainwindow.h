#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPainter>
#include <QDialog>
#include <QLayout>
#include <QMessageBox>
#include <QWheelEvent>
#include <QLabel>
#include <vector>

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

    void onAddTreeNode();
    void onMovementTreeTile(QPushButton* currentTile, QPushButton* compareTile, char animationType);
    void onCompareTreeNodes();
    void onLeftTreeNode();
    void onRightTreeNode();
    void onChildTreeNode();
    void onRemoveWidget();

private slots:
    void on_pushButton_clicked();

    void on_createButton_clicked();

private:
    Ui::MainWindow *ui;
    void addTreeNode(QString name);
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
