#include "depreciatedMainWindow.h"

depreciatedMainWindow::depreciatedMainWindow() {}

void depreciatedMainWindow::displayTreeFromQueueFind(queue<BTreeNode*> q, int find_value) {
    BTreeNode* currentNode = nullptr;
    BTreeNode* oldParent = nullptr;
    int oldHeight = 0;
    int currentY = 0;
    int minX = 0;
    int maxX = 0;
    int currentDx = 0;
    int currentX = 0;
    int rectWidth = 50 * (max_degree - 1);
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
        QGraphicsRectItem* item = new QGraphicsRectItem(0,0,rectWidth,rectHeight);
        QColor* roaring_light_grey = new QColor(230, 231, 232);
        item->setBrush(*roaring_light_grey);

        // Creates the text to display within the rectangle
        char output[1024] = {};
        for(int i = 0; i < (int)currentNode->getKeys().size(); i++) {
            snprintf(output + strlen(output), sizeof(output), "%d", (currentNode->getKeys())[i]);
            if(i != (int)currentNode->getKeys().size() - 1) {
                snprintf(output + strlen(output), sizeof(output), " | ");
            }
        }
        snprintf(output + strlen(output), sizeof(output), "ID:%s",currentNode->getId().c_str());

        // Creates the visual text item from the text
        QString* text = new QString(output);
        QGraphicsTextItem* text_item = new QGraphicsTextItem(*text);
        text_item->setDefaultTextColor(Qt::black);

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        if(currentNode->keyExists(find_value)){
            QColor* roarange = new QColor(244, 121, 32);
            item->setBrush(*roarange);
        }

        // Groups the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Adds the grouping and our display items
        displayItems.push_back(node);


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
        }
        if(oldParent && childIndex < oldParent->getChildren()->size()) {
            if(childIndex == 0) {
                currentX = ((childIndex - (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            }
            if(childIndex != 0) {
                currentX += currentParentDx + rectWidth;
            }
            childIndex++;
        } else if(oldParent != currentNode->getParent()) {
            oldParent = currentNode->getParent();
            parentIndex++;
            currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
            currentX = ((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            childIndex = 1;
        }

        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
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
}
void depreciatedMainWindow::displayTreeFromQueue(queue<BTreeNode*> q) {
    BTreeNode* currentNode = nullptr;
    BTreeNode* oldParent = nullptr;
    int oldHeight = 0;
    int currentY = 0;
    int minX = 0;
    int maxX = 0;
    int currentDx = 0;
    int currentX = 0;
    int rectWidth = 50 * (max_degree - 1);
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
        QGraphicsRectItem* item = new QGraphicsRectItem(0,0,rectWidth,rectHeight);
        QColor* roaring_light_grey = new QColor(230, 231, 232);
        item->setBrush(*roaring_light_grey);

        // Creates the text to display within the rectangle
        char output[1024] = {};
        for(int i = 0; i < (int)currentNode->getKeys().size(); i++) {
            snprintf(output + strlen(output), sizeof(output), "%d", (currentNode->getKeys())[i]);
            if(i != (int)currentNode->getKeys().size() - 1) {
                snprintf(output + strlen(output), sizeof(output), " | ");
            }
        }

        snprintf(output + strlen(output), sizeof(output), "ID:%s",currentNode->getId().c_str());

        // Creates the visual text item from the text
        QString* text = new QString(output);
        QGraphicsTextItem* text_item = new QGraphicsTextItem(*text);
        text_item->setDefaultTextColor(Qt::black);

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        // Groups the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Adds the grouping and our display items
        displayItems.push_back(node);


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
        }
        if(oldParent && childIndex < oldParent->getChildren()->size()) {
            if(childIndex == 0) {
                currentX = ((childIndex - (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            }
            if(childIndex != 0) {
                currentX += currentParentDx + rectWidth;
            }
            childIndex++;
        } else if(oldParent != currentNode->getParent()) {
            oldParent = currentNode->getParent();
            parentIndex++;
            currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
            currentX = ((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            childIndex = 1;
        }

        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
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
}
void depreciatedMainWindow::displayTreeFromQueueFind(queue<BPlusTreeNode*> q, int find_value) {
    BPlusTreeNode* currentNode = nullptr;
    BPlusTreeNode* oldParent = nullptr;
    int oldHeight = 0;
    int currentY = 0;
    int minX = 0;
    int maxX = 0;
    int currentDx = 0;
    int currentX = 0;
    int rectWidth = 50 * (max_degree - 1);
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
    while(q.size() > 0) {
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
        QGraphicsRectItem* item = new QGraphicsRectItem(0,0,rectWidth,rectHeight);
        QColor* roaring_light_grey = new QColor(230, 231, 232);
        item->setBrush(*roaring_light_grey);

        // Creates the text to display within the rectangle
        char output[1024] = {};
        for(int i = 0; i < (int)currentNode->getKeys()->size(); i++) {
            snprintf(output + strlen(output), sizeof(output), "%d", (*(currentNode->getKeys()))[i]);
            if(i != (int)currentNode->getKeys()->size() - 1) {
                snprintf(output + strlen(output), sizeof(output), " | ");
            }
        }

        snprintf(output + strlen(output), sizeof(output), "ID:%d", currentNode->getHeight());

        // Creates the visual text item from the text
        QString* text = new QString(output);
        QGraphicsTextItem* text_item = new QGraphicsTextItem(*text);
        text_item->setDefaultTextColor(Qt::black);

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        if(currentNode->getIsLeaf() && currentNode->keyExists(find_value)){
            QColor* roarange = new QColor(244, 121, 32);
            item->setBrush(*roarange);
        }

        // Groups the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Adds the grouping and our display items
        displayItems.push_back(node);


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
        }
        if(oldParent && childIndex < oldParent->getChildren()->size()) {
            if(childIndex == 0) {
                currentX = ((childIndex - (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            }
            if(childIndex != 0) {
                currentX += currentParentDx + rectWidth;
            }
            childIndex++;
        } else if(oldParent != currentNode->getParent()) {
            oldParent = currentNode->getParent();
            parentIndex++;
            currentParentDx = (parentLength - (oldParent->getChildren()->size() * rectWidth)) / (oldParent->getChildren()->size() - 1);
            currentX = ((-1 * (max_degree / 2)) * currentDx) + prevXs[parentIndex];
            childIndex = 1;
        }

        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
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
}
void depreciatedMainWindow::displayTreeFromQueue(queue<BPlusTreeNode*> q) {
    BPlusTreeNode* currentNode = nullptr;
    BPlusTreeNode* oldParent = nullptr;
    int oldHeight = 0;
    int currentY = 0;
    int minX = 0;
    int maxX = 0;
    int currentDx = 0;
    int currentX = 0;
    int rectWidth = 50 * (max_degree - 1);
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
        QGraphicsRectItem* item = new QGraphicsRectItem(0,0,rectWidth,rectHeight);
        QColor* roaring_light_grey = new QColor(230, 231, 232);
        item->setBrush(*roaring_light_grey);

        // Create text for the node
        char output[1024] = {};
        for (int i = 0; i < (int)currentNode->getKeys()->size(); i++) {
            snprintf(output + strlen(output), sizeof(output), "%d", (*(currentNode->getKeys()))[i]);
            if (i != (int)currentNode->getKeys()->size() - 1) {
                snprintf(output + strlen(output), sizeof(output), " | ");
            }
        }

        snprintf(output + strlen(output), sizeof(output), "ID:%d", currentNode->getHeight());

        QString* text = new QString(output);
        QGraphicsTextItem* text_item = new QGraphicsTextItem(*text);
        text_item->setDefaultTextColor(Qt::black);

        // Centers the text within the rectangle
        qreal textXPos = (rectWidth / 2) - (text_item->boundingRect().width() / 2);
        text_item->setPos(textXPos, 0);

        // Group the rectangle and text together
        QList<QGraphicsItem*>* nodeComponents = new QList<QGraphicsItem*>({item, text_item});
        QGraphicsItemGroup* node = scene.createItemGroup(*nodeComponents);

        // Add to the scene and record the position
        displayItems.push_back(node);

        if (oldHeight != currentNode->getHeight()) {
            layerLevel++;
            oldHeight = currentNode->getHeight();
            currentY = (layerLevel * rectHeight) + (layerLevel * gapSize);
            currentDx = ((pow(max_degree, height) * (rectWidth + gapSize)) / pow(max_degree, layerLevel));
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
        }

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

        // Set node position
        node->setPos(currentX, currentY);
        currentXs.push_back(currentX);

        // Draw a line from the bottom center of the parent node to the top center of this node
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
            // Create a line item (you might want to manage these separately)
            QGraphicsLineItem* line = new QGraphicsLineItem(parentBottomX, parentBottomY,
                                                            childTopX, childTopY);
            line->setPen(QPen(Qt::black, 2));
            scene.addItem(line);
        }
    }
}

