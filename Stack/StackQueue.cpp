//
// Created by amirziya on 10/31/25.
//

#include "StackQueue.h"

#include <iostream>


void StackQueue::push(int x) {
    q1.push(x);
    top = x;
}


bool StackQueue::isEmpty() {
    return q1.empty() && q2.empty();
}

void StackQueue::pop() {
    if (isEmpty()) {
        return;
    }

    const int n = q1.size();

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i -1 ; j++) {
            q1.push(q1.front());
            q1.pop();
        }

        q2.push(q1.front());
        q1.pop();
    }


    q2.pop();
    top = q2.front();
}

int StackQueue::peek() {
    return top;
}


