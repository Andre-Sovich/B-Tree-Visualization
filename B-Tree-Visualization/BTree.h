#pragma once
#include "BTreeNode.h"
#include <cstring>
#include <queue>
class BTree
{
private:
	BTreeNode* _root;
	int _domain;
	int _middle;
    char instructions[16384] = {};
public:
	BTree();
	BTree(int domain);
	char* getCurrentInstructions();
	void clearInsturctions();
	int splitRootNode();
	int splitNode(BTreeNode* node);
	int insert(int key);
	int remove(int key);
	int search(int key);
	BTreeNode* findDeepestOccurance(int key);
	int mergeNodes(BTreeNode* node);
	int mergeLeafNodes(BTreeNode* node);
	int getHeight();
	queue<BTreeNode*> treeToQueue();
	~BTree();
	string toString();
	void printNode(BTreeNode* node);
	void printTree();
};

