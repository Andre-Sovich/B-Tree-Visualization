#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QTimer>//Jmods
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tileCount = 0;// intialize count
    ui->setupUi(this);
    QObject::connect(
        ui->createButton, &QPushButton::clicked,
        this, [this]() {
            QString inputNum = ui->lineEdit->text();// Test with input number entered from lineEdit--MMods
            bool validNum;
            int number = inputNum.toInt(&validNum);
            QString key;
            if (validNum) {
                key = inputNum;
                onAddTreeTile(key);//onAddTreeTile adds the key to titlemap
            }
    });

    QObject::connect(ui->compareButton, &QPushButton::clicked, this, [this]() {
        // QString ogkey= "tile" + QString::number(this->tileCount);
        // QString ogref= "tile" + QString::number(this->tileCount++);
        // if(tileCount>0){
        //     onCompareTreeNodes(ogkey,ogref);
        // }
        if (tileKeys.size() >= 2) {
            QString key = tileKeys[tileKeys.size() - 2];
            QString ref = tileKeys[tileKeys.size() - 1];
            onCompareTreeNodes(key, ref);
        }else{
            QString key = tileKeys[tileKeys.size() - 1];
            QString ref = tileKeys[tileKeys.size() - 1];
            onCompareTreeNodes(key, ref);

        }
    });
    QObject::connect(ui->leftButton, &QPushButton::clicked, this, [this]() {
        // QString ogkey= "tile" + QString::number(this->tileCount);
        // QString ogref= "tile" + QString::number(this->tileCount++);
        // if(tileCount>=1){
        //     onLeftTreeNode(ogkey, ogref);
        // }
        if (tileKeys.size() >= 2) {
            QString key = tileKeys[tileKeys.size() - 2];
            QString ref = tileKeys[tileKeys.size() - 1];
            onLeftTreeNode(key, ref);
        }else{
            QString key = tileKeys[tileKeys.size() - 1];
            QString ref = tileKeys[tileKeys.size() - 1];
            onLeftTreeNode(key, ref);

        }
    });
    QObject::connect(ui->rightButton, &QPushButton::clicked, this, [this]() {
        // QString ogkey= "tile" + QString::number(this->tileCount);
        // QString ogref= "tile" + QString::number(this->tileCount++);
        // onRightTreeNode(ogkey, ogref);
        if (tileKeys.size() >= 2) {
            QString key = tileKeys[tileKeys.size() - 2];
            QString ref = tileKeys[tileKeys.size() - 1];
            onRightTreeNode(key, ref);
        }else{
            QString key = tileKeys[tileKeys.size() - 1];
            QString ref = tileKeys[tileKeys.size() - 1];
            onRightTreeNode(key, ref);

        }
    });
    QObject::connect(ui->childButton, &QPushButton::clicked, this, [this]() {
        // QString ogkey= "tile" + QString::number(this->tileCount);
        // QString ogref= "tile" + QString::number(this->tileCount++);
        // onChildTreeNode(ogkey, ogref);//Mmods because functions refactored
        if (tileKeys.size() >= 2) {
            QString key = tileKeys[tileKeys.size() - 2];
            QString ref = tileKeys[tileKeys.size() - 1];
            onChildTreeNode(key, ref);
        }else{
            QString key = tileKeys[tileKeys.size() - 1];
            QString ref = tileKeys[tileKeys.size() - 1];
            onChildTreeNode(key, ref);

        }
    });
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


MainWindow::~MainWindow()
{
}


void MainWindow::onAddTreeTile(QString& key){

    QPushButton* newTile = new QPushButton(ui->centralwidget);
    // create new tree node
    newTile->setGeometry(340,110, 0, 0);
    newTile->setText(key);//Mmod
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
    //qDebug() << "Tile count:" << tileCount;
    tileCount++;
    //qDebug() << "Tile count:" << tileCount;
    QString tileString =  "tile" + QString::number(this->tileCount);
    this->tileMap[tileString] = newTile;
    this->tileKeys.append(tileString);//MMods
}

void MainWindow::onMovementTree(QString& key,QString& ref, char animationType){//Mmods
    QPushButton* currentTile = tileMap[key];// Changed all std::string to QString to follow hashmap
    QPushButton* compareTile = tileMap[ref];
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
        lineAnimation(tileMap["tile1"], tileMap["tile2"]); // Call lineAnimation only after movement

        if (animationType == 'r') outlineNode({compareTile, currentTile});
        if (animationType == 'l') outlineNode({currentTile, compareTile});
    });
    //highlightNode({tile});//Jmod ---
    onHighlightTile(this->tileMap[ref]);//test if function works--Mmod
}

void MainWindow::onCompareTreeNodes(QString& key,QString& ref){
    onMovementTree(ref,key, 'c');
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


void MainWindow::onLeftTreeNode(QString& key,QString& ref){
    onMovementTree(key, ref, 'l');
}

void MainWindow::onRightTreeNode(QString& key,QString& ref){
    onMovementTree(key,ref, 'r');
}
void MainWindow::onRemoveWidget(QString& key) {
    QPushButton* button = tileMap[key];
    if (button) {
        delete button;
        tileMap.remove(key);
    }
    // QPushButton* button = qobject_cast<QPushButton*>(sender());
    // delete button;
}

void MainWindow::onChildTreeNode(QString& key,QString& ref){
    onMovementTree(key,ref, 'h');
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
