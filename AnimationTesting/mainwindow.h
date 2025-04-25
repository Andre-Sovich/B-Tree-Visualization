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
#include <QTimer>
#include <QSequentialAnimationGroup>

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
    void onAddTreeNode(std::string key);
    void onCompareTreeNodes(std::string key,std::string refKey);
    void onLeftTreeNode(std::string key,std::string refKey);
    void onRightTreeNode(std::string key,std::string refKey);
    void onChildTreeNode(std::string key,std::string refKey);
    void onRemoveWidget(std::string key,std::string refKey);
    void callAnimation(char c);
    void runAnimationString();



private slots:

private:
    Ui::MainWindow *ui;
    void addTreeNode(QString name);
    QPropertyAnimation *animation;
};
#endif // MAINWINDOW_H
