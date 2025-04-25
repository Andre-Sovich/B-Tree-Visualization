#ifndef BTREENODE_H
#define BTREENODE_H

#include <vector>
#include <string>
using namespace std;


class BTreeNode {
    private:
    int _domain;
    bool _leaf;
    bool _root;
    bool _full;
    BTreeNode* _parent;
    vector<BTreeNode*> _children;
    vector<int> _keys;
    int _id;
    int _height;

    public:
    // Constructors
    BTreeNode();
    BTreeNode(int domain, bool leaf, bool root, int height);


    // Getters
    int getDomain();
    bool getLeaf();
    bool getRoot();
    bool getFull();
    int size();
    vector<int> getKeys();
    int getKeyAtIndex(int index);
    BTreeNode *getParent();
    BTreeNode *getChild(int index);
    vector<BTreeNode *> *getChildren();
    int numChildren();
    std::string getId();
    int getHeight();


    // Setters
    int setId(int i);
    int setLeaf();
    int setRoot();
    int insertKey(int key);
    int setParent(BTreeNode *parent);
    int addChild(BTreeNode *child, int index);
    int setHeight(int height);

    // Removers
    int removeRoot();
    int removeKey(int key);
    int removeLeaf();
    int removeParent();
    int removeChild(int index);

    // Info
    void printKeys();
    int findHeight();
    string toString();
    bool operator==(const BTreeNode &other);
    bool keyExists(int key);
};

#endif
