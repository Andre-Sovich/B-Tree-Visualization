#ifndef BPLUSTREE_HH
#define BPLUSTREE_HH

#include  <queue>
#include <cstring>
#include "BPlusTreeNode.hh"
class BPlusTree {
    private:
    BPlusTreeNode* root;
    int maxKeysLeaf;
    char instructions[16384] = {};

    public:
    BPlusTree(int maxKeys);

    BPlusTreeNode* getRoot();
    char* getCurrentInstructions();

    // Search
    BPlusTreeNode* find(int key);
    BPlusTreeNode* find(int key, BPlusTreeNode* currentNode);

    // Modifiers
    int insert(int key);
    int remove(int key);

    // Helpers
    void printNode(BPlusTreeNode* currentNode);
    void printTree();

    queue<BPlusTreeNode*> treeToQueue();
    void clearInstructions();
};

#endif
