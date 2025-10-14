//
// Created by amirziya on 10/13/25.
//

#ifndef STACK_H
#define STACK_H
#include "string"
#include "stack"
using  namespace std;
#include "../LinkedList/Node.h"


class Stack {
    private:
    Node *head = nullptr;
    public:
    bool isEmpty() const;
    int peek() const;
    int pop();
    void push(int);
    bool isPostFix(const string &) const;
    bool isBalanced(const string&)const;
    void removeByKey(int,stack<int>&);
};



#endif //STACK_H
