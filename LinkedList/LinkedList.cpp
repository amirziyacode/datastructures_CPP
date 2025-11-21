//
// Created by amirziya on 9/28/25.
//

#include "LinkedList.h"

#include <iostream>

#include "vector"
using namespace std;
#include <stdexcept>

void LinkedList::append(int  ele) {
    if (head == nullptr) {
        head = new Node(ele);
        return;
    }
    Node *ptr = head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = new Node(ele);
}

int LinkedList::getSize() const {
    int count = 0;
    Node *ptr = head;
    while (ptr) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void LinkedList::insertSorted(int ele) {
    if (head) {
        head = new Node(ele);
        return;
    }
    Node *ptr = head;
    Node *prev = nullptr;

    while (ptr != nullptr && ele > ptr->data) {
        prev = ptr;
        ptr = ptr->next;
    }

    Node *newNode = new Node(ele);

    // first node of linked list
    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    }else {
        prev->next = newNode;
        newNode->next = ptr;
    }
}

void LinkedList::insertAt(int pos, int ele) {
    if (pos<0 || pos>getSize()) {
        return;
    }
    Node *newNode = new Node(ele);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    }

    Node* ptr = head;
    int counter = 0;

    while (counter < pos -1) {
        ptr = ptr->next;
        counter++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}


void LinkedList::deleteAt(int pos) {
    if ( pos < 0 || pos >= getSize()) {
        return;
    }
    if (getSize() == 1) {
        const Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *ptr = head;
    Node *prev = nullptr;
    int counter = 0;

    while (counter < pos) {
        prev = ptr;
        ptr = ptr->next;
        counter++;
    }
    prev->next = ptr->next;
    delete ptr;
}

void LinkedList::deleteElementAt(int ele) {

    if (head==nullptr) {
        throw std::out_of_range("LinkedList::deleteElementAt");
    }

    if (head-> data == ele) {
        const Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *ptr = head;
    Node *prev = nullptr;

    while (ptr != nullptr && ptr->data != ele) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == nullptr) {
        throw std::out_of_range("LinkedList::deleteElementAt: element not found");
    }

    prev->next = ptr->next;

    delete ptr;

}
bool LinkedList::hasCycle() const {

    const Node *slow = head;
    const Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast) {
        return true;
    }
    return false;
}

void LinkedList::reverseList() {
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList::print() const {
    const Node *ptr = head;
    cout << "{";
    while (ptr) {
        cout << ptr->data<< ",";
        ptr = ptr->next;
    }
    cout << "}" << endl;

}

int LinkedList::getKthFromEnd(int kth) const {
    Node *slow = head;
    Node *fast = head;

    for (int i=0;i<kth;i++) {
        fast = fast->next;
    }
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}


// for moment our lists not sorted and duplicate element not excite
LinkedList LinkedList::subsecribList(const LinkedList other) {
    LinkedList result;
    if (!head || !other.head) {
        return result;
    }

    for (const Node *ptr = head; ptr;ptr = ptr->next ) {
        for (const Node *ptr2 =  other.head; ptr2; ptr2 = ptr2->next) {
            if (ptr->data  ==  ptr2->data) {
                result.append(ptr->data);
                break;
            }
        }
    }
    return result;
}

// only for sorted LinkList
void LinkedList::removeDuplicates() const {
    Node *ptr = head;
    const Node  *temp=nullptr;
    if (!head) {
        return;
    }
    while (ptr->next) {
        if (ptr->data == ptr->next->data) {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }else {
            ptr = ptr->next;
        }
    }
}


void LinkedList::printMiddle() const {
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && slow != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next == nullptr) {
        cout << slow->data << " ";
    }else {
        cout << slow->next->data << " ";
    }
}

void LinkedList::removeEven() {
    if (!head) {
        return;
    }
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr) {
        if (head->data % 2 == 0) {
            head = head->next;
            delete curr;
            curr = head;
        }else if (curr -> data % 2 == 0) {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }else {
            prev = curr;
            curr = curr->next;
        }

    }
}
