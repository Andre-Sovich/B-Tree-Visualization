#include <iostream>
#include <queue>
#include "BStarTree.hh"

using namespace std;

/*
BStarTree::BStarTree(int maxKeys)

Creates a new B* Tree with the given value setting the max number of keys per node within the tree.
*/
BStarTree::BStarTree(int maxKeys) {
    maxKeysLeaf = maxKeys;
    root = new BPlusTreeNode(0, true);
}

/*
BPlusTreeNode* BStarTree::getRoot

Returns a pointer to the root of the tree.
*/
BPlusTreeNode* BStarTree::getRoot() {
    return root;
}

char* BStarTree::getCurrentInstructions() {
    return instructions;
}

// Search
/*
BPlusTreeNode* BStarTree::find(int key)

Recursive wrapper for the find(key, currentNode) function. Returns a pointer to the node that contains the given key.
*/
BPlusTreeNode* BStarTree::find(int key) {
    clearInstructions();
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Find start\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Finding leaf node that contains/should contain %d...\n", key);
    return find(key, root);
}

/*
BPlusTreeNode* BStarTree::find(int key, BPlusTreeNode* currentNode)

Recursively finds the node that contains the given key and returns a pointer to that node.
*/
BPlusTreeNode* BStarTree::find(int key, BPlusTreeNode* currentNode) {
    if(!(currentNode->getIsLeaf())) {
        for(int i = 0; i <= (int)(currentNode->getKeys()->size()); i++) {
            if(i >= (int)(currentNode->getKeys()->size())) {
                snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Traverse to child #%d...\n", i + 1);
                return find(key, (*(currentNode->getChildren()))[(unsigned long int)i]);
            }
            if(key < (*(currentNode->getKeys()))[(unsigned long int)i]) {
                snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Traverse to child #%d...\n", i + 1);
                return find(key, (*(currentNode->getChildren()))[(unsigned long int)i]);
            }
        }
    }

    return currentNode;
}

// Modifiers
/*
int BStarTree::insert(int key)

Finds the correct place to insert the given key recursively. Once the key has been inserted
nodes may be split/values shared to maintain the BPlusTree properties.
*/
int BStarTree::insert(int key) {
    clearInstructions();

    // Finds the correct node to insert the key into recursively
    BPlusTreeNode* currentNode = find(key);
    
    // Adds the key to the node
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Insert Start\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Add key %d to the found node.\n", key);
    currentNode->addKey(key);

    // If the key is inserted without exceeding the max length for keys, return to finish.
    if(currentNode->getKeysLength() < maxKeysLeaf) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The size of the node is %d, which isn't larger than k=%d, so nothing else is done.\n", currentNode->getKeysLength(), maxKeysLeaf);
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Insert Done\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n\n");
        return 1;
    }

    // Since the current node is out of room, try to give the lowest value to the node's left neighbor.
    // If unable to give to the left neighbor, try to give the largest value to the node's right neighbor.
    // If all that fails, split the current node. After the split, check ensure the parent doesn't need split.
    // If the parent needs split, repeat the process above until all nodes aren't full.
    if(currentNode->getLeftNeighbor() && currentNode->getLeftNeighbor()->getKeysLength() + 1 < maxKeysLeaf) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's size is now larger than or equal to k=%d\n", maxKeysLeaf);
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's left neighbor has room enough room for another value so give the current node's lowest key to the left neighbor.\n\n");
        currentNode->giveLeft();
    } else if(currentNode->getRightNeighbor() && currentNode->getRightNeighbor()->getKeysLength() + 1 < maxKeysLeaf) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's size is now larger than or equal to k=%d\n", maxKeysLeaf);
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's right neighbor has room enough room for another value so give the current node's highest key to the right neighbor.\n\n");
        currentNode->giveRight();
    } else {
        while(currentNode->getKeysLength() >= maxKeysLeaf) {
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's size is now larger than or equal to k=%d, therefore the node must be split.\n", maxKeysLeaf);
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Create a new node to the right of the current node.\n");
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Splitting current node's keys in half giving half to the newly created node on the right (if not an even split, the extra value is given to the right)\n");
            if(!currentNode->getIsLeaf()) {
                snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Current node is an internal node, therefore splitting children in half giving half to the newly created node on the right (if not an even split the extra child is given to the right)\n");
            }
            currentNode->splitNode();
            if(currentNode == root) {
                snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Current node that was just split was the current root. Create another new node to be the current node and the newly created node on the right's parent. Set this new parent node as the root of the tree.\n");
                root = currentNode->getParent();
            }
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Change current node to the current node's parent.\n");
            currentNode = currentNode->getParent();
        }
    }
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The size of the node is %d, which isn't larger than k=%d, so nothing else is done.\n", currentNode->getKeysLength(), maxKeysLeaf);
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Insert Done\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n\n");
    return 1;
}

/*
int BStarTree::remove(int key)

Removes the given key from the B* Tree. Returns the key if it is removed successfully.
On fail it returns -1.
*/
int BStarTree::remove(int key) {
    // Grabs the node that contains the value.
    BPlusTreeNode* currentNode = find(key);

    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Delete Start\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");

    // If key doesn't exist, can't remove key
    if(!currentNode || !(currentNode->keyExists(key))) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The key %d does not exist in the tree, therefore %d cannot be removed.\n", key, key);
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Delete Done\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
        return -1;
    }

    // Remove the key
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Remove %d from the current node.\n", key);
    int keyIndex = currentNode->removeKeyByValue(key);
    
    // A boolean variable that determines if the node has enough keys.
    bool okayKeyLength = currentNode->getKeysLength() > 0;

    /* If the removed value is the first value of a node AND the node has enough keys to avoid
    taking or merging with its neighbors, the removed key is replaced within the internal nodes. */
    if(keyIndex == 0 && okayKeyLength) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d was the first key in the current leaf node, therefore %d's reference in internal nodes must be replaced with the the new first key for the current node.\n", key);
        int replacementKey;
        if(okayKeyLength) {
            replacementKey = (*(currentNode->getKeys()))[0];
        } else if(currentNode->getLeftNeighbor() && currentNode->nodesShareParent(currentNode->getLeftNeighbor())) {
            replacementKey = (*(currentNode->getLeftNeighbor()->getKeys()))[currentNode->getLeftNeighbor()->getKeysLength() - 1];
        } else {
            replacementKey = (*(currentNode->getRightNeighbor()->getKeys()))[0];
        }
        currentNode->findAndReplaceKeyInAncestry(key, replacementKey);
    }
    // If the keys vector satisfies the minimum key length requirement, finish and return the key.
    if(okayKeyLength) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "After removing the key, the current node's size is larger than 0, so the deletion is finished.\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Delete Done\n");
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
        return key;
    }

    /* If the node doesn't have enough keys, try:
    1. Taking from left
    2. Taking from right
    3. Merging left
    4. Merging right 
    Change the current node to its parent and repeat steps until the current node has enough keys. */
    while(!okayKeyLength && currentNode != root) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The current node's size is less than 0. The node has 4 potential options: take left, take right, merge left, merge right\n");
        if(currentNode->getLeftNeighbor() && currentNode->nodesShareParent(currentNode->getLeftNeighbor()) && currentNode->getLeftNeighbor()->getKeysLength() - 1 > 0) {
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The node's left neighbor is greather than one, meaning the current node can take the highest key from it's left neighbor.\n");
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "After taking from the node's left neighbor, the node's old first key must be replaced within the internal node's with the new key.\n");
            currentNode->takeLeft();
        } else if(currentNode->getRightNeighbor() && currentNode->nodesShareParent(currentNode->getRightNeighbor()) && currentNode->getRightNeighbor()->getKeysLength() - 1 > 0) {
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The node's right neighbor is larger than one, meaning the current node can take the lowest key from it's right neighbor.\n");
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "After taking from the node's right neighbor, the right neighbors old lowest key must be replaced throughout the internal nodes with the right neighbor's new lowest key.\n");
            currentNode->takeRight();
            currentNode->findAndReplaceKeyInAncestry(key, (*(currentNode->getKeys()))[0]);
        } else if(currentNode->getLeftNeighbor() && currentNode->nodesShareParent(currentNode->getLeftNeighbor())) {
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Both the node's left and right neighbors are not greater than one, therefore it must be merged.\n");
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Merging left. Remove the given key from the parent and remove the node from the parent's children. Also update left and right neighbor's references as needed. Finally delete the current node.\n");
            currentNode->mergeLeft();
        } else {
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Both the node's left and right neighbors are not greater than one, therefore it must be merged.\n");
            snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Merging right. Remove the given key from the parent and remove the node from the parent's children. Also update left and right neighbor's references as needed. Finally delete the current node.\n");
            currentNode->findAndReplaceKeyInAncestry(key, (*(currentNode->getRightNeighbor()->getKeys()))[0]);
            currentNode->mergeRight();
        }
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Change current node to current node's parent.\n");
        currentNode = currentNode->getParent();
        okayKeyLength = currentNode->getKeysLength() > 0;
    }

    /* If after the while loop finishes, the current node is the root and the root only has one child, the child becomes the room and the old root is removed. */
    if(currentNode == root && root->getChildren()->size() == 1) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The root node only has one child, so that child becomes the new root and the old root is deleted.\n");
        BPlusTreeNode* oldRoot = root;
        root = (*(root->getChildren()))[0];
        if(root->getLeftNeighbor()) {
            root->setLeftNeighbor(nullptr);
        }
        if(root->getRightNeighbor()) {
            root->setRightNeighbor(nullptr);
        }
        root->setParent(nullptr);

        delete oldRoot;
    }

    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Delete Done\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    // Return the key.
    return key;
}

// Helpers
/*
void BStarTree::printNode(BPlusTreeNode* currentNode)

Prints the given node's keys with spaces between them.
*/
void BStarTree::printNode(BPlusTreeNode* currentNode) {
    currentNode->printKeys();
}

/*
void BStarTree::printTree() 

Prints the tree in a manner that attemps to show parent children relationships.
*/
void BStarTree::printTree() {
    queue<BPlusTreeNode*> queue;
    queue.push(root);
    int oldHeight = root->getHeight();
    BPlusTreeNode* oldParent = root->getParent();
    while(queue.size() > 0) {
        BPlusTreeNode* currentNode = queue.front();
        queue.pop();
        BPlusTreeNode* currentParent = currentNode->getParent();
        for(int i = 0; i < (int)(currentNode->getChildren()->size()); i++) {
            queue.push((*(currentNode->getChildren()))[(unsigned long int)i]);
        }
        if(currentParent != oldParent) {
            oldParent = currentParent;
            cout << "\t\t";
        }
        if(oldHeight > currentNode->getHeight()) {
            cout << endl;
            oldHeight = currentNode->getHeight();
        }
        printNode(currentNode);
    }
    cout << endl;
}

queue<BPlusTreeNode*> BStarTree::treeToQueue() {
    queue<BPlusTreeNode*> q;
    queue<BPlusTreeNode*> resultQueue;
    q.push(root);
    while(q.size() > 0) {
        BPlusTreeNode* currentNode = q.front();
        resultQueue.push(currentNode);
        q.pop();
        for(int i = 0; i < (int)(currentNode->getChildren()->size()); i++) {
            q.push((*(currentNode->getChildren()))[(unsigned long int)i]);
        }
    }
    return resultQueue;
}

void BStarTree::clearInstructions() {
    for(int i = 0; i < (sizeof(instructions) / sizeof(instructions[0])); i++) {
        instructions[i] = '\0';
    }
}
