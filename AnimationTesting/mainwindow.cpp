#include "mainwindow.h"
#include "./ui_mainwindow.h"




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
}
//global variables
QPushButton *tile;
QPushButton *currentTile;
QPushButton *compareTile;
MainWindow::~MainWindow()
{
}

void MainWindow::onAddTreeNode(){

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

void MainWindow::onMovementTreeTile(QPushButton* currentTile, QPushButton* compareTile, char animationType){
    // find new position
    QRect endPos = ui->compareTile->geometry();
    endPos = endPos.translated(50,0); //based on tile width + spac // replace with global x and y positon
    // animate tree node
    animation = new QPropertyAnimation(currentTile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(currentTile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    currentTile->show();
}

void MainWindow::onLeftTreeNode(){
    // find new position /// modify to include onMovementTreeTile width x.y //
    QRect endPos = ui->tile2->geometry();
    endPos = endPos.translated(-50,0); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    tile->show();
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
}

// void MainWindow::highlightTiles(){// will use the tilesLL

// }

// void MainWindow::removeTile(){//

// }

void MainWindow::on_createButton_clicked()
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 100));
}

