#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
// #include <QTimer>//Jmods



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(
        ui->createButton, &QPushButton::clicked,
        this, &MainWindow::onAddTreeNode);

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

    // //must initialize line timer--Jmods
    // lineAnimationTimer = new QTimer(this);//Jmods
    // connect(lineAnimationTimer, &QTimer::timeout, this, &MainWindow::moveLine);
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


void MainWindow::onAddTreeNode(){

    tile = new QPushButton(ui->centralwidget);
    // create new tree node
    tile->setGeometry(340,110, 0, 0);
    tile->setText("Tile");
    tile->setProperty("remove",false);// won't remove tile if false--set to true to remove on click

    connect(tile, &QPushButton::clicked, this, &MainWindow::onRemoveTile);//Mmods
   // onHighlightTile(tile);//test if function works



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
}

void MainWindow::onCompareTreeNodes(){
    onMovementTree(tile, ui->tile2, 'c');
    // // find new position
    // QRect endPos = ui->tile2->geometry();
    // endPos = endPos.translated(0,-60); //based on tile -1 * (height + space)
    // // animate tree node
    // animation = new QPropertyAnimation(tile, "geometry");
    // animation->setDuration(250);
    // animation->setStartValue(tile->geometry());
    // animation->setEndValue(endPos);
    // animation->start();
    // tile->show();
}


void MainWindow::onLeftTreeNode(){
    onMovementTree(tile, ui->tile2, 'l');
    // // find new position
    // QRect endPos = ui->tile2->geometry();
    // endPos = endPos.translated(-50,0); //based on tile width + spac
    // // animate tree node
    // animation = new QPropertyAnimation(tile, "geometry");
    // animation->setDuration(250);
    // animation->setStartValue(tile->geometry());
    // animation->setEndValue(endPos);
    // animation->start();
    // tile->show();
}

void MainWindow::onRightTreeNode(){
    onMovementTree(tile, ui->tile2, 'r');
    // // find new position
    // QRect endPos = ui->tile2->geometry();
    // endPos = endPos.translated(50,0); //based on tile width + spac
    // // animate tree node
    // animation = new QPropertyAnimation(tile, "geometry");
    // animation->setDuration(250);
    // animation->setStartValue(tile->geometry());
    // animation->setEndValue(endPos);
    // animation->start();
    // tile->show();
}
void MainWindow::onRemoveWidget() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}

void MainWindow::onChildTreeNode(){
    onMovementTree(tile, ui->tile2, 'h');
    // // find new position
    // QRect endPos = ui->tile2->geometry();
    // endPos = endPos.translated(0,80); //based on tile width + spac
    // // animate tree node
    // animation = new QPropertyAnimation(tile, "geometry");
    // animation->setDuration(250);
    // animation->setStartValue(tile->geometry());
    // animation->setEndValue(endPos);
    // animation->start();
    // tile->show();
}

void MainWindow::on_createButton_clicked()
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 100));
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
