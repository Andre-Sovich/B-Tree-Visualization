#include "BTree.h"
#include <queue>
#include <iostream>
using namespace std;
/*
* TODO:
* When initialized, Creates an empty BTreeNode that is the root
* When the root node is full, Split the node in the middle, create 2 new nodes, a left node and a new root node.
* When a leaf node is full, split the leaf node and push the middle to the parent.
* To insert, start from the root node and search for the correct node to insert into, then insert the key. extra steps if node is full
* To remove, start from the root and search for the correct node to remove a key from and remove the key if it exists. extra steps if the node becomes less than half full
* To search, compare the elements at each node then go to the corrisponding child.
*/

// consturctors
/*
BTree::BTree()

creates a defult B Tree with a domain of 3
*/
BTree::BTree() {
	_domain = 3;
	_middle = _domain / 2;
	_root = new BTreeNode(_domain, true, true, 0);
}

/*
BTree::BTree(int domain)

creates a B Tree with the specified domain.
*/
BTree::BTree(int domain) {
	_domain = domain;
	_middle = domain / 2 + 1;
	_root = new BTreeNode(_domain, true, true, 0);
}
/*
char* BTree::getCurrentInstructions()

returns the instructions for the given step
*/
char* BTree::getCurrentInstructions()
{
	return instructions;
}

void BTree::clearInsturctions()
{
	for (int i = 0; i < (sizeof(instructions) / sizeof(instructions[0])); i++) {
		instructions[i] = '\0';
	}
}

/*
int BTree::splitRootNode()

splits the root node in the B tree, assigning a new root
*/
int BTree::splitRootNode() {
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	BTreeNode* newRoot = new BTreeNode(_domain, true, true, _root->getHeight()+1);
	BTreeNode* rightChild = new BTreeNode(_domain, true, false, _root->getHeight());
	int key = 0;
	// if the root node is also a leaf node
	if (_root->getLeaf()) {
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The root node, which is also a leaf node is full and needs to be split.\n");
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "A new node is created as a right sibling, and a new node is created to become the new root.\n");
		while (_root->size() > _middle) {
			key = _root->getKeyAtIndex(_root->size() - 1);
			rightChild->insertKey(key);
			_root->removeKey(key);
		}

		key = _root->getKeyAtIndex(_root->size() - 1);
		newRoot->insertKey(key);
		_root->removeKey(key);
		// set the parent of the old rood and right child to the new root
		_root->setParent(newRoot);
		_root->removeRoot();
		rightChild->setParent(newRoot);
		newRoot->addChild(_root, 0);
		newRoot->addChild(rightChild, 1);
		_root = newRoot;
		//_root->findHeight();
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The old root node becomes the first child of the new root and the new node becomes the second child. \n");
		return 0;
	}
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The root node is full and needs to be split\n");
	// if the root node is not a leaf node
	BTreeNode* lastChild = _root->getChild(_root->size());
	BTreeNode* childToMove = NULL;
	_root->removeChild(_root->size());
	int index = 0;
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Splitting keys between the old root node and the new sibling.\n");
	while (_root->size() > _middle) {
		index = _root->size() - 1;
		key = _root->getKeyAtIndex(index);
		rightChild->insertKey(key);
		_root->removeKey(key);
		childToMove = _root->getChild(index);
		childToMove->setParent(rightChild);
		rightChild->addChild(childToMove, rightChild->size() -1);
		_root->removeChild(index);

	}
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Now that the keys have been split the children need to be moved between the nodes.\n");
	key = _root->getKeyAtIndex(_root->size() - 1);
	rightChild->addChild(lastChild, rightChild->size());
	lastChild->setParent(rightChild);
	newRoot->insertKey(key);
	_root->removeKey(key);
	_root->setParent(newRoot);
	_root->removeRoot();
	rightChild->setParent(newRoot);
	newRoot->addChild(_root, 0);
	newRoot->addChild(rightChild, 1);
	_root = newRoot;
	_root->findHeight();
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The old root node becomes the first child of the new root and the new node becomes the second child. \n");
	return 0;
}
/*
int BTree::splitNode(Node* node)

Splits the given node in the B Tree, pushing the middle key into the parent node.
Also recursively checks the parent to make sure that it doesn't need to be split.
*/
int BTree::splitNode(BTreeNode* node) {
	//static Node node = *nodeptr;
	//node = *nodeptr;
	if (node->getRoot()) { return this->splitRootNode(); }
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "A node is full and needs to be split. A new sivling is created to the right.\n");
	BTreeNode* parent = node->getParent();
	BTreeNode* rightChild = new BTreeNode(_domain, true, false, node->getHeight());
	int index = -1;
	int key = 0;
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The keys need to be evenly distrubuted between each of the nodes. \n");
	for (int i = 0; i < parent->numChildren(); i++)
	{	
		if (parent->getChild(i) == node) {
			index = i;
			break;
		}
		
	}
	parent->addChild(rightChild, index + 1);
	rightChild->setParent(parent);
	while (node->size() > _middle) {
		key = node->getKeyAtIndex(node->size()-1);
		node->removeKey(key);
		rightChild->insertKey(key);

	}
	key = node->getKeyAtIndex(node->size()-1);
	node->removeKey(key);
	parent->insertKey(key);
	rightChild->setParent(parent);
	if (!node->getLeaf()) {
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Now that the nodes are split, and keys moved. The children need to be moved between nodes.\n");
	}
	// this will split the child vectors into the until the nodes have the proper number of children
	BTreeNode* child;
	if (node->numChildren() > _middle) {
		while (node->numChildren() > _middle) {
			child = node->getChild(_middle);
			rightChild->addChild(child, rightChild->numChildren());
			child->setParent(rightChild);
			node->removeChild(_middle);
		}
	}

	if (parent->getFull()) { this->splitNode(parent); }
	return 0;
}
/*
int BTree::insert(int key)

Inserts a key into the B tree
*/
int BTree::insert(int key) {
	clearInsturctions();
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "inserting the key: %d into the tree. \n", key);
	BTreeNode node = *_root;
	BTreeNode* nodeptr= _root;
	int index = 0;
	while (!node.getLeaf()) {
		index = node.size();
		for (int i = 0; i < node.size(); i++) {

			if (key < node.getKeyAtIndex(i)) {
				index = i;
				break;
			}
		}
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Moving to child %d.\n", index + 1);
		nodeptr = node.getChild(index);
		node = *node.getChild(index);
	}
	BTreeNode& insNode = *nodeptr;
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Inserting the key: %d into the leaf node. \n", key);
	insNode.insertKey(key);
	if (insNode.getFull()) { this->splitNode(nodeptr); }
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	return 0;
}
/*
int BTree::remove(int key)

removes a key from the B tree
*/
int BTree::remove(int key) {
	clearInsturctions();
	
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Removing the deepest occurance of %d...\n", key);
	BTreeNode* node = this->findDeepestOccurance(key);
	if (node == nullptr) {
		return -1;
	}
	if (node->getLeaf()) {
		node->removeKey(key);
		// check if the leaf node meets the requirements (merge if necessary)
		if (node->size() < _middle and !node->getLeaf()) {
			this->mergeNodes(node);
		}
		else if (node->getRoot() && node->getLeaf()) { return 0; }
		else if (node->size() == 0 and node->getLeaf()) {
			this->mergeLeafNodes(node);

		}
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
		return 0;
	}
	int index;
	for (int i = 0; i < node->size(); i++) {
		if (node->getKeyAtIndex(i) == key) {
			index = i;
			break;
		}
	}
	while (!node->getLeaf()) {
		key = node->getKeyAtIndex(index);
		node->removeKey(key);
		key = node->getChild(index + 1)->getKeyAtIndex(0);
		node->insertKey(key);
		if (node->size() < _middle and !node->getLeaf()) {
			this->mergeNodes(node);
		}
		node = node->getChild(index + 1);
		index = 0;
	}
	node->removeKey(node->getKeyAtIndex(0));
	if (node->size() == 0 and node->getLeaf()) {
		this->mergeLeafNodes(node);
	}
}

/*
int BTree::search(int key)

Finds if a key in the B tree exists
*/
int BTree::search(int key)
{
	clearInsturctions();
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Finding node that contains/should contain %d...\n", key);
	BTreeNode* node = _root;
	BTreeNode* oldNode = node;
	while (!node->getLeaf()) {
		for (int i = 0; i < node->size(); i++) {
			if (node->getKeyAtIndex(i) == key) {
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The key, %d was found.\n", key);
				return key;
			}
			if (key < node->getKeyAtIndex(i)) {
				node = node->getChild(i);
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Moving to node %d.\n", i + 1);
				break;
			}
		}
		if (node == oldNode) {
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "Moving to node %d.\n", node->size()+1);
			node = node->getChild(node->size());
		}
		oldNode = node;
	}

	//searches the leaf node for the key
	for (int i = 0; i < node->size(); i++) {
		if (node->getKeyAtIndex(i) == key) {
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The key, %d was found.\n", key);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
			return key;
			break;
		}
	}
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The key, %d was not found.\n", key);
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	return -1;
}
/*
BTreeNode* BTree::findDeepestOccurance(int key)

returns the node of the deepest occurnace of a key or a null ptr
*/
BTreeNode* BTree::findDeepestOccurance(int key)
{
	vector<BTreeNode*> nodes;
	BTreeNode* node = _root;
	BTreeNode* oldNode = node;

	// search all nodes until the leaf node to find the key
	while (!node->getLeaf()) {
		for (int i = 0; i < node->size(); i++) {
			if (node->getKeyAtIndex(i) == key) {
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "a key has been found in a non leaf node, checking child %d for more keys \n", i + 1);
				nodes.push_back(node);
				node = node->getChild(i+1);
				break;
			}
			if (key < node->getKeyAtIndex(i)) {
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "moving to child %d.\n", i + 1);
				node = node->getChild(i);
				break;
			}
		}
		if (node == oldNode) {
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "moving to child %d.\n", node->size() + 1);
			node = node->getChild(node->size());
		}
		oldNode = node;
	}

	//searches the leaf node for the key
	for (int i = 0; i < node->size(); i++) {
		if (node->getKeyAtIndex(i) == key) {
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "the key: %d was found in a leaf node.\n", key);
			nodes.push_back(node);
			break;
		}
	}

	if (nodes.empty()) {
		return nullptr;
	}
	return nodes.back();
}
/*
pair<BTreeNode*, BTreeNode*> BTree::findSiblings(BTreeNode* node)
finds the siblings nodes ------ modulized this portion of code to divide code into smaller function to be used within merge nodes
*/
pair<BTreeNode*, BTreeNode*> BTree::findSiblings(BTreeNode* node) {
    BTreeNode* parent = node->getParent();
    if (!parent) return {nullptr, nullptr};
    int child_ndx = -1;
    for (int i = 0; i <= parent->size(); i++) {
        if (parent->getChild(i) == node) {
            child_ndx = i;
            break;
        }
    }
    BTreeNode* leftSibling = (child_ndx > 0) ? parent->getChild(child_ndx - 1) : nullptr;
    BTreeNode* rightSibling = (child_ndx < parent->numChildren() - 1) ? parent->getChild(child_ndx + 1) : nullptr;

    return {leftSibling, rightSibling};
}
/*
int BTree::mergeNodes(BTreeNode* node)
merges a given node in the B Tree with its sibling nodes ------ modulized this portion of the code below
*/
int BTree::mergeNodes(BTreeNode* node)
{
    bool func_called = false;
    if (node->getRoot() && node->size() == 0 && !node->getLeaf()) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "The root node is empty, and the child will become the new root.\n");
        BTreeNode* temp = node;
        _root = node->getChild(0);
        _root->setRoot();
        _root->removeParent();
        //delete temp;
        return 0;
    }
    else if (node->getLeaf()){
        mergeLeafNodes(node);
        return 0;
    }
    else if (node->getRoot()) {
        return 0;
    }
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "A internal node is under half size and needs to be merged with it's sibling.\n");
    // find the index of the child from the parent node
    BTreeNode* parent = node->getParent();
    int child_ndx = -1;
    for (int i = 0; i <= parent->size(); i++) {
        if (parent->getChild(i) == node) {
            child_ndx = i;
            break;
        }

    }

    //this section of code calls function to find the siblings was modified
    auto [leftSibling, rightSibling] = findSiblings(node);
    BTreeNode* targetSibling = nullptr;

    if (child_ndx == 0) {
        // merge with right sibling
        targetSibling = rightSibling;
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "Merging child 1 into child 2.\n");
    } else if (child_ndx == parent->numChildren() - 1) {
        // merge with left sibling
        targetSibling = leftSibling;
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "Merging child %d into child %d\n", child_ndx + 1, child_ndx);
    } else {
        // merge with greater sibling
        targetSibling = (leftSibling->size() > rightSibling->size()) ? rightSibling : leftSibling;
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "Merging child %d into child %d\n", child_ndx + 1, child_ndx + (targetSibling == rightSibling ? 2 : 0));
    }

    // merging occurs
    int key = parent->getKeyAtIndex((targetSibling == leftSibling) ? child_ndx - 1 : child_ndx);
    parent->removeKey(key);
    targetSibling->insertKey(key);

    while (node->size() > 0) {
        int index = (targetSibling == leftSibling) ? 0 : node->size() - 1;
        key = node->getKeyAtIndex(index);
        BTreeNode* childMoving = node->getChild(index + (targetSibling == leftSibling ? 0 : 1));
        childMoving->setParent(targetSibling);
        node->removeKey(key);
        node->removeChild(index + (targetSibling == leftSibling ? 0 : 1));
        targetSibling->insertKey(key);
        targetSibling->addChild(childMoving, (targetSibling == leftSibling) ? targetSibling->size() : 0);
    }

    BTreeNode* lastChild = node->getChild(0);
    lastChild->setParent(targetSibling);
    node->removeChild(0);
    targetSibling->addChild(lastChild, (targetSibling == leftSibling) ? targetSibling->size() : 0);

    parent->removeChild(child_ndx);

    if (targetSibling->getFull()) {
        this->splitNode(targetSibling);
        func_called = true;
    }
    if (parent->size() < _middle) {
        this->mergeNodes(parent);
        func_called = true;
    }

    if (!func_called) _root->findHeight();
    return 0;
}
/*
 int BTree::mergeLeafNodes
 
 this method will merge the given non root leaf node with another leaf node
*/
int BTree::mergeLeafNodes(BTreeNode* node)
{
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "A leaf node is under half size and needs to be merged with it's sibling\n");
	if (!node->getLeaf()) { return -1; }
	BTreeNode* parent = node->getParent();
	int child_ndx = -1;
	for (int i = 0; i <= parent->size(); i++) {
		if (parent->getChild(i) == node) {
			child_ndx = i;
			break;
		}
		
	}

    //this section of code is used to find the siblings

	BTreeNode* left_Sibiling = nullptr;
	BTreeNode* right_Sibiling = nullptr;
	if (child_ndx == 0 && parent->numChildren() > 1)
	{
		// this section will handle if the leaf node being merged is the leftmost child
		right_Sibiling = parent->getChild(1);
		int key = parent->getKeyAtIndex(child_ndx);
		parent->removeKey(key);
		right_Sibiling->insertKey(key);
		while (node->size() > 0) {
			key = node->getKeyAtIndex(node->size() - 1);
			node->removeKey(key);
			right_Sibiling->insertKey(key);
		}
		parent->removeChild(child_ndx);
		if (right_Sibiling->getFull()) { this->splitNode(right_Sibiling); }
		if (parent->size() < _middle) { this->mergeNodes(parent); }
	}
	else if(child_ndx == parent->numChildren() - 1) {
		// this section will handle if the leaf node being merged is the right most child
		left_Sibiling = parent->getChild(child_ndx - 1);
		int key = parent->getKeyAtIndex(child_ndx-1);
		parent->removeKey(key);
		left_Sibiling->insertKey(key);
		while (node->size() > 0) {
			key = node->getKeyAtIndex(0);
			node->removeKey(key);
			left_Sibiling->insertKey(key);
		}
		parent->removeChild(child_ndx);
		if (left_Sibiling->getFull()) { this->splitNode(left_Sibiling); }
		if (parent->size() < _middle) { this->mergeNodes(parent); }
	}
	else {
		// this block of code is untested
		left_Sibiling = parent->getChild(child_ndx - 1);
		right_Sibiling = parent->getChild(child_ndx + 1);
		if (left_Sibiling->size() > right_Sibiling->size()) {
			// merge to the right
			int key = parent->getKeyAtIndex(child_ndx);
			parent->removeKey(key);
			right_Sibiling->insertKey(key);
			while (node->size() > 0) {
				key = node->getKeyAtIndex(node->size() - 1);
				node->removeKey(key);
				right_Sibiling->insertKey(key);
			}
			parent->removeChild(child_ndx);
			if (right_Sibiling->getFull()) { this->splitNode(right_Sibiling); }
			if (parent->size() < _middle) { this->mergeNodes(parent); }
		}
		else {
			// merge to the left
			int key = parent->getKeyAtIndex(child_ndx - 1);
			parent->removeKey(key);
			left_Sibiling->insertKey(key);
			while (node->size() > 0) {
				key = node->getKeyAtIndex(0);
				node->removeKey(key);
				left_Sibiling->insertKey(key);
			}
			parent->removeChild(child_ndx);
			if (left_Sibiling->getFull()) { this->splitNode(left_Sibiling); }
			if (parent->size() < _middle) { this->mergeNodes(parent); }
		}
		
	}
	//delete node;
	return 0;
}
/*
 int BTree::getHeight()

 returns the height of the root node
*/
int BTree::getHeight()
{
	return _root->getHeight();
	
}

/*
queue<BTreeNode*> BTree::treeToQueue()

converts the given B Tree into a queue to be used for the GUI
*/
queue<BTreeNode*> BTree::treeToQueue()
{
	queue<BTreeNode*> q;
	queue<BTreeNode*> resultQueue;
	q.push(_root);
	while (q.size() > 0) {
		BTreeNode* currentNode = q.front();
		resultQueue.push(currentNode);
		q.pop();
		for (int i = 0; i < currentNode->numChildren(); i++) {
			q.push(currentNode->getChild(i));
		}
	}
	return resultQueue;
}

BTree::~BTree(){
}

/*
void BTree::printNode(Node* node)

prints the given node's keys
*/
void BTree::printNode(BTreeNode* node)
{
	node->printKeys();
}

/*
void BTree::printTree()

Prints a diagram of each node and all the values in the tree
*/
void BTree::printTree()
{
	queue<BTreeNode*> queue;
	_root->findHeight();
	queue.push(_root);
	int oldHeight = _root->getHeight();
	BTreeNode* oldParent = _root->getParent();
	for (int i = 0; i < oldHeight; i++) { std::cout << "\t";}
	while (queue.size() > 0) {
		BTreeNode* currentNode = queue.front();
		
		queue.pop();
		BTreeNode* currentParent = currentNode->getParent();
		for (int i = 0; i < currentNode->numChildren(); i++) {
			queue.push(currentNode->getChild(i));
		}
		if (currentParent != oldParent) {
			oldParent = currentParent;
				std::cout << "\t";
		}
		if (oldHeight > currentNode->getHeight()) {
			std::cout << endl;
			oldHeight = currentNode->getHeight();
			for (int i = 0; i < oldHeight; i++) { std::cout << "\t"; }
		}
		printNode(currentNode);
	}	
}
