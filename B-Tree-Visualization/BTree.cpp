#include "BTree.h"
#include <queue>
#include <iostream>
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
    for (int i = 0; i < int(sizeof(instructions) / sizeof(instructions[0])); i++) {
		instructions[i] = '\0';
	}
}

/*
int BTree::splitRootNode()


int BTree::splitNode(Node* node)

Splits the given node in the B Tree, pushing the middle key into the parent node.
Also recursively checks the parent to make sure that it doesn't need to be split.
*/
int BTree::splitNode(BTreeNode* node) {
	// Check if even or odd
	int midPoint = 0;
	// If even, get length / 2 - 1
    if(node->size() % 2 == 0){ midPoint = node->size() / 2 - 1;}
	// If odd, get length / 2
	else{ midPoint = node->size() / 2;}

	// Check if node has parent aka is root
    if(node->getParent() == NULL){
		// If not, create parent node
        BTreeNode * newParent = new BTreeNode(_domain,false,true,_root->getHeight()+1);
		// Set parent node
		node->setParent(newParent);
		node->setId(0);
		// Add Child Node
		newParent->addChild(node,0);
		// Update root
		_root = newParent;
		}
	// get node parent
	BTreeNode * parent = node->getParent();
	// get index of current node in parent
	int index = -1;
	for (int i = 0; i < parent->numChildren(); i++)
	{	
		if (parent->getChild(i) == node) {
			index = i;
			break;
		}		
    }

	if (index < 0) { return 1;}

    // Create new node to the right for all small keys with parent = this nodes parent
	BTreeNode * newSib = new BTreeNode(_domain,true,false,node->getHeight());
	parent->addChild(newSib,index + 1);
	newSib->setId(index + 1);
	newSib->setParent(parent);

	// Split children equally
	// get number of children
	int numChild = node->numChildren();
	// for each child from middle forward, add to new sibling
    if (numChild != 0){
        while(node->numChildren() > numChild / 2){
            int i = node->numChildren() - 1; // end of index
            BTreeNode * child = node->getChild(i);
            newSib->addChild(child, i - (numChild / 2));
            child->setId(i - (numChild / 2));
            child->setParent(newSib);
            node->removeChild(i);
        }
    }
	// for each entry middle to end, place into new node
	int midKey = node->getKeyAtIndex(midPoint);
    while (int(node->getKeys().size()) > midPoint + 1){
        int i = node->getKeys().size() - 1;
        int key = node->getKeyAtIndex(i);
		// add key to new right
		newSib->insertKey(key);
        node->removeKey(key);
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "%s*%s*%d.g", node->getId().c_str(), newSib->getId().c_str(), key); // move key from node to node
	}
	//add middle to parent
	parent->insertKey(midKey);
	// remove middle from node
	node->removeKey(midKey);
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
             "%s*%s*%d.g", node->getId().c_str(), parent->getId().c_str(), midKey); // move key from node to node

	// check if parent needs to split
	if (parent->getFull()){
		// split parent
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "%s*s", parent->getId().c_str()); // split node
		return this->splitNode(parent);
	}
	// return 0 if works
	return 0;
}
/*
int BTree::insert(int key)

Inserts a key into the B tree
*/
int BTree::insert(int key) {
	clearInsturctions();
    //Add insert call to tree
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d.k", key);
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
		nodeptr = node.getChild(index);
		node = *node.getChild(index);
	}
	BTreeNode& insNode = *nodeptr;
    snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
             "%s*%d.g", nodeptr->getId().c_str(), key); // move from temp to node
	insNode.insertKey(key);
    if (insNode.getFull()) {
        snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)),
                 "%s*s", nodeptr->getId().c_str()); // split node
        this->splitNode(nodeptr); }
	return 0;
}



/*
int BTree::remove(int key)

removes a key from the B tree
*/
int BTree::remove(int key) {
	clearInsturctions();
	
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
        return this->mergeLeafNodes(node);
	}
    return 0;
}

/*
int BTree::search(int key)

Finds if a key in the B tree exists
*/
int BTree::search(int key)
{
	clearInsturctions();
	snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "----------\n");
	BTreeNode* node = _root;
	BTreeNode* oldNode = node;
	while (!node->getLeaf()) {
		for (int i = 0; i < node->size(); i++) {
			if (node->getKeyAtIndex(i) == key) {
				return key;
			}
			if (key < node->getKeyAtIndex(i)) {
				node = node->getChild(i);
				break;
			}
		}
		if (node == oldNode) {
			node = node->getChild(node->size());
		}
		oldNode = node;
	}

	//searches the leaf node for the key
	for (int i = 0; i < node->size(); i++) {
		if (node->getKeyAtIndex(i) == key) {
			return key;
			break;
		}
	}
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
				nodes.push_back(node);
				node = node->getChild(i+1);
				break;
			}
			if (key < node->getKeyAtIndex(i)) {
				node = node->getChild(i);
				break;
			}
		}
		if (node == oldNode) {
			node = node->getChild(node->size());
		}
		oldNode = node;
	}

	//searches the leaf node for the key
	for (int i = 0; i < node->size(); i++) {
		if (node->getKeyAtIndex(i) == key) {
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
int BTree::mergeNodes(BTreeNode* node)

merges a given node in the B Tree with its sibling nodes
*/
int BTree::mergeNodes(BTreeNode* node)
{
	bool func_called = false;
	if (node->getRoot() && node->size() == 0 && !node->getLeaf()) {
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
	// find the index of the child from the parent node
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
	BTreeNode* child_Moving = nullptr;
	if (child_ndx == 0 && parent->numChildren() > 1)
	{
		// this section will handle if the node being merged is the leftmost child
		right_Sibiling = parent->getChild(1);
		int key = parent->getKeyAtIndex(child_ndx);
		parent->removeKey(key);
		right_Sibiling->insertKey(key);
        //snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d.%d*g",key, right_Sibiling->getId()); // move node
		while (node->size() > 0) {
			int index = node->size() - 1;
			key = node->getKeyAtIndex(index);
			child_Moving = node->getChild(index + 1);
			child_Moving->setParent(right_Sibiling);
			node->removeKey(key);
			node->removeChild(index + 1);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",index + 2); // delete node
			right_Sibiling->insertKey(key);
            //snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d.%d*g",key, right_Sibiling->getId()); // move node
			right_Sibiling->addChild(child_Moving, 0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
		}
		child_Moving = node->getChild(0);
		child_Moving->setParent(right_Sibiling);
		node->removeChild(0);
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
		right_Sibiling->addChild(child_Moving,0);
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
		parent->removeChild(child_ndx);
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
		if (right_Sibiling->getFull()) { this->splitNode(right_Sibiling); func_called = true; }
		if (parent->size() < _middle) { this->mergeNodes(parent); func_called = true; }
	}
	else if (child_ndx == parent->numChildren() - 1) {
		// this section will handle if the leaf node being merged is the right most child
		left_Sibiling = parent->getChild(child_ndx - 1);
		int key = parent->getKeyAtIndex(child_ndx - 1);
		parent->removeKey(key);
		left_Sibiling->insertKey(key);
		while (node->size() > 0) {
			key = node->getKeyAtIndex(0);
			child_Moving = node->getChild(0);
			child_Moving->setParent(left_Sibiling);
			node->removeKey(key);
			node->removeChild(0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
			left_Sibiling->insertKey(key);
			left_Sibiling->addChild(child_Moving, left_Sibiling->size());
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
		}
		child_Moving = node->getChild(0);
		child_Moving->setParent(left_Sibiling);
		node->removeChild(0);
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
		left_Sibiling->addChild(child_Moving, left_Sibiling->size());
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
		parent->removeChild(child_ndx);
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx+1); // delete node
		if (left_Sibiling->getFull()) { this->splitNode(left_Sibiling); func_called = true; }
		if (parent->size() < _middle) { this->mergeNodes(parent); func_called = true; }
	}
	else {
		left_Sibiling = parent->getChild(child_ndx - 1);
		right_Sibiling = parent->getChild(child_ndx + 1);
		if (left_Sibiling->size() > right_Sibiling->size()) {
			// merge to the right
			int key = parent->getKeyAtIndex(child_ndx);
			parent->removeKey(key);
			right_Sibiling->insertKey(key);
			while (node->size() > 0) {
				int index = node->size() - 1;
				key = node->getKeyAtIndex(index);
				child_Moving = node->getChild(index + 1);
				child_Moving->setParent(right_Sibiling);
				node->removeKey(key);
				node->removeChild(index + 1);
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",index + 2); // delete node
				right_Sibiling->insertKey(key);
				right_Sibiling->addChild(child_Moving, 0);
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
			}
			child_Moving = node->getChild(0);
			child_Moving->setParent(right_Sibiling);
			node->removeChild(0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
			right_Sibiling->addChild(child_Moving, 0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
			parent->removeChild(child_ndx);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
			if (right_Sibiling->getFull()) { this->splitNode(right_Sibiling); func_called = true; }
			if (parent->size() < _middle) { this->mergeNodes(parent); func_called = true; }
		}
		else {
			// merge to the left
			int key = parent->getKeyAtIndex(child_ndx - 1);
			parent->removeKey(key);
			left_Sibiling->insertKey(key);
			while (node->size() > 0) {
				key = node->getKeyAtIndex(0);
				child_Moving = node->getChild(0);
				child_Moving->setParent(left_Sibiling);
				node->removeKey(key);
				node->removeChild(0);
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
				left_Sibiling->insertKey(key);
				left_Sibiling->addChild(child_Moving, left_Sibiling->size());
				snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
			}
			child_Moving = node->getChild(0);
			child_Moving->setParent(left_Sibiling);
			node->removeChild(0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",1); // delete node
			left_Sibiling->addChild(child_Moving, 0);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "n"); // add child node
			parent->removeChild(child_ndx);
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
			if (left_Sibiling->getFull()) { this->splitNode(left_Sibiling); func_called = true; }
			if (parent->size() < _middle) { this->mergeNodes(parent); func_called = true; }
		}

	}
	//delete node;
	if (!func_called) {
		_root->findHeight();
	}
	return 0;

}


/*
 int BTree::mergeLeafNodes
 
 this method will merge the given non root leaf node with another leaf node
*/
int BTree::mergeLeafNodes(BTreeNode* node)
{
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
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
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
		snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
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
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
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
			snprintf(instructions + strlen(instructions), sizeof(instructions) - sizeof(strlen(instructions)), "%d*d",child_ndx + 1); // delete node
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
