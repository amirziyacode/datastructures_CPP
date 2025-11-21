//
// Created by amirziya on 10/5/25.
//

#include "CycleLinkedList.h"


void CycleLinkedList::append(int element) {
    Node *newNode = new Node(element);
    if (!head) {
        head = newNode;
        head -> next = head;
        return;
    }
    Node *temp = head;
    while (temp -> next != head) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = head;
}
int CycleLinkedList::getLength() const {
    if (!head) {
        return 0;
    }
    int count = 1;
    Node *curr = head;
    while (curr -> next != head) {
        curr = curr -> next;
        count++;
    }
    return count;
}

void CycleLinkedList::deleteFromBeginning() {
    if (!head) {
        return;
    }

    // with one Node
    if (head->next == head) {
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }

    Node *curr = head;
    while (curr -> next != head) {
        curr = curr -> next;
    }
    const Node *prev = head;
    head = head->next;
    curr->next = head;
    delete prev;
}

void CycleLinkedList::deleteByElement(const int element) {
    if (!head) {
        return;
    }
    if (head->data == element) {
        deleteFromBeginning();
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != head && curr->data != element) {
        prev = curr;
        curr = curr -> next;
    }

    if (curr->data == element) {
        prev -> next = curr -> next;
        delete curr;
    }
}

void CycleLinkedList::deleteFromEnd() {
    if (!head) {
        return;
    }
    if (head -> next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr -> next != head) {
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    delete curr;
}
