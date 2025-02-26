#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <queue>
#include <string>
#include <cmath>
#include <optional>
#include <QtCore/qforeach.h>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);


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
    //All variables needed in the display functions and theif defaults.
    int oldHeight = 0;
    int currentY = 0;
    int minX = 0;
    int maxX = 0;
    int currentDx = 0;
    int currentX = 0;
    int rectWidth = 50 * (MainWindow::max_degree - 1);
    int rectHeight = 25;
    int gapSize = 25;
    int layerLevel = 0;
    int height = -1;
    int parentIndex = 0;
    int childIndex = 0;
    int currentParentDx = 0;
    int parentLength = 0;
    vector<int> prevXs;
    vector<int> currentXs;
}

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
            b_tree->insert(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BTreeNode*> queue = b_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(b_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 2){   // B+ Insert
            bplus_tree->insert(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(bplus_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 3){   // B* Insert
            bstar_tree->insert(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(bstar_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }
    }

    else {
        inputErrorMsgBox.setVisible(true);
    }
}


void MainWindow::on_delete_textbox_copyAvailable(bool b)
{

}


void MainWindow::on_btree_radio_button_clicked()
{
    tree_identifier = 1;
    resetTrees();
    clearDisplay();
}


void MainWindow::on_bplus_radio_button_clicked()
{
    tree_identifier = 2;
    resetTrees();
    clearDisplay();
}


void MainWindow::on_bstar_radio_button_clicked()
{
    tree_identifier = 3;
    resetTrees();
    clearDisplay();
}


void MainWindow::on_delete_button_clicked()
{
    if(isNumber(ui->input_textbox->text().toStdString())){
        if(tree_identifier == 1){
            //B Tree Remove
            b_tree->remove(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BTreeNode*> queue = b_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(b_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 2){   // B+ Remove
            bplus_tree->remove(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(bplus_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 3){   // B* Remove
            bstar_tree->remove(ui->input_textbox->text().toInt());
            clearDisplay();
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
            displayTreeFromQueue(queue, std::nullopt);
            QString instructions(bstar_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }
    }
}

void MainWindow::on_clear_button_clicked()
{
    resetTrees();
    clearDisplay();
    ui->graphicsView->resetTransform();
    ui->graphicsView->centerOn(0, 0);
    ui->message_display_textedit->setPlainText("");
}

void MainWindow::max_degree_combo_index_changed(int index)
{
    max_degree = index + 3;
    resetTrees();
    clearDisplay();
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
    while(displayItems.size() > 0) {
        displayItems.pop_back();
    }
    scene.clear();
}

bool MainWindow::isNumber(std::string s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)){
        ++it;
    }
    return !s.empty() && it == s.end();
}

void MainWindow::displayTreeFromQueue(queue<BPlusTreeNode*> q, std::optional<int> find_value) {
    BPlusTreeNode* currentNode = nullptr;
    BPlusTreeNode* oldParent = nullptr;
    initializeVariables();
    vector<int> prevXs;
    vector<int> currentXs;

    while (!q.empty()) {
        currentNode = q.front();
        q.pop();
        if(currentNode->getKeys()->size() <= 0) {
            break;
        }
        if(height == -1) {
            height = currentNode->getHeight();
            oldHeight = currentNode->getHeight();
            minX = -1 * (((pow(max_degree, height) - 1) * (rectWidth + gapSize)) / 2);
            maxX = (((pow(max_degree, height) - 1) * (rectWidth + gapSize)) / 2);
        }

        // Creates the rectangle to display
        QGraphicsRectItem* item = makeRectangle(rectWidth, rectHeight);

        //Creates Text For Node
        QGraphicsTextItem* text_item = makeQString(makeNodeText(*currentNode));

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        //turns orange if value is found
        if(find_value.has_value()){
            if(currentNode->getIsLeaf() && currentNode->keyExists(find_value.value())){
                QColor* roarange = new QColor(244, 121, 32);
                item->setBrush(*roarange);
            }
        }

        // Group the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Add to the scene and record the position
        displayItems.push_back(node);
        updateLayer(prevXs, currentXs, currentNode, oldParent);

        updateIndexes(prevXs, currentXs, currentNode, oldParent);

        // Set node position
        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
        drawLines(prevXs, currentXs, oldParent);
    }
}

void MainWindow::displayTreeFromQueue(queue<BTreeNode*> q, std::optional<int> find_value) {
    BTreeNode* currentNode = nullptr;
    BTreeNode* oldParent = nullptr;
    initializeVariables();
    vector<int> prevXs;
    vector<int> currentXs;
    while(q.size() > 0) {
        currentNode = q.front();
        q.pop();
        if(currentNode->getKeys().size() <= 0) {
            break;
        }
        if(height == -1) {
            height = currentNode->getHeight();
            oldHeight = currentNode->getHeight();
            minX = -1 * (((pow(max_degree, height) - 1) * (rectWidth + gapSize)) / 2);
            maxX = (((pow(max_degree, height) - 1) * (rectWidth + gapSize)) / 2);
        }

        // Creates the rectangle to display
        QGraphicsRectItem* item = makeRectangle(rectWidth,rectHeight);

        // Creates the text to display within the rectangle
        QGraphicsTextItem* text_item = makeQString(makeNodeText(*currentNode));

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        //Makes rectangle orange
        if(find_value.has_value()){
            if(currentNode->keyExists(find_value.value())){
                QColor* roarange = new QColor(244, 121, 32);
                item->setBrush(*roarange);
            }
        }
        // Groups the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Adds the grouping and our display items
        displayItems.push_back(node);

        updateLayer(prevXs, currentXs, currentNode, oldParent);
        updateIndexes(prevXs, currentXs, currentNode, oldParent);


        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
        drawLines(prevXs, currentXs, oldParent);
    }
}

void MainWindow::on_find_button_clicked()
{
    if(isNumber(ui->input_textbox->text().toStdString())){
        int findValue = ui->input_textbox->text().toInt();

        if(tree_identifier == 1){
            clearDisplay();
            b_tree->findDeepestOccurance(findValue);
            queue<BTreeNode*> queue = b_tree->treeToQueue();
            displayTreeFromQueue(queue, findValue);
            QString instructions(bplus_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 2){   // B+
            clearDisplay();
            bplus_tree->find(findValue);
            queue<BPlusTreeNode*> queue = bplus_tree->treeToQueue();
            displayTreeFromQueue(queue, findValue);
            QString instructions(bplus_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }

        if(tree_identifier == 3){   // B*
            clearDisplay();
            bstar_tree->find(findValue);
            queue<BPlusTreeNode*> queue = bstar_tree->treeToQueue();
            displayTreeFromQueue(queue, findValue);
            QString instructions(bstar_tree->getCurrentInstructions());
            ui->message_display_textedit->setPlainText(instructions);
        }
    }
    else{
        inputErrorMsgBox.setVisible(true);
    }
}

/*
* wheelEvent is used to zoom in and out of the graphicsView
* using the mouse wheel or the trackpad
*/
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

//These are all helper functions for the display functions
QGraphicsRectItem* MainWindow::makeRectangle(int rectWidth, int rectHeight){
    QGraphicsRectItem* item = new QGraphicsRectItem(0,0,rectWidth,rectHeight);
    QColor* roaring_light_grey = new QColor(230, 231, 232);
    item->setBrush(*roaring_light_grey);
    return item;
}

string MainWindow::makeNodeText(BTreeNode currentNode){
    vector<int> keys = currentNode.getKeys();
    string output = "";
    for(int i = 0; i < keys.size(); i++){
        output += to_string(keys[i]);
        if( i != keys.size() - 1){
            output += "|";
        }
    }
    return output;
}
string MainWindow::makeNodeText(BPlusTreeNode currentNode){
    vector<int> keys = *(currentNode.getKeys());
    string output = "";
    for(int i = 0; i < keys.size(); i++){
        output += to_string(keys[i]);
        if( i != keys.size() - 1){
            output += "|";
        }
    }
    return output;
}
QGraphicsTextItem* MainWindow::makeQString(string input){
    QString* text = new QString(QString::fromStdString(input));
    QGraphicsTextItem* text_item = new QGraphicsTextItem(*text);
    text_item->setDefaultTextColor(Qt::black);
    return text_item;
}
void MainWindow::updateLayer(vector<int>& prevXs, vector<int>& currentXs, BPlusTreeNode* currentNode, BPlusTreeNode*& oldParent){
    if(oldHeight != currentNode->getHeight()) {
        // Increase layer level, since we've gone down a layer in the tree
        layerLevel++;
        oldHeight = currentNode->getHeight();

        // Calculate the new Y coordinate for the new layer
        currentY = (layerLevel * rectHeight) + (layerLevel * gapSize);

        // Calculate the difference between nodes for the current layer.
        // ((k^h) * (w + g)) / (k^l)
        currentDx = ((pow(max_degree, height) * (rectWidth + gapSize)) / pow(max_degree, layerLevel));

        // Calculate the furthest left node's placement. DOUBLE CHECK THIS
        currentX = minX + (((maxX - minX) % currentDx) / 2);

        // Updating the parent references.
        oldParent = currentNode->getParent();

        // Swap prevXs and currentXs since we're in a new layer of the tree
        prevXs.swap(currentXs);

        // Clear currentXs
        currentXs.clear();

        // Reset parent and child index for new layer
        parentIndex = 0;
        childIndex = 0;

        parentLength = ((((max_degree - 1) - (max_degree / 2)) * currentDx) + prevXs[parentIndex]) - (((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex]) + rectWidth;
        currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
        return;
    }
}
void MainWindow::updateLayer(vector<int>& prevXs, vector<int>& currentXs, BTreeNode* currentNode, BTreeNode*& oldParent){
    if(oldHeight != currentNode->getHeight()) {
        // Increase layer level, since we've gone down a layer in the tree
        layerLevel++;
        oldHeight = currentNode->getHeight();

        // Calculate the new Y coordinate for the new layer
        currentY = (layerLevel * rectHeight) + (layerLevel * gapSize);

        // Calculate the difference between nodes for the current layer.
        // ((k^h) * (w + g)) / (k^l)
        currentDx = ((pow(max_degree, height) * (rectWidth + gapSize)) / pow(max_degree, layerLevel));

        // Calculate the furthest left node's placement. DOUBLE CHECK THIS
        currentX = minX + (((maxX - minX) % currentDx) / 2);

        // Updating the parent references.
        oldParent = currentNode->getParent();

        // Swap prevXs and currentXs since we're in a new layer of the tree
        prevXs.swap(currentXs);

        // Clear currentXs
        currentXs.clear();

        // Reset parent and child index for new layer
        parentIndex = 0;
        childIndex = 0;

        parentLength = ((((max_degree - 1) - (max_degree / 2)) * currentDx) + prevXs[parentIndex]) - (((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex]) + rectWidth;
        currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
        return;
    }
}
void MainWindow::updateIndexes(vector<int>& prevXs, vector<int>& currentXs, BPlusTreeNode*& currentNode, BPlusTreeNode*& oldParent){
    if(oldParent && childIndex < oldParent->getChildren()->size()) {
        if(childIndex == 0) {
            currentX = ((childIndex - (max_degree / 2)) * currentDx) + prevXs[parentIndex];
        }
        if(childIndex != 0) {
            currentX += currentParentDx + rectWidth;
        }

        childIndex++;
    } else if (oldParent != currentNode->getParent()) {
        oldParent = currentNode->getParent();
        parentIndex++;
        currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
        currentX = ((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex];
        childIndex = 1;
    }

}
void MainWindow::updateIndexes(vector<int>& prevXs, vector<int>& currentXs, BTreeNode*& currentNode, BTreeNode*& oldParent){
    if(oldParent && childIndex < oldParent->getChildren()->size()) {
        if(childIndex == 0) {
            currentX = ((childIndex - (max_degree / 2)) * currentDx) + prevXs[parentIndex];
        }
        if(childIndex != 0) {
            currentX += currentParentDx + rectWidth;
        }

        childIndex++;
    } else if (oldParent != currentNode->getParent()) {
        oldParent = currentNode->getParent();
        parentIndex++;
        currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
        currentX = ((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex];
        childIndex = 1;
    }

}
void MainWindow::initializeVariables(){
    oldHeight = 0;
    currentY = 0;
    minX = 0;
    maxX = 0;
    currentDx = 0;
    currentX = 0;
    rectWidth = 50 * (MainWindow::max_degree - 1);
    rectHeight = 25;
    gapSize = 25;
    layerLevel = 0;
    height = -1;
    parentIndex = 0;
    childIndex = 0;
    currentParentDx = 0;
    parentLength = 0;
}
void MainWindow::drawLines(vector<int>& prevXs, vector<int>& currentXs, BTreeNode*& oldParent){
    if (oldParent) {
        int parentX = prevXs[parentIndex];
        int parentY = currentY - (rectHeight + gapSize);

        // Adjust positions for bottom of the parent and top of the child
        int parentBottomX = parentX + rectWidth / 2;
        int parentBottomY = parentY + rectHeight;
        int childTopX = currentX + rectWidth / 2;
        int childTopY = currentY;

        // Create a QPen with a bolder line width
        QPen pen(Qt::black);
        pen.setWidth(2);

        scene.addLine(parentBottomX, parentBottomY, childTopX, childTopY, pen);
    }
}
void MainWindow::drawLines(vector<int>& prevXs, vector<int>& currentXs, BPlusTreeNode*& oldParent){
    if (oldParent) {
        int parentX = prevXs[parentIndex];
        int parentY = currentY - (rectHeight + gapSize);

        // Adjust positions for bottom of the parent and top of the child
        int parentBottomX = parentX + rectWidth / 2;
        int parentBottomY = parentY + rectHeight;
        int childTopX = currentX + rectWidth / 2;
        int childTopY = currentY;

        // Create a QPen with a bolder line width
        QPen pen(Qt::black);
        pen.setWidth(2);

        scene.addLine(parentBottomX, parentBottomY, childTopX, childTopY, pen);
    }
}

