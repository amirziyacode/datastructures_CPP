//
// Created by amirziya on 12/11/25.
//

#ifndef UNTITLED_AVLNODE_H
#define UNTITLED_AVLNODE_H


class AVLNode {
public:
    AVLNode* left;
    AVLNode* right;
    int height;
    int value;
    AVLNode(const int);
};


#endif //UNTITLED_AVLNODE_H