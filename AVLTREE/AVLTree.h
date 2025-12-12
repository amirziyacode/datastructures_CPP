//
// Created by amirziya on 12/11/25.
//

#ifndef UNTITLED_AVLTREE_H
#define UNTITLED_AVLTREE_H
#include "AVLNode.h"


class AVLTree {
    private:
    AVLNode* root;
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* leftRotate(AVLNode* node);
    AVLNode* rightRotate(AVLNode* node);
    AVLNode* insert(AVLNode* node,int key);
    public:
    void insert(int key);
};


#endif //UNTITLED_AVLTREE_H