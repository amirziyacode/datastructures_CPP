//
// Created by amirziya on 10/31/25.
//

#ifndef UNTITLED_STAKCQUEUE_H
#define UNTITLED_STAKCQUEUE_H
#include <queue>


class StackQueue {
private:
    std::queue<int> q1;
    std::queue<int> q2;
    int top = 0;
public:
    bool isEmpty();
    void push(int);
    void pop();
    int peek();

};


#endif //UNTITLED_STAKCQUEUE_H