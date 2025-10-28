//
// Created by amirziya on 10/28/25.
//

#ifndef UNTITLED_QUEUESTACK_H
#define UNTITLED_QUEUESTACK_H
#include <stack>


class QueueStack {
    private:
    std::stack<int> s1;
    std::stack<int> s2;
    int front;
    public:
    void Enqueue(int);
    void Dequeue();
    int Peek();
    bool isEmpty();
};


#endif //UNTITLED_QUEUESTACK_H