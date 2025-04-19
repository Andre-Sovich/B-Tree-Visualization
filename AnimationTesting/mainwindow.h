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
#include <QGraphicsDropShadowEffect>
#include <QHash>

//extern QHash<QString, QPushButton*> tileMap;

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

    void onAddTreeTile(QString& key);//Mmods start
    // void onCompareTreeNodes();
    // void onLeftTreeNode();
    // void onRightTreeNode();
    // void onChildTreeNode();
    // void onRemoveWidget();
    // void lineAnimation(QPushButton* parent, QPushButton* child);
    // void moveLine();
    // void highlightNode(const QList<QPushButton*>& tiles);
    // void highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color);
    // void shiftNode(const QList<QPushButton*>& tiles);
    // void outlineNode(const QList<QPushButton*>& tiles);
    // void onMovementTree(QPushButton *currentTile, QPushButton *compareTile, char animationType);
    // void onRemoveTile();
    // void onHighlightTile(QPushButton* highlightTile);

    void onCompareTreeNodes(QString& key,QString& ref);
    void onLeftTreeNode(QString& key,QString& ref);
    void onRightTreeNode(QString& key,QString& ref);
    void onChildTreeNode(QString& key,QString& ref);
    void onRemoveWidget(QString& key);//Mmods finish
    void lineAnimation(QPushButton* parent, QPushButton* child);//Jmods
    void moveLine();
    void highlightNode(const QList<QPushButton*>& tiles);
    void highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color);
    void shiftNode(const QList<QPushButton*>& tiles);
    void outlineNode(const QList<QPushButton*>& tiles);
    void onMovementTree(QString& key,QString& ref, char animationType); // refactor  --Mmods
    void onRemoveTile();
    void onHighlightTile(QPushButton* highlightTile);


private slots:

    void on_pushButton_clicked();//Jmods
    void on_createButton_clicked();
protected:
    void paintEvent(QPaintEvent *event) override;
private://Jmods
    Ui::MainWindow *ui;
    void addTreeNode(QString name);
    QPropertyAnimation *animation;
    QTimer *lineAnimationTimer;
    int lineAnimationStep = 0;
    int totalLineSteps = 50;
    QPoint lineParent, lineChild, movingPoint;
    QLine animatedLine;
    bool drawingLine = false;
    int rectWidth;
    int rectHeight;
    bool drawOutlineRect = false;
    QRect outlineRect;
    QHash<QString, QPushButton*> tileMap;
    int tileCount;
    QList<QString> tileKeys;// keep track of keysstring name
};

#endif // MAINWINDOW_H
