//
// Created by amirziya on 11/20/25.
//

#ifndef UNTITLED_QUEUEARRAY_H
#define UNTITLED_QUEUEARRAY_H


class QueueArray {
    private:
    int capacity = 50;
    int count = 0;
    int front = 0;
    int rear = 0;
    int array[50];
    public:
    bool isFull();
    bool isEmpty();
    void enQueue(int);
    int deQueue();
};

#endif //UNTITLED_QUEUEARRAY_H