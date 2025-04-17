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
#include <QList>//Jmods

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
    void onAddTreeTile(std::string& key);//J/Mmods
    void onMovementTree(std::string& key,std::string& ref, char animationType); // added on MovementTree function --Mmods
    void onCompareTreeNodes(std::string& key,std::string& ref);//Mods
    void onLeftTreeNode(std::string& key,std::string& ref);
    void onRightTreeNode(std::string& key,std::string& ref);
    void onChildTreeNode(std::string& key,std::string& ref);
    void onRemoveWidget(std::string& key);
    void onRemoveTile();//Mmods
    void onHighlightTile(QPushButton* highlightTile);//Mmods
    void lineAnimation(QPushButton* parent, QPushButton* child);//Jmods
    void moveLine();
    void highlightNode(const QList<QPushButton*>& tiles);
    void highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color);
    void shiftNode(const QList<QPushButton*>& tiles);

private slots:

    void on_pushButton_clicked();//Jmods
    void on_createButton_clicked();

private://Jmods
    Ui::MainWindow *ui;
    void addTreeNode(QString name);
    QPropertyAnimation *animation;
    void paintEvent(QPaintEvent *event);
    QTimer *lineAnimationTimer;
    int lineAnimationStep = 0;
    int totalLineSteps = 50;
    QPoint lineParent, lineChild, movingPoint;
    QLine animatedLine;
    bool drawingLine = false;
};

#endif // MAINWINDOW_H
