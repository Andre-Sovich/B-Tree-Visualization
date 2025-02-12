#pragma once
#ifndef Node_H
#define Node_H
#include <vector>
#include <string>
using namespace std;
class BTreeNode {
private:
	long long _id;
	int _domain;
	bool _leaf;
	bool _root;
	bool _full;
	vector<int> _keys;
	vector<BTreeNode*> _children;
	BTreeNode* _parent;
	int _height;
public:
	BTreeNode();
	BTreeNode(int domain, bool leaf, bool root, int height);
	int getDomain();
	bool getLeaf();
	int setLeaf();
	int removeLeaf();
	bool getRoot();
	int setRoot();
	int removeRoot();
	bool getFull();
	int insertKey(int key);
	int removeKey(int key);
	vector<int> getKeys();
	int getKeyAtIndex(int index);
	int size();
	int setParent(BTreeNode* parent);
	int removeParent();
	BTreeNode* getParent();
	int addChild(BTreeNode* child, int index);
	int removeChild(int index);
	BTreeNode* getChild(int index);
    vector<BTreeNode*>* getChildren();
	int numChildren();
	int getId();
	void printKeys();
	~BTreeNode();
	int getHeight();
	int setHeight(int height);
	int findHeight();
	string toString();
    bool keyExists(int key);
	bool operator==(const BTreeNode& other);


};
#endif // !Node


