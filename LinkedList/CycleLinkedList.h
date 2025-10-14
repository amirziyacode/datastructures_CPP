//
// Created by amirziya on 10/5/25.
//

#ifndef CYCLELINKEDLIST_H
#define CYCLELINKEDLIST_H
#include "Node.h"


class CycleLinkedList {
    private:
    Node *head = nullptr;
    public:
    void append(int);
    int getLength() const;
    void deleteFromBeginning();
    void deleteByElement(int);
    void deleteFromEnd();
};



#endif //CYCLELINKEDLIST_H
