//
// Created by amirziya on 10/12/25.
//

#include "DoublyLinkedList.h"
using namespace std;
#include <iostream>

void DoublyLinkedList::append(const int ele) {
    if (!head) {
        head = new Node(ele);
        // head->prev = nullptr;
        head->next = nullptr;
        return;
    }
    Node *ptr = head;

    while (ptr->next) {
        ptr = ptr->next;
    }
    Node *newNode = new Node(ele);
    ptr->next = newNode;
    // newNode->prev = ptr;
    newNode->next = nullptr;
}

void DoublyLinkedList::print() const {
    const Node *ptr = head;
    cout << "{";
    while (ptr) {
        cout << ptr->data<< ",";
        ptr = ptr->next;
    }
    cout << "}" << endl;
}