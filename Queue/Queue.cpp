//
// Created by amirziya on 10/28/25.
//

#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}


void Queue::Enqueue(int ele) {
    Node* newNode = new Node(ele);
    if (isEmpty()) {
        front = rear = newNode;
    }else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::Dequeue() {
    if (isEmpty()) {
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) {
        rear = nullptr;
    }
}

int Queue::peek() {
    if (isEmpty()) {
        return -1;
    }
    return front->data;
}
