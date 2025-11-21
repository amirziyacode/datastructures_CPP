//
// Created by amirziya on 11/20/25.
//

#include "QueueArray.h"

bool QueueArray::isFull() {
    return count == capacity;
}
bool QueueArray::isEmpty() {
    return count == 0;
}

void QueueArray::enQueue(int ele) {
    if (isFull()) {
        return;
    }
    rear = rear % capacity;
    array[rear] = ele;
    rear ++;
    count ++;
}

int QueueArray::deQueue() {
    if (isEmpty()) {
        return -1;
    }
    front = front % capacity;
    const int temp = array[front];
    front ++;
    count --;
    return temp;
}