#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <queue>
#include <string>
#include <cmath>
#include <QtCore/qforeach.h>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QMap>
#include <QSequentialAnimationGroup>
#include <QLayout>
#include <vector>
#include <format>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(max_degree_combo_index_changed(int)));

    inputErrorMsgBox.setIcon(QMessageBox::Critical);
    inputErrorMsgBox.setText("Please enter a valid input");

    // By default, all trees max key is 3
    max_degree = 3;
    b_tree = new BTree(max_degree);
    bplus_tree = new BPlusTree(max_degree);
    bstar_tree = new BStarTree(max_degree);

    // identifier for which tree the user is currently using
    // 1 = B Tree, 2 = B+Tree, 3 = B*Tree
    // The default is B Tree
    tree_identifier = 1;
}
// Public Var
std::string intStr = "";// temporary string for ints
std::string keyStr = "";// key string
std::string indStr = "";// index string
std::string refStr = "";// reference key
vector<std::string> instructions;
std::string logStr = "";
int instInd = 0;
bool showIndex = false;
QMap<std::string, QGroupBox *> nodeMap;
QSequentialAnimationGroup animSeq;
std::vector<QGraphicsItemGroup*> displayItems;
QList<QLabel *> connectionLines;

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_insert_button_clicked()
{
    std::string string = ui->input_textbox->text().toStdString();
    if(isNumber(string)){
        if(tree_identifier == 1){
            //B Tree insert
            clearDisplay();
            std::string temp = "";
            for (int i = 0; i < instructions.size(); i ++) {
                qDebug("%s\n", temp.c_str());
                temp += instructions[i];}
            runAnimationString(temp);
            b_tree->insert(ui->input_textbox->text().toInt());
            getInstructionVector();
            runAnimationString(b_tree->getCurrentInstructions());
            queue<BTreeNode*> queue = b_tree->treeToQueue();
            QString instructions(b_tree->getCurrentInstructions());

        }

        if(tree_identifier == 2){   // B+ Insert
            bplus_tree->insert(ui->input_textbox->text().toInt());
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
            QString instructions(bplus_tree->getCurrentInstructions());
        }

        if(tree_identifier == 3){   // B* Insert
            bstar_tree->insert(ui->input_textbox->text().toInt());
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
            QString instructions(bstar_tree->getCurrentInstructions());
        }
    }

    else {
        inputErrorMsgBox.setVisible(true);
    }
}


void MainWindow::on_btree_radio_button_clicked()
{
    tree_identifier = 1;
    resetTrees();
    clearDisplay();
    ui->message_display_textedit->setPlainText("");
    logStr = "";
    instructions.clear();
}


void MainWindow::on_bplus_radio_button_clicked()
{
    tree_identifier = 2;
    resetTrees();
    clearDisplay();
    ui->message_display_textedit->setPlainText("");
    logStr = "";
    instructions.clear();
}


void MainWindow::on_bstar_radio_button_clicked()
{
    tree_identifier = 3;
    resetTrees();
    clearDisplay();
    ui->message_display_textedit->setPlainText("");
    logStr = "";
    instructions.clear();
}


void MainWindow::on_delete_button_clicked()
{
    if(isNumber(ui->input_textbox->text().toStdString())){
        if(tree_identifier == 1){
            //B Tree Remove
            b_tree->remove(ui->input_textbox->text().toInt());
            getInstructionVector();
            queue<BTreeNode*> queue = b_tree->treeToQueue();
        }

        if(tree_identifier == 2){   // B+ Remove
            bplus_tree->remove(ui->input_textbox->text().toInt());
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
            QString instructions(bplus_tree->getCurrentInstructions());
        }

        if(tree_identifier == 3){   // B* Remove
            bstar_tree->remove(ui->input_textbox->text().toInt());
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
            QString instructions(bstar_tree->getCurrentInstructions());
        }
    }
}

void MainWindow::on_clear_button_clicked()
{
    resetTrees();
    clearDisplay();
    ui->message_display_textedit->setPlainText("");
    logStr = "";
    instructions.clear();
}

void MainWindow::max_degree_combo_index_changed(int index)
{
    max_degree = index + 3;
    resetTrees();
    clearDisplay();
    ui->message_display_textedit->setPlainText("");
    logStr = "";
    instructions.clear();
}


// Helper Functions

void MainWindow::resetTrees() {
    delete b_tree;
    delete bplus_tree;
    delete bstar_tree;

    b_tree = new BTree(max_degree);
    bplus_tree = new BPlusTree(max_degree);
    bstar_tree = new BStarTree(max_degree);
}

void MainWindow::clearDisplay()
{
    for (auto [key, node] : nodeMap.asKeyValueRange()){
        delete node;
    }
    QMap<std::string, QGroupBox *> tempMap;
    nodeMap = tempMap;
}

bool MainWindow::isNumber(std::string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)){
        ++it;
    }
    return !s.empty() && it == s.end();
}


void MainWindow::on_find_button_clicked()
{
    if(isNumber(ui->input_textbox->text().toStdString())){
        int findValue = ui->input_textbox->text().toInt();

        if(tree_identifier == 1){
            b_tree->findDeepestOccurance(findValue);
            queue<BTreeNode*> queue = b_tree->treeToQueue();
        }

        if(tree_identifier == 2){   // B+
            bplus_tree->find(findValue);
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
        }

        if(tree_identifier == 3){   // B*
            bstar_tree->find(findValue);
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
        }
    }
    else{
        inputErrorMsgBox.setVisible(true);
    }
}

/*
* wheelEvent is used to zoom in and out of the graphicsView
* using the mouse wheel or the trackpad

void MainWindow::wheelEvent(QWheelEvent * event){
    ui->graphicsView->setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    QGraphicsView::ViewportAnchor anchor = ui->graphicsView->transformationAnchor();
    if(event->angleDelta().y()){    // If the wheelEvent has an angleDelta, we default to using that. Typically when using a mouse wheel.
        int angle = event->angleDelta().y();
        qreal factor;
        if(angle > 0){  // If the angle is greater than 0, we zoom in
            factor = 1.05;
        }
        else{   // If the angle is less than 0, we zoom out
            factor = 0.95;
        }
        ui->graphicsView->scale(factor, factor);    // Scales the viewpoint
        ui->graphicsView->setTransformationAnchor(anchor);  // sets the anchor
    }
    else if(event->hasPixelDelta()){    // If the wheelEvent has pixelDelta, we will use it instead. Typically when user is using a trackpad
        int pixels = event->pixelDelta().y();   // Gets the number of pixels moved in the y direction, ignoring the x direction
        qreal factor;
        if(pixels > 0){
            factor = 1.05;
        }
        else{
            factor = 0.95;
        }
        ui->graphicsView->scale(factor, factor);    // Scales the viewpoint
        ui->graphicsView->setTransformationAnchor(anchor);  // sets the anchor
    }
}
*/

/* labeled 'k'
 * Follows: %d.k
   Line: "Key %d was created"*/
void MainWindow::createKey(std::string key){
    // create new key
    QLabel * Qkey = new QLabel(ui->tree);
    Qkey->setGeometry(340,110, 50, 25);
    Qkey->setText(QString::fromStdString(key));
    QFont font = QFont();
    font.setPointSize(10);
    Qkey->setFont(font);

    // place key in spawn node
    ui->spawnNode->layout()->addWidget(Qkey);
    ui->spawnNode->show();
    Qkey->show();
    ui->spawnNode->show();

}
/* labeled 'n'
 * Follows: %d*n
   Line: "Node %d created as child to node %d"*/
void MainWindow::createNode(std::string index) {
    QGroupBox* Qnode = new QGroupBox(ui->tree);
    Qnode->setLayout(new QHBoxLayout());

    // Set style
    QPalette p = Qnode->palette();
    p.setColor(QPalette::Window, Qt::lightGray);
    Qnode->setPalette(p);
    Qnode->setAutoFillBackground(true);

    // Store in map
    nodeMap[index] = Qnode;
    if(showIndex) Qnode->setTitle(QString::fromStdString("Node " + index));

}

/* labeled 'g'
 * Follows: %d.%d*%d*g
   Line: "Key %d was moved from node %d to %d"*/
void MainWindow::gotoNode(std::string curIndex, std::string newIndex, std::string key){
    //qDebug("Go To Node:\n\tCurrent Index: %s\n\tNew Index: %s\n\tKey:%s",curIndex.c_str(),newIndex.c_str(),key.c_str());
    QGroupBox * curNode;
    // check if newIndex is empty
    if (newIndex == ""){
        // if it is, swap new and current and set current to spawn
        newIndex = curIndex;
        curNode = ui->spawnNode;
    }
    else curNode = nodeMap.find(curIndex).value();
    // check that both newIndex exist
    if (!nodeMap.contains(newIndex)){ createNode(newIndex);
        //qDebug("\tGenerating Node for %s", newIndex.c_str());
    }

    // get node to place tile in
    QGroupBox * newNode = nodeMap.find(newIndex).value();
    // get key
    //qDebug("Current Index: %s\nCurrent Exists: %s",curIndex.c_str(),(nodeMap.contains(curIndex)) ? "1" : "0");
    QList<QLabel *> keys = curNode->findChildren<QLabel *>();
    //qDebug("test");
    QLabel * keyRef = NULL;
    for (auto it : keys){
        QLabel* currentLabel = it;
        if (currentLabel->text() == QString::fromStdString(key)){
            keyRef = currentLabel;
            break;
        }
    }
    if(keyRef == NULL) return;

    // move key to node location
    curNode->layout()->removeWidget(keyRef);
    newNode->layout()->addWidget(keyRef);

    newNode->show();
    curNode->show();
    keyRef->show();
    // compare tiles for each tile in node until placed correctly
}
/* labeled 'c'
 * Follows: %d.%d.%d*t
   Line: "Key %d was moved to the (left/right) of %d in node %d"*/
bool MainWindow::compareTiles(std::string curKey, std::string refKey, std::string index){
    // get current nodes index

    // get current keys tile name

    // get refernce keys tile name

    // compare each and move left or right respectively

    // update nodes list respectively

    // return true if larger
    return true;
}

/* labeled 'r'
 * Follows: %d.%d*r
   Line: "Key %d in node %d was removed"*/
void MainWindow::removeTile(std::string key, std::string index){
    // get node at index

    // get key in node

    // delete tile

    // delete references

    // resize node
}

/* labeled 'd'
 * Follows: %d*d
   Line: "Node %d was removed"*/
void MainWindow::removeNode(std::string index){
    // get node at index

    // get parent node

    // move all keys in node to parent

    // remove node

    // unreference node

    // respace nodes
}
/* labeled 'l'
 * Follows: %d*l
   Line: "Node %d was highlighted"*/
void MainWindow::highlightNode(std::string index){
    // get node at index

    // change color
}
/* labeled 'h'
 * Follows: %d*h
   Line: "Node %d was resized"*/
void MainWindow::highlightTile(std::string key, std::string index){
    // get node at index

    // get key

    // change color
}

/* labeled 'z'
 * Follows: %d*z
   Line: "Node %d was resized"*/
void MainWindow::resizeNode(std::string index){
    // get node at index

    // get number of tiles

    // resize in respect to amount

    // respace nodes
}

/* labeled 'a'
 * Follows: a
   Line: "Respaced nodes"*/
void MainWindow::respaceNodes() {
    lineAnimationTimer = new QTimer(this);//Jmods
    connect(lineAnimationTimer, &QTimer::timeout, this, &MainWindow::moveLine);
    lines.clear();
    update();
    if (nodeMap.isEmpty()) return;
    // Constants for layout
    const int levelHeight = 100;  // Vertical space between levels
    const int siblingSpacing = 50; // Horizontal space between siblings
    const int nodeWidth = 100;
    const int nodeHeight = 50;
    const int startY = 10;

    // First, organize nodes by their depth level
    QMap<int, QList<QGroupBox*>> nodesByLevel;

    for (auto [key, node] : nodeMap.asKeyValueRange()) {
        // Count slashes to determine level depth
        int level = std::count(key.begin(), key.end(), '/');

        // Rename all nodes
        if(showIndex) node->setTitle(QString::fromStdString(key));
        nodesByLevel[level].append(node);
    }

    // Position nodes level by level from top to bottom
    for (auto level : nodesByLevel.keys()) {
        int yPos = startY + level * levelHeight;
        QList<QGroupBox*> levelNodes = nodesByLevel[level];

        // Calculate total width needed for this level
        int totalWidth = levelNodes.size() * nodeWidth +
                         (levelNodes.size() - 1) * siblingSpacing;

        int startX = (ui->tree->width() - totalWidth) / 2;

        // Position each node in this level
        for (int i = 0; i < levelNodes.size(); i++) {
            QGroupBox* node = levelNodes[i];
            node->setGeometry(startX + i * (nodeWidth + siblingSpacing),
                              yPos,
                              nodeWidth,
                              nodeHeight);
            node->show();
        }
    }

    // Draw connections
    for (auto [key, node] : nodeMap.asKeyValueRange()) {
        std::string parentKey = key.substr(0, key.find_last_of('/'));
        if (nodeMap.contains(parentKey)) {
            QGroupBox* parent = nodeMap[parentKey];
            QGroupBox* child = node;

            lineAnimation(parent,child);
            update();
        }
    }
}
/* labeled 's'
 * Follows: %s*s
 * Line: split node
 * NOTE: call BEFORE the index is changed in BTree->splitnode*/
void MainWindow::splitNode(std::string index) {
    //qDebug("Splitting node %s", index.c_str());
    // Extract parent path
    size_t lastSlash = index.find_last_of('/');
    std::string parentPath = (lastSlash != std::string::npos) ?
                                 index.substr(0, lastSlash) : "";
    // Extract pure index
    std::string pureIndex = index;
    if(lastSlash != std::string::npos) pureIndex.erase(0, parentPath.length() + 1);
    // Get index's number of children
    int childNum = 0;
    int iLevel = std::count(index.begin(), index.end(), '/');
    for (auto [key, node] : nodeMap.asKeyValueRange()){
        if (key.find(index) == 0){
            int level = std::count(key.begin(), key.end(), '/');
            if (level - 1 == iLevel) childNum ++;
        }
    }
    int midway = childNum / 2;

    // Renumber existing nodes
    QMap<std::string, QGroupBox*> newMap;
    for (auto [key, node] : nodeMap.asKeyValueRange()) {
        //qDebug("\tCurrent Key: %s", key.c_str());
        if (index == key) {
            if (parentPath == ""){
                newMap["0/" + key] = node;
                //qDebug("\tNew Key: 0/%s\n", key.c_str());
            }
            else {
                newMap[key] = node;
                //qDebug("\tNew Key: %s\n", key.c_str());
            }
        }
        // Check if Child
        else if (key.find(index) == 0) {
            //qDebug("\tChild of node");
            std::string newKey = parentPath;
            if (newKey == "") newKey += "0/";
            else newKey += "/";
            // For child reassignment
            std::string midKey = key.substr(index.length() + 1);
            std::string endKey = midKey;
            if (midKey.find_first_of("/") != std::string::npos){
                midKey.erase(midKey.find_first_of("/"),midKey.length() - 1);
                endKey.erase(0, endKey.find_first_of("/"));
            }
            else endKey = "";

            // Check if to the Left
            if (stoi(midKey) < midway){
                newKey += pureIndex + "/" + midKey + endKey;
            }
            else newKey += std::to_string(stoi(pureIndex) + 1) + "/" + std::to_string(stoi(midKey) - midway) + endKey;
            newMap[newKey] = node;
            //qDebug("\tNew Key: %s\n\tMid Key: %s\n\tEnd Key: %s\n", newKey.c_str(), midKey.c_str(),endKey.c_str());
        // Check if Sibling or Niece
        } else if (key.find(parentPath) == 0 && key.length() != parentPath.length()) {
            //qDebug("\tSibling of node");
            std::string midKey = key.substr(parentPath.length() + 1);
            std::string endKey = midKey;
            // Check if Niece
            if(midKey.find_first_of("/") != std::string::npos){
                midKey.erase(midKey.find_first_of("/"),midKey.length() - 1);
                endKey.erase(0, endKey.find_first_of("/"));
            }
            else endKey = "";
            std::string newKey = parentPath;
            if (newKey == "") newKey += "0/";
            else newKey += "/";
            // Check if to the Left
            if (stoi(midKey) <= stoi(pureIndex)){
                newKey += midKey + endKey;
            }
            else newKey += std::to_string(stoi(midKey) + 1) + endKey;
            newMap[newKey] = node;
            //qDebug("\tNew Key: %s\n", newKey.c_str());
        } else {
            newMap[key] = node;
            //qDebug("\tNew Key: %s\n", key.c_str());
        }
    }

    nodeMap = newMap;
}



void MainWindow::runAnimationString(std::string inst){
    for(char& c : inst){
        callAnimation(c);
    }
    displayInstr(logStr);
    logStr = "";
}
void MainWindow::lineAnimation(QGroupBox* parent, QGroupBox* child) {
    if (!parent || !child) return;

    QRect parentPos = parent->geometry();
    QRect childPos = child->geometry();

    lineParent = QPoint(parentPos.center().x(), parentPos.center().y()+100);
    lineChild = QPoint(childPos.center().x(), childPos.center().y()+100);

    // Store the line data (don't draw it yet)
    LineData newLine;
    newLine.start = lineParent;
    newLine.end = lineChild;
    lines.append(newLine); // Save the line to the list

    movingPoint = lineParent;
    lineAnimationStep = 0;
    drawingLine = true;
    lineAnimationTimer->start(10);
}

void MainWindow::paintEvent(QPaintEvent *event) { //Jmods
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 5));


    if(drawingLine){
        painter.drawLine(animatedLine);
    }
    for (const LineData &line : lines) {
        painter.drawLine(line.start, line.end);
    }
}

void MainWindow::moveLine() {
    if (lineAnimationStep >= totalLineSteps) {
        lineAnimationTimer->stop();
        drawingLine = false;
        return;
    }
    qreal progress = (qreal)lineAnimationStep / totalLineSteps;
    movingPoint.setX(lineParent.x() + (progress * (lineChild.x() - lineParent.x())));
    movingPoint.setY(lineParent.y() + (progress * (lineChild.y() - lineParent.y())));
    animatedLine = QLine(lineParent, movingPoint);

    lineAnimationStep++;
}


void MainWindow::callAnimation(char c){
    switch (c) {
    case 'k': // Add key
        createKey(keyStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr += "Created key.\n";
        break;
    case 'n': // Add node
        createNode(indStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr +=("Created a new node.\n");
        break;
    case 'g': // Move to Node
        gotoNode(indStr, refStr,keyStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr +=("Moved key to new node.\n");
        break;
    case 'c': // Compare
        compareTiles(keyStr, refStr, indStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr +=("Compared the keys in give node.\n");
        break;
    case 'r': // Delete key
        removeTile(keyStr, refStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr +=("Deleted node.\n");
        break;
    case 's': // split node
        splitNode(indStr);
        keyStr = "";
        refStr = "";
        indStr = "";
        // Trigger respacing
        respaceNodes();
        logStr +=("Split node because it was too big.\n");
        break;
    case '.': // New int
        if(keyStr == "") keyStr = intStr;
        else refStr = intStr;
        intStr = "";
        break;
    case '*': // New int
        if(indStr == "") {
            //qDebug("Setting Index to %s\n",intStr.c_str());
            indStr = intStr;}
        else {
            //qDebug("Setting Reference Index to %s\n",intStr.c_str());
            refStr = intStr;}
        intStr = "";
        break;
    case ',':
        break;
    default:
        // check if its a digit for a key
        intStr += c;
        break;
    }
}

void MainWindow::displayInstr(std::string instructions){
    ui->message_display_textedit->setPlainText(QString::fromStdString(instructions));
}

void MainWindow::getInstructionVector(){
    qDebug("%s", b_tree->getCurrentInstructions());
    std::string fullInstr = b_tree->getCurrentInstructions();
    std::string partInstr = "";
    for(char& c: fullInstr){
        qDebug("%c",c);
        if(c == ','){
            qDebug("%s", partInstr.c_str());
            instructions.push_back(partInstr);
            partInstr = "";
        } else partInstr += c;
    }

}

void MainWindow::on_step_forward_button_clicked()
{
    if (instructions.empty()) getInstructionVector();
    if (instructions.empty()) return;
    instInd ++;
    if (instInd >= instructions.size()) instInd = 0;
    clearDisplay();
    std::string tempInst = "";
    for (int i = 0; i <= instInd; i ++) tempInst += instructions[i];
    qDebug("%s", tempInst.c_str());
    runAnimationString(tempInst);

}

void MainWindow::on_step_back_button_clicked()
{
    if (instructions.empty()) getInstructionVector();
    if (instructions.empty()) return;
    instInd --;
    if (instInd < 0) instInd = instructions.size() - 1;
    clearDisplay();
    std::string tempInst = "";
    for (int i = 0; i <= instInd; i ++) tempInst += instructions[i];
    qDebug("%s", tempInst.c_str());
    runAnimationString(tempInst);
}

