//
// Created by amirziya on 11/7/25.
//

#include "BST.h"

#include <stddef.h>

#include "../LinkedList/Node.h"

BST::BST() {
    root = nullptr;
}

void BST::insert(int data) {
    if (root == NULL) {
        root = new NodeTree(data);
        return;
    }

    NodeTree *current = root;
    while (true) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new NodeTree(data);
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == NULL) {
                current->right = new NodeTree(data);
                break;
            }
            current = current->right;
        }
    }

};

bool BST::search(const int data) {
    if (root == NULL) {
        return false;
    }
    if (data == root->data) {
        return true;
    }

    const NodeTree *current = root;
    while (current!=NULL) {
        if (data < current->data) {
            current = current->left;
            if (current != NULL && current->data == data) {
                return true;
            }
        }
        else {
            current = current->right;
            if (current != NULL && current->data == data) {
                return true;
            }
        }
    }

    return false;
}
