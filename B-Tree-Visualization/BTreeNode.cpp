// B-tree-testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "BTreeNode.h"
#include <ctime>
#include <string>
using namespace std;
/*
class Node
{
public:
	Node(int domain, bool leaf, bool root);
	int getDomain();
	bool getLeaf();
	int setLeaf();
	int removeLeaf();
	bool getRoot();
	int setRoot();
	int removeRoot();
	int insertKey(int key);
	int removeKey(int key);
	vector<int> getKeys();
	~Node();

private:
	int _domain;
	bool _leaf;
	bool _root;
	bool _full;
	vector<int> _keys;
};
*/

// constructors
/*
BTreeNode::BTreeNode()

Default constructor for the B tree node, domain defaults to 3
*/
BTreeNode::BTreeNode()
{
	_domain = 3;
	_leaf = true;
	_root = true;
	_full = false;
	_parent = NULL;
	_children = vector<BTreeNode*>();
	_keys = vector<int>();
	time_t now = time(0);
	_id = static_cast<long long>(now);
	_height = NULL;
}
/*
BTreeNode::BTreeNode(int domain, bool leaf, bool root, int height)

consturctor for B tree node
*/
BTreeNode::BTreeNode(int domain, bool leaf, bool root, int height)
{
	_domain = domain;
	_leaf = leaf;
	_root = root;
	_height = height;
	_full = false;
	_parent = NULL;
	_children = vector<BTreeNode*>();
	_keys = vector<int>();
	time_t now = time(0);
	_id = static_cast<long long>(now);
}

// getters
/*
int BTreeNode::getDomain()

returns the domain of the node
*/
int BTreeNode::getDomain()
{
	return _domain;
}
/*
bool BTreeNode::getLeaf()

returns if the node is a leaf node or not
*/
bool BTreeNode::getLeaf()
{
	return _leaf;
}
/*
bool BTreeNode::getRoot()

returns if the node is a root node or not
*/
bool BTreeNode::getRoot()
{
	return _root;
}
/*
bool BTreeNode::getFull()

returns if the node is full or not
*/
bool BTreeNode::getFull()
{
	return _full;
}
/*
int BTreeNode::size()

returns the integer value of the number of keys in the node
*/
int BTreeNode::size()
{
	return _keys.size();
}
/*
vector<int> BTreeNode::getKeys()

returns the vector of keys
*/
vector<int> BTreeNode::getKeys() {
	return _keys;
}
/*
int BTreeNode::getKeyAtIndex(int index)

returns a integer value of a key at an index
*/
int BTreeNode::getKeyAtIndex(int index)
{
	if (index > _keys.size()-1 or index < 0) {
		return NULL;
	}
	return _keys[index];
}
/*
BTreeNode* BTreeNode::getChild(int index)

returns a pointer to the parent node
*/
BTreeNode* BTreeNode::getParent()
{
	if (_parent != NULL) {
		return _parent;
	}
    return NULL;
}
/*
BTreeNode* BTreeNode::getChild(int index)

returns a child at a specific index
*/
BTreeNode* BTreeNode::getChild(int index) {
	if (index <= _children.size() and index >= 0) {
		return _children[index];
	}	
}
/*
vector<BTreeNode*>* BTreeNode::GetChildren()

returns a vector containing the children nodes
*/
vector<BTreeNode*>* BTreeNode::getChildren()
{
	return &_children;
}
/*
int BTreeNode::numChildren()

returns the number of children in the child vector
*/
int BTreeNode::numChildren()
{
	return _children.size();
}
/*
int BTreeNode::getId()

returns the ID of the node (this function is depreciated)
*/
int BTreeNode::getId()
{
	return _id;
}
/*
int BTreeNode::getHeight()

Returns the hegiht of the node in the tree
*/
int BTreeNode::getHeight()
{
	return _height;
}
// setters
/*
int BTreeNode::setLeaf()

Sets the boolean value for the node being a leaf node
*/
int BTreeNode::setLeaf()
{
	if (_leaf)
	{
		return 1;
	}
	_leaf = true;
	return 0;
}
/*
int BTreeNode::setRoot()

Sets the boolean value for the node being a root node
*/
int BTreeNode::setRoot()
{
	if (_root) { return 1; } // already the root
	_root = true;
	return 0;
}
/*
int BTreeNode::insertKey(int key)

inserts the given key into the correct spot of the vector, sorted by value
*/
int BTreeNode::insertKey(int key)
{
	//if (_keys.size() >= _domain) { return 1; } // the node is already full
	for (int i = 0; i < _keys.size(); i++) {
		if (key <= _keys[i]) {
			_keys.insert(_keys.begin() + i, key);
			if (_keys.size() >= _domain) { _full = true; }
			return 0;
		}

	}
	_keys.push_back(key);
	if (_keys.size() >= _domain) { _full = true; }
	return 0;
}
/*
int BTreeNode::setParent(BTreeNode* parent)

sets the pointer to the parent node to the given value
*/
int BTreeNode::setParent(BTreeNode* parent) {
	_parent = parent;
	return 0;
}
/*
int BTreeNode::addChild(BTreeNode *child, int index)

inserts a child into the child vector at the given index
*/
int BTreeNode::addChild(BTreeNode *child, int index) {
	if (index < 0) { return 1; }
	if (index > _children.size()) { 
		_children.push_back(child);
		_leaf = false;
		return 0;
	}
	_children.insert(_children.begin() + index, child);
	_leaf = false;
	return 0;
}
/*
int BTreeNode::setHeight(int height)

sets the value of the height to the given integer
*/
int BTreeNode::setHeight(int height)
{
	_height = height;
	return 0;
}
// removers
/*
int BTreeNode::removeRoot()

Remove the boolean value for being a root node
*/
int BTreeNode::removeRoot()
{
	if (not _root) { return 1; } // already not the root
	_root = false;
	return 0;
}
/*
int BTreeNode::removeKey(int key)

Remove a key from the vector when it finds that value
*/
int BTreeNode::removeKey(int key)
{
	for (int i = 0; i < _keys.size(); i++) {
		if (key == _keys[i]) {
			_keys.erase(_keys.begin() + i);
			_full = false;
			return 0;
		}
	}
	return 1; // did not find the value to remove
}
/*
int BTreeNode::removeLeaf()

Removes the boolean value for being a leaf node
*/
int BTreeNode::removeLeaf()
{
	if (not _leaf)
	{
		return 1;
	}
	_leaf = false;
	return 0;
}
/*
int BTreeNode::removeParent()

removes the pointer to a parent node and sets it to a Null ptr
*/
int BTreeNode::removeParent() {
	_parent = NULL;
	return 0;
}
/*
int BTreeNode::removeChild(int index)

Removes a child from the child vector at a given index
*/
int BTreeNode::removeChild(int index) {
	_children.erase(_children.begin() + index);
	return 0;
}

// helpers
/*
void BTreeNode::printKeys()

Prints keys to the console
*/
void BTreeNode::printKeys()
{
	cout << "|";
	for (int i = 0; i < _keys.size(); i++) {
		cout << _keys[i] << " ";
	}
	cout << "|";
}
/*
BTreeNode::~BTreeNode()

deconstructor
*/
BTreeNode::~BTreeNode()
{
	/*
	_keys.~vector();
	while (_children.size() > 0) {
		_children.pop_back();
	}
	*/
}
/*
int BTreeNode::findHeight()

recursively finds the height of the node, finding the height of all the leaf nodes
*/
int BTreeNode::findHeight()
{
	//Note I know this is not efficent, this should only be used when printing to console
	if (_leaf == false) {
		for (int i = 0; i < _children.size(); i++)
		{
			_height = _children[i]->findHeight()+1;
		}
		return _height;
	}
	return 0;
}
/*
string BTreeNode::toString()

To string (Depreciated)
*/
string BTreeNode::toString()
{
	if (_leaf) {
		string ret = string();
		for (int i = 0; i < _keys.size(); i++) {
			ret.append(to_string(_keys[i]) + " ");
		}
		return ret;
	}
}
/*
bool BTreeNode::operator==(const BTreeNode& other)

comparison override (Depreciated)
*/
bool BTreeNode::operator==(const BTreeNode& other) {
	return _id == other._id;
}

bool BTreeNode::keyExists(int key) {
    for(int i = 0; i < (int)_keys.size(); i++) {
        if(_keys[(unsigned long int)i] == key) {
            return true;
        }
    }
    return false;
}
/*
int main()
{
	Node root(3, true, true);
	cout << "The domain is: " << root.getDomain() << "\n";
	root.insertKey(1);
	root.insertKey(2);
	root.removeKey(3);
	root.removeKey(1);
	root.insertKey(1);
	root.insertKey(3);
	root.insertKey(4);
	vector<int> temp = root.getKeys();
	cout << "data: ";
	for (int element : temp) {
		cout << element << " ";
	}
}
*/
