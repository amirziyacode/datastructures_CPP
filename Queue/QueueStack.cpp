//
// Created by amirziya on 10/28/25.
//

#include "QueueStack.h"

void QueueStack::Enqueue(int item) {
    if (isEmpty()) {
        front = item;
    }
    s1.push(item);
}

void QueueStack::Dequeue() {
    if (isEmpty()) {
        return;
    }
    // revers s1
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    front = s2.top();
}

bool QueueStack::isEmpty() {
    return s1.empty() && s2.empty();
}

int QueueStack::Peek() {
    return front;
}