//
// Created by amirziya on 11/7/25.
//

#ifndef UNTITLED_BST_H
#define UNTITLED_BST_H
#include "NodeTree.h"


class BST {
private:
    int minValue(NodeTree*);
    bool equality(NodeTree*,NodeTree*);
    bool isBST();
    public:
    NodeTree *root;
    BST();
    void insert(int);
    bool search(int);
    void BFS();
    void InorderTraversal();
    void inorderTraversal(NodeTree*);
    int height(NodeTree*);
    int minValue();
    bool equality(BST);
    bool isBST(NodeTree*,int,int);
};


#endif //UNTITLED_BST_H