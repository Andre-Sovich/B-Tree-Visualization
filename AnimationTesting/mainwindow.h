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
#include <QList>

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

    void onAddTreeTile();
    void onCompareTreeNodes();
    void onLeftTreeNode();
    void onRightTreeNode();
    void onChildTreeNode();
    void onRemoveWidget();
    void lineAnimation(QPushButton* parent, QPushButton* child);
    void moveLine();
    void highlightNode(const QList<QPushButton*>& tiles);
    void highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color);
    void shiftNode(const QList<QPushButton*>& tiles);

private slots:
    void on_pushButton_clicked();

    void on_createButton_clicked();

private:
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
