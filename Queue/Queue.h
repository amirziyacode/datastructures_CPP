//
// Created by amirziya on 10/28/25.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H
#include "Node.h"


class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    void Enqueue(int ele);
    void Dequeue();
    int peek();
    bool isEmpty();
};


#endif //UNTITLED_QUEUE_H