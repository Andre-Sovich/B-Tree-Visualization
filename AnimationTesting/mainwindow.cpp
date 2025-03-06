#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(
        ui->createButton, &QPushButton::clicked,
        this, &MainWindow::onAddTreeTile);

    QObject::connect(
        ui->compareButton, &QPushButton::clicked,
        this, &MainWindow::onCompareTreeNodes);
    QObject::connect(
        ui->leftButton, &QPushButton::clicked,
        this, &MainWindow::onLeftTreeNode);
    QObject::connect(
        ui->rightButton, &QPushButton::clicked,
        this, &MainWindow::onRightTreeNode);
    QObject::connect(
        ui->childButton, &QPushButton::clicked,
        this, &MainWindow::onChildTreeNode);

    //must initialize line timer
    lineAnimationTimer = new QTimer(this);
    connect(lineAnimationTimer, &QTimer::timeout, this, &MainWindow::moveLine);
}
//global variables
QPushButton *tile;
int nodeWidth = 50; //150;
int nodeHeight = 50; //25;
int startingXpos = 80;
int startingYpos = 120;
QPushButton *currentTile;

MainWindow::~MainWindow()
{
}

void MainWindow::onAddTreeTile(){

    tile = new QPushButton(ui->centralwidget);
    // create new tree node
    tile->setGeometry(340,110, 0, 0);
    tile->setText("Tile");

    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(QRect(340,110,50,50));
    animation->start();
    tile->show();
}

void MainWindow::onCompareTreeNodes(){
    // find new position
    QRect endPos = ui->tile2->geometry();
    endPos = endPos.translated(0,-60); //based on tile -1 * (height + space)
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    tile->show();
}

void MainWindow::lineAnimation(QPushButton* parent, QPushButton* child){
    if(!parent || !child) return;

    QRect parentPos = parent->geometry();
    QRect childPos = child->geometry();

    lineParent = QPoint(parentPos.center().x(), parentPos.center().y());
    lineChild = QPoint(childPos.center().x(), childPos.center().y());

    movingPoint = lineParent;
    lineAnimationStep = 0;
    drawingLine = true;
    lineAnimationTimer->start(10);

}
void MainWindow::moveLine(){
    if(lineAnimationStep >= totalLineSteps){
        lineAnimationTimer->stop();
        drawingLine = false;
        return;
    }
    QRect childPos = tile->geometry();
    qreal progress = (qreal)lineAnimationStep / totalLineSteps;
    movingPoint.setX(lineParent.x() + (progress*(lineChild.x()- lineParent.x())));
    movingPoint.setY(lineParent.y() + (progress * (childPos.center().y() - lineParent.y())));
    animatedLine = QLine(lineParent, movingPoint);

    update();
    lineAnimationStep++;

}
void MainWindow::onLeftTreeNode(){
    // find new position
    QRect endPos = ui->tile2->geometry();
    endPos = endPos.translated(-50,0); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    tile->show();
    highlightNode({tile});
}

void MainWindow::onRightTreeNode(){
    // find new position
    QRect endPos = ui->tile2->geometry();
    endPos = endPos.translated(50,0); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    tile->show();
}
void MainWindow::onRemoveWidget() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}

void MainWindow::onChildTreeNode(){
    // find new position
    QRect endPos = ui->tile2->geometry();
    endPos = endPos.translated(0,80); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    tile->show();

    animation->start();
    tile->show();
    connect(animation, &QPropertyAnimation::finished, this, [this]() {
        lineAnimation(ui->tile2, tile); // Call lineAnimation only after movement
    });
}

void MainWindow::on_createButton_clicked()
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 100));
}
void MainWindow::on_pushButton_clicked()
{

}
void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    if(drawingLine){
        painter.drawLine(animatedLine);
    }
}

//input can be put in as {tile1, tile2, tile3} even if it's a single tile
void MainWindow::highlightNode(const QList<QPushButton*>& tiles){
    for(int i = 0; i < tiles.count(); i++){
    if(tile){
        tile->setStyleSheet("background-color: orange;");
    }
    }
}
void MainWindow::highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color){
    for(int i = 0; i < tiles.count(); i++){
    if(tile){
        tile->setStyleSheet(QString("background-color: %1").arg(color));
    }
    }
}
void MainWindow::shiftNode(const QList<QPushButton*>& tiles){
    for(int i = 0; i < tiles.count(); i++){
        int shiftAmount = nodeWidth/2;
        QRect endPos;
        if(tile){
            endPos = tiles[i]->geometry();
            endPos = endPos.translated(-shiftAmount,0); //based on tile width + spac
            // animate tree node
            animation = new QPropertyAnimation(tile, "geometry");
            animation->setDuration(250);
            animation->setStartValue(tile->geometry());
            animation->setEndValue(endPos);
            animation->start();
            tile->show();
        }
    }
}

