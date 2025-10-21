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


    static bool isPostFix(const string &);

    static bool isBalanced(const string&);
    void removeByKey(int,stack<int>&);

    static void reverse(string&);

    static bool isPalindrome(string&);

    static void removeDublication(string&);

};



#endif //STACK_H
