//
// Created by amirziya on 12/11/25.
//

#include "AVLTree.h"

#include <algorithm>
using namespace std;
#include "AVLNode.h"

int AVLTree::height(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* node) {
    AVLNode* x = node->left;
    AVLNode* t2 = x->right;

    x->right = node;
    node->left = t2;

    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* node) {
    AVLNode* x = node->right;
    AVLNode* t2 = x->left;

    x->left = node;
    node->right = t2;

    node->height = max(height(x->left), height(x->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}