//
// Created by amirziya on 9/28/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList {
public:
    Node *head = nullptr;
    void append(int);
    int getSize() const;
    void insertSorted(int);
    void insertAt(int, int);
    void deleteAt(int);
    void deleteElementAt(int) ;
    bool hasCycle() const;
    void reverseList();
    int getKthFromEnd(int) const;
    void print() const;
    void printMiddle() const;
    void removeDuplicates() const;
    void removeEven() ;
    LinkedList subsecribList(LinkedList other);
};



#endif //LINKEDLIST_H
