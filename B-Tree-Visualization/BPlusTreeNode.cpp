#include "BPlusTreeNode.hh"

// Constructors
/*
BPlusTreeNode::BPlusTreeNode(int newHeight, bool leaf)

Creates a new node to be used within a B+ Tree and its variants.
*/
BPlusTreeNode::BPlusTreeNode(int newHeight, bool leaf) {
    parent = nullptr;
    leftNeighbor = nullptr;
    rightNeighbor = nullptr;
    isLeaf = leaf;
    height = newHeight;
}


// Getters
/*
vector<int>* BPlusTreeNode::getKeys()

Returns a pointer to the node's keys vector
*/
vector<int>* BPlusTreeNode::getKeys() {
    return &keys;
}

/*
int BPlusTreeNode::getKeysLength()

Returns the length of the keys vector.
*/
int BPlusTreeNode::getKeysLength() {
    return (int)keys.size();
}

/*
vector<BPlusTree*>* BPlusTreeNode::getChildren()

Returns a pointer to the node's children vector
*/
vector<BPlusTreeNode*>* BPlusTreeNode::getChildren() {
    return &children;
}

/*
BPlusTreeNode* BPlusTreeNode::getParent()

Returns a pointer to the parent of the current node
*/
BPlusTreeNode* BPlusTreeNode::getParent() {
    return parent;
}

/*
BPlusTreeNode* BPlusTreeNode::getLeftNeighbor()

Returns a pointer to the left neighbor of the current node.
*/
BPlusTreeNode* BPlusTreeNode::getLeftNeighbor() {
    return leftNeighbor;
}

/*
BPlusTreeNode* BPlusTreeNode::getRightNeighbor()

Returns a pointer to the right neighbor of the current node.
*/
BPlusTreeNode* BPlusTreeNode::getRightNeighbor() {
    return rightNeighbor;
}

/*
bool BPlusTreeNode::getIsLeaf()

Return true if the node is a leaf node, and false otherwise.
*/
bool BPlusTreeNode::getIsLeaf() {
    return isLeaf;
}

/*
int BPlusTreeNode::getHeight()

Returns the height of the current node. Leaf nodes are 0 height, the root is the highest node in the tree.
*/
int BPlusTreeNode::getHeight() {
    return height;
}


// Setters
/*
void BPlusTreeNode::setIsLeaf(bool nowLeaf)

Sets the isLeaf attribute to the given value for the current node.
*/
void BPlusTreeNode::setIsLeaf(bool nowLeaf) {
    isLeaf = nowLeaf;
}

/*
void BPlusTreeNode::setParent(BPlusTreeNode* newParent)

Sets the parent for the current node to the given parent pointer.
*/
void BPlusTreeNode::setParent(BPlusTreeNode* newParent) {
    parent = newParent;
}

/*
void BPlusTreeNode::setLeftNeighbor(BPlusTreeNode* newLeft)

Sets the left neighbor for the current node to the given node pointer.
*/
void BPlusTreeNode::setLeftNeighbor(BPlusTreeNode* newLeft) {
    leftNeighbor = newLeft;
}

/*
void BPlusTreeNode::setRightNeighbor(BPlusTreeNode* newRight)

Sets the right neighbor for the current node to the given node pointer.
*/
void BPlusTreeNode::setRightNeighbor(BPlusTreeNode* newRight) {
    rightNeighbor = newRight;
}

/*
void BPlusTreeNode::setHeight(int newHeight)

Sets the height of the node to the new given height.
*/
void BPlusTreeNode::setHeight(int newHeight) {
    height = newHeight;
}

/*
int BPlusTreeNode::whatChildAmI()

Returns the indexed position of the current node in parent's child vector.
*/
int BPlusTreeNode::whatChildAmI() {
    if(!parent) {
        return -1;
    }

    for(int i = 0; i < (int)(parent->getChildren()->size()); i++) {
        if((*(parent->getChildren()))[(unsigned long int)i] == this) {
            return i;
        }
    }
    return -1;
}

/*
bool BPlusTreeNode::keyExists(int key)

Returns the boolean value true if the given key is found within the node's keys vector. Returns false otherwise.
*/
bool BPlusTreeNode::keyExists(int key) {
    for(int i = 0; i < (int)keys.size(); i++) {
        if(keys[(unsigned long int)i] == key) {
            return true;
        }
    }
    return false;
}

/*
bool BPlusTreeNode::nodesShareParent(BPlusTreeNode* otherNode)

Returns true if the given node shares a parent with this node. Returns false otherwise.
*/
bool BPlusTreeNode::nodesShareParent(BPlusTreeNode* otherNode) {
    if(otherNode->getParent() == parent) {
        return true;
    }
    return false;
}

// Adders
/*
void BPlusTreeNode::addKey(int key)

Adds the given key to the node's keys vector in the correct position to maintain ascending order.
*/
void BPlusTreeNode::addKey(int key) {
    // If there are no keys, simply add the key to the vector.
    if(keys.size() < 1) {
        keys.push_back(key);
        return;
    }

    for(int i = 0; i <= (int)keys.size(); i++) {
        /* If iteration ends and the element still hasn't been inserted,
        insert it at the back as it must be the biggest element in the vector. */
        if(i >= (int)keys.size()) {
            keys.push_back(key);
            return;
        }

        /* If the key to be inserted is less than the current element,
        insert the key at the current position. */
        if(key <= keys[(unsigned long int)i]) {
            keys.insert(keys.begin() + i, key);
            return;
        }
    }
}

/*
void BPlusTreeNode::addChild(BPlusTreeNode* newChild)

Adds the given node to the current node's children vector. This function maintains properties
so that the children are in the correct order for searching and finding.
*/
void BPlusTreeNode::addChild(BPlusTreeNode* newChild) {
    // If there isn't any children, simply add the child to the vector.
    if(children.size() < 1) {
        children.push_back(newChild);
        return;
    }

    for(int i = 0; i <= (int)children.size(); i++) {
        // If the end of the vector is hit without inserting, simply add to the back of the vector.
        if(i >= (int)children.size()) {
            children.push_back(newChild);
            return;
        }
        // Compare the child we're adding's first key to every other child's first key.
        // Once the index is found on where to insert the child, slot it in.
        if((*(children[(unsigned long int)i]->getKeys()))[0] > (*(newChild->getKeys()))[0]) {
            children.insert(children.begin() + i, newChild);
            return;
        }
    }
}


// Removers
/*
int BPlusTreeNode::removeKey(int index)

Removes the key at the given index from the keys vector and returns the removed key.
If the given index is not within the vector bounds an error message is displayed.
*/
int BPlusTreeNode::removeKey(int index) {
    // If the given index is not valid, print an error.
    if(index < 0 || index >= (int)keys.size()) {
        cout << "ERROR: Invalid index given, unable to remove the key from the vector." << endl;
        return -1;
    }

    // Save the element before removing it. After removing the element return the removed value.
    int removedElement = keys[(unsigned long int)index];
    keys.erase(keys.begin() + index);
    return removedElement;
}

/*
int BPlusTreeNode::removeKeyByValue(int key)

Removes the key of the given value from the current node's keys vector, returning the key.
If the given key is not within the vector, returns -1.
*/
int BPlusTreeNode::removeKeyByValue(int key) {
    if(!keyExists(key)) {
        cout << "ERROR: Key does not existsin the given node." << endl;
        return -1;
    }

    for(int i = 0; i < (int)keys.size(); i++) {
        if(keys[(unsigned long)i] == key) {
            keys.erase(keys.begin() + i);
            return i;
        }
    }
    return -1;
}

/*
bool BPlusTreeNode::replaceKey(int keyToReplace, int newKey)

Finds the given key in the current nodes keys vector. If it successfully finds it, it will replace the key with the newKey
and return true. Otherwise it returns false.
*/
bool BPlusTreeNode::replaceKey(int keyToReplace, int newKey) {
    for(int i = 0; i < (int)keys.size(); i++) {
        if(keys[(unsigned long int)i] == keyToReplace) {
            keys[(unsigned long int)i] = newKey;
            return true;
        }
    }
    return false;
}


/*
BPlusTreeNode* BPlusTreeNode::removeChild(int index)

Removes the child at the given index. If this is successful it returns the removed child.
If it fails it returns an nullptr.
*/
BPlusTreeNode* BPlusTreeNode::removeChild(int index) {
    if(index < 0 || index >= (int)children.size()) {
        cout << "ERROR: Invalid index given, unable to remove the child from the vector." << endl;
        return nullptr;
    }

    BPlusTreeNode* removedChild = children[(unsigned long int)index];
    children.erase(children.begin() + index);
    return removedChild;
}


// Modifiers
// For Insertion
/*
bool BPlusTreeNode::giveLeft()

Gives the smallest key of the current node to its left neighbor. This also updates any references in the parent as needed.
If the current node doesn't have a left neighbor, this function returns false.
*/
bool BPlusTreeNode::giveLeft() {
    if(!leftNeighbor) {
        return false;
    }

    int keyToGive = removeKey(0);
    leftNeighbor->addKey(keyToGive);

    parent->replaceKey(keyToGive, keys[0]);
    return true;
}


/*
BPlusTreeNode::giveRight()

Gives the largest key of the current node to its right neighbor. This also updates the parent references as needed.
If the current node doesn't have a right neighbor, this function returns false.
*/
bool BPlusTreeNode::giveRight() {
    if(!rightNeighbor) {
        return false;
    }

    int keyToGive = removeKey(((int)keys.size()) - 1);
    int keyToReplace = (*(rightNeighbor->getKeys()))[0];
    rightNeighbor->addKey(keyToGive);

    rightNeighbor->getParent()->replaceKey(keyToReplace, keyToGive);
    return true;
}


/*
void BPlusTreeNode::splitChildren(BPlusTreeNode* nodeToGiveChildren)

Splits the current node's children at the median, giving the children to the right of the median to nodeToGiveChildren.
If there is an uneven number of children, the extra child is given to nodeToGiveChildren.
*/
void BPlusTreeNode::splitChildren(BPlusTreeNode* nodeToGiveChildren) {
    int childMedianIndex = (((int)children.size()) - 1) / 2;
    for(int i = ((int)children.size()) - 1; i > childMedianIndex; i--) {
        BPlusTreeNode* childToMove = removeChild(i);
        nodeToGiveChildren->addChild(childToMove);
        childToMove->setParent(nodeToGiveChildren);
    }
}


/*
void BPlusTreeNode::splitKeys(BPlusTreeNode* nodeToGiveKeys)

Splits the current node's keys at its median, giving the keys to the right of the median to nodeToGiveKeys.
If there is an uneven number of keys, the extra key is given to nodeToGiveKeys.
*/
void BPlusTreeNode::splitKeys(BPlusTreeNode* nodeToGiveKeys) {
    int medianIndex = (((int)keys.size()) - 1) / 2;
    if(keys.size() % 2 == 1) {
        medianIndex--;
    }
    for(int i = ((int)keys.size()) - 1; i > medianIndex; i--) {
        int keyToMove = removeKey(i);
        nodeToGiveKeys->addKey(keyToMove);
    }
}

/*
bool BPlusTreeNode::splitNode()

Splits a node at the median, creating a right neighbor and a parent in the process.
A boolean value is returned to determine if the function was successful in the split.
*/
bool BPlusTreeNode::splitNode() {
    // Create the new neighbor node.
    BPlusTreeNode* newNode = new BPlusTreeNode(height, isLeaf);

    // Split the current node's keys and give the split keys to the new node.
    // If the node is internal, also split the children and give the children to the new node.
    splitKeys(newNode);
    if(!isLeaf) {
        splitChildren(newNode);
    }

    // If there is no right neighbor for the current node, create a new neighbor and create a link between the two.
    // If a right neighbor does exist, insert the new node between the two nodes, creating links as needed.
    if(!rightNeighbor) {
        rightNeighbor = newNode;
        newNode->setLeftNeighbor(&*this);
    } else {
        BPlusTreeNode* oldNeighbor = rightNeighbor;
        rightNeighbor = newNode;
        newNode->setLeftNeighbor(&*this);
        newNode->setRightNeighbor(oldNeighbor);
        oldNeighbor->setLeftNeighbor(newNode);
    }

    // If there is no parent node, create the parent and create a link between the newly created parent and the current node.
    if(!parent) {
        parent = new BPlusTreeNode(height + 1, false);
        parent->addChild(&(*this));
    }
    // Create the link needed between the new node and the parent.
    parent->addChild(newNode);
    newNode->setParent(parent);
    
    // If the node is internal, remove the first key of the new node and give it to the parent.
    // If the node is external (a leaf node), give the parent the first key of new node, but does not remove it from the new node.
    if(!isLeaf) {
        parent->addKey(newNode->removeKey(0));
    } else {
        parent->addKey((*(newNode->getKeys()))[0]);
    }

    return true;
}

/*
bool BPlusTreeNode::findAndReplaceKeyInAncestry(int key, int newKey)

Finds and replaces the given key with the given new key from the parents ancestry.
This is done by traversing the current nodes parents until the key is found, at which point it replaces the key.
If the key isn't found returns false. Returns true on success.
*/
bool BPlusTreeNode::findAndReplaceKeyInAncestry(int key, int newKey) {
    BPlusTreeNode* currentNode = parent;
    while(currentNode) {
        if(currentNode->keyExists(key)) {
            currentNode->replaceKey(key, newKey);
            return true;
        }
        currentNode = currentNode->getParent();
    }
    return false;
}

/*
bool BPlusTreeNode::findAndRemoveKeyInAncestry(int key)

Finds and removes the given key with the given new key from the parents ancestry.
This is done by traversing the current nodes parents until the key is found, at which point it removes the key.
If the key isn't found returns false. Returns true on success.
*/
bool BPlusTreeNode::findAndRemoveKeyInAncestry(int key) {
    BPlusTreeNode* currentNode = parent;
    while(currentNode) {
        if(currentNode->keyExists(key)) {
            currentNode->removeKeyByValue(key);
            return true;
        }
        currentNode = currentNode->getParent();
    }
    return false;
}

/*
bool BPlusTreeNode::takeLeft()

Takes the last key from the node's left neighbor and adds it to itself.
If the node is an internal node it also takes the child related to the key.
Returns false on fail, and true on success.
*/
bool BPlusTreeNode::takeLeft() {
    if(!leftNeighbor || leftNeighbor->getKeysLength() <= 1) {
        return false;
    }

    if(isLeaf) {
        int keyToTake = leftNeighbor->removeKey(leftNeighbor->getKeysLength() - 1);
        int keyToReplace = keys[0];
        addKey(keyToTake);
        findAndReplaceKeyInAncestry(keyToReplace, keyToTake);
    } else {
        int keyToBubbleUp = leftNeighbor->removeKey(leftNeighbor->getKeysLength() - 1);
        int keyToBubbleDown = parent->removeKey(whatChildAmI() - 1);

        parent->addKey(keyToBubbleUp);
        addKey(keyToBubbleDown);

        BPlusTreeNode* newChild = leftNeighbor->removeChild((int)leftNeighbor->getChildren()->size() - 1);
        addChild(newChild);
        newChild->setParent(this);

    }

    return true;
}

/*
bool BPlusTreeNode::takeRight()

Takes the first key from the node's right neighbor and adds it to itself.
If the node is an internal node it also takes the child related to the key.
Returns false on fail, and true on success.
*/
bool BPlusTreeNode::takeRight() {
    if(!rightNeighbor || rightNeighbor->getKeysLength() <= 1) {
        return false;
    }

    if(isLeaf) {
        int keyToTake = rightNeighbor->removeKey(0);
        int replacementKey = (*(rightNeighbor->getKeys()))[0];
        rightNeighbor->findAndReplaceKeyInAncestry(keyToTake, replacementKey);
        addKey(keyToTake);
    } else {
        int keyToBubbleUp = rightNeighbor->removeKey(0);
        int keyToBubbleDown = parent->removeKey(whatChildAmI());

        parent->addKey(keyToBubbleUp);
        addKey(keyToBubbleDown);

        BPlusTreeNode* newChild = rightNeighbor->removeChild(0);
        addChild(newChild);
        newChild->setParent(this);
    }
    return true;
}

/*
void BPlusTreeNode::mergeChildren(BPlusTreeNode* nodeToMergeWith)

Merges the current node's children vector into the given node's children vector.
*/
void BPlusTreeNode::mergeChildren(BPlusTreeNode* nodeToMergeWith) {
    if(!nodeToMergeWith) {
        return;
    }

    while(children.size() > 0) {
        BPlusTreeNode* child = removeChild(0);
        nodeToMergeWith->addChild(child);
        child->setParent(nodeToMergeWith);
    }
}

/*
void BPlusTreeNode::mergeKeys(BPlusTreeNode* nodeToMergeWith)

Merges the current node's keys attribute into the given node's keys attribute.
*/
void BPlusTreeNode::mergeKeys(BPlusTreeNode* nodeToMergeWith) {
    if(!nodeToMergeWith) {
        return;
    }

    while(keys.size() > 0) {
        nodeToMergeWith->addKey(removeKey(0));
    }
}

/*
BPlusTreeNode* BPlusTreeNode::mergeLeft()

Merges the current node (keys and children) into its left neighbor.
Returns the parent of the current node, so the current node can be deleted afterwards.
*/
BPlusTreeNode* BPlusTreeNode::mergeLeft() {
    if(isLeaf) {
        parent->removeKey(whatChildAmI() - 1);
        parent->removeChild(whatChildAmI());
        leftNeighbor->setRightNeighbor(rightNeighbor);
        if(rightNeighbor) {
            rightNeighbor->setLeftNeighbor(leftNeighbor);
        }
    } else {
        int key = parent->removeKey(whatChildAmI() - 1);
        parent->removeChild(whatChildAmI());
        leftNeighbor->setRightNeighbor(rightNeighbor);
        leftNeighbor->addKey(key);
        mergeChildren(leftNeighbor);
        if(rightNeighbor) {
            rightNeighbor->setLeftNeighbor(leftNeighbor);
        }
    }
    return parent;
}

/*
BPlusTreeNode* BPlusTreeNode::mergeRight()

Merges the current node (keys and children) into its right neighbor.
Returns the parent of the current node, allowing the current node to be deleted after.
*/
BPlusTreeNode* BPlusTreeNode::mergeRight() {
    if(isLeaf) {
        parent->removeKey(whatChildAmI());
        parent->removeChild(whatChildAmI());
        rightNeighbor->setLeftNeighbor(leftNeighbor);
        if(leftNeighbor) {
            leftNeighbor->setRightNeighbor(rightNeighbor);
        }
    } else {
        int key = parent->removeKey(whatChildAmI());
        mergeChildren(rightNeighbor);
        parent->removeChild(whatChildAmI());
        rightNeighbor->addKey(key);
        rightNeighbor->setLeftNeighbor(leftNeighbor);
        if(leftNeighbor) {
            leftNeighbor->setRightNeighbor(leftNeighbor);
        }
    }
    return parent;
}
// Debugging Tools
/*
void BPlusTreeNode::printKeys()

Prints the keys of the current node with spaces between them.
*/
void BPlusTreeNode::printKeys() {
    for(int i = 0; i < (int)keys.size(); i++) {
        cout << keys[(unsigned long int)i] << " ";
    }
}
