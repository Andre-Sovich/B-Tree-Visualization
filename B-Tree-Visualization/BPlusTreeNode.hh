#ifndef BPLUSTREENODE_HH
#define BPLUSTREENODE_HH

#include <iostream>
#include <vector>

using namespace std;

class BPlusTreeNode {
    private:
    vector<int> keys;
    vector<BPlusTreeNode*> children;
    BPlusTreeNode* parent;
    BPlusTreeNode* leftNeighbor;
    BPlusTreeNode* rightNeighbor;
    bool isLeaf;
    int height;

    public:
    // Constructors
    BPlusTreeNode(int height = 0, bool leaf = true);


    // Getters
    vector<int>* getKeys();
    int getKeysLength();
    vector<BPlusTreeNode*>* getChildren();
    BPlusTreeNode* getParent();
    BPlusTreeNode* getLeftNeighbor();
    BPlusTreeNode* getRightNeighbor();
    bool getIsLeaf();
    int getHeight();


    // Setters
    void setIsLeaf(bool nowLeaf);
    void setParent(BPlusTreeNode* newParent);
    void setLeftNeighbor(BPlusTreeNode* newLeft);
    void setRightNeighbor(BPlusTreeNode* newRight);
    void setHeight(int newHeight);

    // Information
    int whatChildAmI();
    bool keyExists(int key);
    bool nodesShareParent(BPlusTreeNode* otherNode);

    // Adders
    void addKey(int key);
    void addChild(BPlusTreeNode* newChild);

    // Removers
    int removeKey(int index);
    int removeKeyByValue(int key);
    bool replaceKey(int keyToReplace, int newKey);
    BPlusTreeNode* removeChild(int index);


    // Modifiers
    // For Insertion
    bool giveLeft();
    bool giveRight();

    void splitChildren(BPlusTreeNode* nodeToGiveChildren);
    void splitKeys(BPlusTreeNode* nodeToGiveKeys);
    bool splitNode();

    // For Deletion
    bool findAndReplaceKeyInAncestry(int key, int newKey);
    bool findAndRemoveKeyInAncestry(int key);

    bool takeLeft();
    bool takeRight();
    void mergeChildren(BPlusTreeNode* nodeToMergeWith);
    void mergeKeys(BPlusTreeNode* nodeToMergeWith);
    BPlusTreeNode* mergeLeft();
    BPlusTreeNode* mergeRight();

    // Debugging Tools
    void printKeys();
    char* getKeysString();
};

#endif
