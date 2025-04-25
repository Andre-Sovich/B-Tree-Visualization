#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QTimer>
#include <QHash>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(
        ui->createButton, &QPushButton::clicked,
        this, &MainWindow::runAnimationString);

    QObject::connect(
        ui->compareButton, &QPushButton::clicked,
        this, &MainWindow::runAnimationString);
    QObject::connect(
        ui->leftButton, &QPushButton::clicked,
        this, &MainWindow::runAnimationString);
    QObject::connect(
        ui->rightButton, &QPushButton::clicked,
        this, &MainWindow::runAnimationString);
    QObject::connect(
        ui->childButton, &QPushButton::clicked,
        this, &MainWindow::runAnimationString);
}
//global variables
std::string instrStr = "12.a12.0.c12.0.l"; //instruction string
std::string intStr = "";// temporary string for ints
std::string keyStr = "";// key string
std::string refStr = "";// reference key
bool setRef = false; // reference set
QHash<std::string,QPushButton *> treeHash;
QSequentialAnimationGroup animSeq;


MainWindow::~MainWindow()
{
}

void MainWindow::onAddTreeNode(std::string key){

    QPushButton * tile = new QPushButton(ui->centralwidget);
    // create new tree node
    tile->setGeometry(340,110, 0, 0);
    tile->setText(QString::fromStdString(key));
    // add to hash map
    treeHash[key] = tile;
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(QRect(340,110,50,50));
    animation->start();
    tile->show();
}

void MainWindow::onCompareTreeNodes(std::string key,std::string refKey){
    //get key
    QPushButton * tile = treeHash[key];
    // get ref
    QPushButton * refTile = treeHash[refKey];
    // find new position
    QRect endPos = refTile->geometry();
    endPos = endPos.translated(0,-60); //based on tile -1 * (height + space)
    treeHash[key] = tile;
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    //tile->show();
}

void MainWindow::onLeftTreeNode(std::string key,std::string refKey){
    //get key
    QPushButton * tile = treeHash[key];
    // get ref
    QPushButton * refTile = treeHash[refKey];
    // find new position
    QRect endPos = refTile->geometry();
    endPos = endPos.translated(-50,0); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    //tile->show();
}

void MainWindow::onRightTreeNode(std::string key,std::string refKey){
    //get key
    QPushButton * tile = treeHash[key];
    // get ref
    QPushButton * refTile = treeHash[refKey];
    // find new position
    QRect endPos = refTile->geometry();
    endPos = endPos.translated(50,0); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    //tile->show();
}
void MainWindow::onRemoveWidget(std::string key,std::string refKey) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}

void MainWindow::onChildTreeNode(std::string key,std::string refKey){
    //get key
    QPushButton * tile = treeHash[key];
    // get ref
    QPushButton * refTile = treeHash[refKey];
    // find new position
    QRect endPos = refTile->geometry();
    endPos = endPos.translated(0,80); //based on tile width + spac
    // animate tree node
    animation = new QPropertyAnimation(tile, "geometry");
    animation->setDuration(250);
    animation->setStartValue(tile->geometry());
    animation->setEndValue(endPos);
    animation->start();
    //tile->show();
}


void MainWindow::runAnimationString(){
    // Do not add
    treeHash["0"] = ui->tile2;
    for(char& c : instrStr){
        callAnimation(c);
    }
}

void MainWindow::callAnimation(char c){
    switch (c) {
    case 'a': // Add
        onAddTreeNode(keyStr);
        keyStr = "";
        refStr = "";
        break;
    case 'c': // Compare
        onCompareTreeNodes(keyStr, refStr);
        keyStr = "";
        refStr = "";
        break;
    case 'l': // Left
        onLeftTreeNode(keyStr, refStr);
        keyStr = "";
        refStr = "";
        break;
    case 'r': // Right
        onRightTreeNode(keyStr, refStr);
        keyStr = "";
        refStr = "";
        break;
    case 'h': // Child
        onChildTreeNode(keyStr, refStr);
        keyStr = "";
        refStr = "";
        break;
    case 'd': // Delete
        onRemoveWidget(keyStr, refStr);
        keyStr = "";
        refStr = "";
        break;
    case '.': // New int
        if(keyStr == "") keyStr = intStr;
        else refStr = intStr;
        intStr = "";
        break;

    default:
        // check if its a digit for a key
        if(isdigit(c)){
            intStr += c;
        }
        break;
    }
}

