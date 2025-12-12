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
    if (!node) {
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

AVLNode* AVLTree::insert(AVLNode* node,int key) {
    if (node == nullptr) {
        return new AVLNode(key);
    }
    if (key < node->value) {
        node->left = insert(node->left,key);
    }else if (key > node->value) {
        node->right = insert(node->right,key);
    }else {
        return node;
    }

    // update height
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->value) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->value) {
        return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && key > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

void AVLTree::insert(int key) {
    root = insert(root,key);
}
