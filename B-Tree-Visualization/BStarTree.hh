#ifndef BSTARTREE_HH
#define BSTARTREE_HH

#include "BPlusTreeNode.hh"
#include <cstring>
#include <queue>
class BStarTree {
    private:
    BPlusTreeNode* root;
    int maxKeysLeaf;
    char instructions[16384] = {};

    public:
    BStarTree(int maxKeys);

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
