//
// Created by amirziya on 10/28/25.
//

#include "StackArray.h"

#include <array>

void StackArray::push(int ele) {
    if (isFull()) {
        return;
    }
    top ++;
    arr[top] = ele;
}
bool StackArray::isFull() {
    return  top == 50;
}

bool StackArray::isEmpty() {
    return top == -1;
}

void StackArray::pop() {
    if (isEmpty()) {
        return;
    }
    arr[top] = 0;
    --top;
}

int StackArray::peek() {
    return arr[top];
}
