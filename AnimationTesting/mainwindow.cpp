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
        this, [this]() {
        std::string key = "5";
        onAddTreeTile(key);});//testing key defined -MMods

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

    this->tileMap["tile1"] = ui->tile2;
    tileCount = 1;
    //must initialize line timer--Jmods
    lineAnimationTimer = new QTimer(this);//Jmods
    connect(lineAnimationTimer, &QTimer::timeout, this, &MainWindow::moveLine);
}
//global variables
//QPushButton *tile;
int nodeWidth = 50; //150; -- Jmods
int nodeHeight = 50; //25;
int startingXpos = 80;
int startingYpos = 70;// changed to 70 for onMovement
QPushButton *currentTile;
//QPushButton *compareTile;//Mmods
//QHash<QString, QPushButton*> tileMap;

MainWindow::~MainWindow()
{
}


void MainWindow::onAddTreeTile(std::string& key){

    QPushButton* newTile = new QPushButton(ui->centralwidget);
    // create new tree node
    newTile->setGeometry(340,110, 0, 0);
    newTile->setText(QString::fromStdString(key));//Mmod
    newTile->setProperty("remove",false);// won't remove tile if false--set to true to remove on click

    connect(newTile, &QPushButton::clicked, this, &MainWindow::onRemoveTile);//Mmods
    //onHighlightTile(tile);//test if function works



    // animate tree node
    animation = new QPropertyAnimation(newTile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(newTile->geometry());
    animation->setEndValue(QRect(340,110,50,50));
    animation->start();
    newTile->show();
    tileCount++;
    QString tileString =  "tile" + QString::number(this->tileCount);
    this->tileMap[tileString] = newTile;
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
        endPos = endPos.translated(startingYpos, 0);
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
    drawOutlineRect = false;
    update();
    animation->start();
    currentTile->show();
    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        lineAnimation(this->tileMap["tile1"], this->tileMap["tile2"]); // Call lineAnimation only after movement

        if (animationType == 'r') outlineNode({compareTile, currentTile});
        if (animationType == 'l') outlineNode({currentTile, compareTile});
    });
    //highlightNode({tile});//Jmod ---
    onHighlightTile(this->tileMap["tile2"]);//test if function works--Mmod
}

void MainWindow::onCompareTreeNodes(){
    onMovementTree(this->tileMap["tile2"], this->tileMap["tile1"], 'c');
}

void MainWindow::lineAnimation(QPushButton* parent, QPushButton* child){//Jmods
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
void MainWindow::moveLine(){//Jmods
    if(lineAnimationStep >= totalLineSteps){
        lineAnimationTimer->stop();
        drawingLine = false;
        return;
    }
    QRect childPos = this->tileMap["tile2"]->geometry();
    qreal progress = (qreal)lineAnimationStep / totalLineSteps;
    movingPoint.setX(lineParent.x() + (progress*(lineChild.x()- lineParent.x())));
    movingPoint.setY(lineParent.y() + (progress * (childPos.center().y() - lineParent.y())));
    animatedLine = QLine(lineParent, movingPoint);

    update();
    lineAnimationStep++;

}


void MainWindow::onLeftTreeNode(){
    onMovementTree(this->tileMap["tile2"], this->tileMap["tile1"], 'l');//Mmods
}

void MainWindow::onRightTreeNode(){
    onMovementTree(this->tileMap["tile2"], this->tileMap["tile1"], 'r');
}
void MainWindow::onRemoveWidget() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}

void MainWindow::onChildTreeNode(){
    onMovementTree(this->tileMap["tile2"], this->tileMap["tile1"], 'h');
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
    if(drawOutlineRect){
        painter.drawRect(outlineRect);
    }

}

//input can be put in as {tile1, tile2, tile3} even if it's a single tile
void MainWindow::highlightNode(const QList<QPushButton*>& tiles){//Jmods
    for(int i = 0; i < tiles.count(); i++){
        if(tiles[i]){
            tiles[i]->setStyleSheet("background-color: orange;");
        }
    }
}
void MainWindow::highlightNodeWithColor(const QList<QPushButton*>& tiles, const QString& color){//Jmods
    for(int i = 0; i < tiles.count(); i++){
        if(tiles[i]){
            tiles[i]->setStyleSheet(QString("background-color: %1").arg(color));
        }
    }
}
void MainWindow::shiftNode(const QList<QPushButton*>& tiles){//Jmods
    for(int i = 0; i < tiles.count(); i++){
        int shiftAmount = nodeWidth/2;
        QRect endPos;
        if(tiles[i]){
            endPos = tiles[i]->geometry();
            endPos = endPos.translated(-shiftAmount,0); //based on tile width + spac
            // animate tree node
            animation = new QPropertyAnimation(tiles[i], "geometry");
            animation->setDuration(250);
            animation->setStartValue(tiles[i]->geometry());
            animation->setEndValue(endPos);
            animation->start();
            tiles[i]->show();
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
void MainWindow::outlineNode(const QList<QPushButton*>& tiles){
    //drawOutlineRect = false;
    //update();
    rectWidth = ((nodeWidth)*tiles.count()+45);
    rectHeight = (nodeHeight+20);
    outlineRect = QRect(tiles[0]->geometry().x()-10, tiles[0]->geometry().y()-10, rectWidth, rectHeight);
    drawOutlineRect = true;
    update();
}
