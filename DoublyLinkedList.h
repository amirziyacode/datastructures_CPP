//
// Created by amirziya on 10/12/25.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "LinkedList/Node.h"


class DoublyLinkedList {
private:
    Node *head;
    public:
    void append(int);
    void print() const;
};



#endif //DOUBLYLINKEDLIST_H
