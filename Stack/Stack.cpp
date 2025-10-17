//
// Created by amirziya on 10/13/25.
//

#include "Stack.h"
#include <cctype>
#include <math.h>
#include <vector>

#include "stack"

bool Stack::isEmpty() const {
    return  head == nullptr;
}

int Stack::peek() const {
    return head->data;
}

void Stack::push(const int ele) {
    if (head == nullptr) {
        head = new Node(ele);
        return;
    }
    Node *temp = head;
    head = new Node(ele);
    head->next = temp;
}


int Stack::pop() {
    if (head == nullptr) {
        return -1;
    }
    const int result = head->data;
    const Node *temp = head;
    head = head ->next;

    delete temp;

    return result;
}

// for Example  32 + 67 -*  is real world is like 3+2 - 6*7 but computer not understood how can to solve it
bool Stack::isPostFix(const string &exp) {
    stack<string> s;

    for (int i=0;i<exp.length();i++) {
        if (isdigit(exp[i])) {
            s.push(string(1,exp[i]));
        }else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            if (s.size() < 2) {
                return false;
            }
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            string result = "(" + op2 + exp[i] + op1 + ")";
            s.push(result);
        }
    }

    return s.size() == 1;

}

bool Stack::isBalanced(const string& exp) {
    stack<char> s;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }

           const char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
                }
        }
    }

    return s.empty();
}
// for example key is 1 and our stak is like this {1,2,3,1,5,6}
// temp is like this => {6,5,3,2}
// we should do this _stack => {2,3,5,6}
void Stack::removeByKey(const int key, stack<int> & _stack) {
    stack<int> temp;

    while (!_stack.empty()) {
        if (_stack.top() != key) {
            temp.push(_stack.top());
        }
        _stack.pop();
    }
    while (!temp.empty()) {
        _stack.push(temp.top());
        temp.pop();
    }
}

// exp = "abc" look for exp = "cba"
void Stack::reverse(string & exp) {
    stack<char> s;
    for (char ch : exp) {
        s.push(ch);
    }
    exp = "";
    while (!s.empty()) {
        exp += s.top();
        s.pop();
    }
}

bool Stack::isPalindrome(string & exp) {
    stack<char> s;
        const int n = exp.length();
    for (int i =0; i< n/2; i++) {
        s.push(exp[i]);
    }

    // length of string exp is odd or even
    const int start = n%2 == 0 ? n/2 : (n/2+1);

    for (int i = start; i < n; i++) {
        if (s.empty() || s.top() != exp[i]) {
            return false;
        }
        s.pop();
    }

    return s.empty();
}
