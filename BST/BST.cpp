//
// Created by amirziya on 11/7/25.
//

#include "BST.h"

#include <climits>
#include <iostream>
#include <queue>
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
//    12
//  9    14
// 5  10    20
//  6
// 12 , 9,14,5,10,20,6

void BST::BFS() {
    std::queue<NodeTree*> q;
    q.push(root);
    while (!q.empty()) {
        NodeTree *temp = q.front();
        q.pop();
        std::cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

void BST::InorderTraversal() {
    inorderTraversal(root);
}
void BST::inorderTraversal(NodeTree *root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data;
    inorderTraversal(root->right);
}
int height(NodeTree *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}
int BST::minValue() {
    return BST::minValue(root);
}


int BST::minValue(NodeTree* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    const int left = minValue(root->left);
    const int right = minValue(root->right);

    return std::min(std::min(left,right) , root->data);
}

bool BST::equality(BST other) {
    return equality(root, other.root);
}

bool BST::equality(NodeTree *first,NodeTree *second) {
    if (first == nullptr && second == nullptr) {
        return true;
    }

    if (first != nullptr && second != nullptr) {
        return first->data == second->data && equality(first->left, second->left) && equality(first->right, second->right);
    }

    return false;

}
bool BST::isBST() {
    return isBST(root,INT_MIN,INT_MAX);
}


bool BST::isBST(NodeTree *root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }
    return isBST(root->left , min, root->data - 1) && isBST(root->right, root->data + 1, max);;
}
