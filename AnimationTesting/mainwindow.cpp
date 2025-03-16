#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QTimer>//Jmods



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(
        ui->createButton, &QPushButton::clicked,
        this, &MainWindow::onAddTreeTile);//Jmods

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

    //must initialize line timer--Jmods
    lineAnimationTimer = new QTimer(this);//Jmods
    connect(lineAnimationTimer, &QTimer::timeout, this, &MainWindow::moveLine);
}
//global variables
QPushButton *tile;
int nodeWidth = 50; //150; -- Jmods
int nodeHeight = 50; //25;
int startingXpos = 80;
int startingYpos = 70;// changed to 70 for onMovement
QPushButton *currentTile;
QPushButton *compareTile;//Mmods


MainWindow::~MainWindow()
{
}


void MainWindow::onAddTreeTile(){

    tile = new QPushButton(ui->centralwidget);
    // create new tree node
    tile->setGeometry(340,110, 0, 0);
    tile->setText("Tile");
    tile->setProperty("remove",false);// won't remove tile if false--set to true to remove on click

    connect(tile, &QPushButton::clicked, this, &MainWindow::onRemoveTile);//Mmods
    //onHighlightTile(tile);//test if function works



    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(QRect(340,110,50,50));
    animation->start();
    tile->show();
}

void MainWindow::onMovementTree(QPushButton *currentTile, QPushButton *compareTile, char animationType){//Mmods
    // find new position
    QRect endPos = compareTile->geometry();
    switch(animationType) {
    case 'c': //compare
        endPos = endPos.translated(0, -startingYpos);
        break;
    case 'l': //left
        endPos = endPos.translated(-startingXpos, 0);
        break;
    case 'r': //right
        endPos = endPos.translated(startingXpos, 0);
        break;
    case 'h': //child
        endPos = endPos.translated(0, startingYpos);
        break;
    default:
        return; // Exit if animationType is invalid
    }

    // animate tree node
    animation = new QPropertyAnimation(currentTile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(currentTile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    currentTile->show();
    connect(animation, &QPropertyAnimation::finished, this, [this]() { //Jmods ----- moved under on movement instead of under child tree--Mmods
        lineAnimation(ui->tile2, tile); // Call lineAnimation only after movement
    });
}

void MainWindow::onCompareTreeNodes(){
    onMovementTree(tile, ui->tile2, 'c');
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
    onMovementTree(tile, ui->tile2, 'l');
}

void MainWindow::onRightTreeNode(){
    onMovementTree(tile, ui->tile2, 'r');
}
void MainWindow::onRemoveWidget() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}

void MainWindow::onChildTreeNode(){
    onMovementTree(tile, ui->tile2, 'h');
}
void MainWindow::on_pushButton_clicked()//Jmods
{

}

void MainWindow::on_createButton_clicked()
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 100));
}

void MainWindow::paintEvent(QPaintEvent *event) { //Jmods
    QPainter painter(this);
    painter.setPen(Qt::black);

    if(drawingLine){
        painter.drawLine(animatedLine);
    }
}

//input can be put in as {tile1, tile2, tile3} even if it's a single tile
void MainWindow::highlightNode(const QList<QPushButton*>& tiles){//Jmods
    for(int i = 0; i < tiles.count(); i++){
        if(tile){
            tile->setStyleSheet("background-color: orange;");
        }
    }
}
void MainWindow::highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color){//Jmods
    for(int i = 0; i < tiles.count(); i++){
        if(tile){
            tile->setStyleSheet(QString("background-color: %1").arg(color));
        }
    }
}
void MainWindow::shiftNode(const QList<QPushButton*>& tiles){//Jmods
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



void MainWindow::onRemoveTile(){//Mmods
    QPushButton* specificTile = qobject_cast<QPushButton*>(sender());
    if (specificTile) {
        QVariant tileValid = specificTile->property("remove");
        if (tileValid.isValid() && tileValid.toBool()) {
            delete specificTile;
        }
    }
}

void MainWindow::onHighlightTile(QPushButton* highlightTile){//MMods
    if(highlightTile){
        highlightTile->setStyleSheet("background-color: red; color: white;");
    }
}
