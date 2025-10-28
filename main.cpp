
#include <iostream>
#include <ostream>
#include <vector>
#include <stack>

#include "Stack/StackArray.h"

using namespace std;

int binarySearch(const vector<int>& numbers,int number) {

    int low = 0;
    int last = numbers.size()-1;

    while (low <= last) {
        int mid = low + (last - low) / 2;
        if (numbers[mid] == number) {
            return numbers[mid];
        }
        if (numbers[mid] < number) {
            low = mid - 1;
        }else {
            last = mid - 1;
        }
    }
    return -1;
}

void sortStack(stack<int>& _stack) {
    stack<int> tempStack;
    int temp = 0;

    while (!_stack.empty()) {
        temp = _stack.top();
        _stack.pop();
        while (!tempStack.empty() && tempStack.top() > temp) {
            _stack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        _stack.push(tempStack.top());
        tempStack.pop();
    }
}

void addToBottomStack(stack<int>& _stack,int x) {
    if (_stack.empty()) {
        _stack.push(x);
        return;
    }
    int top = _stack.top();
    _stack.pop();

    addToBottomStack(_stack,x);

    _stack.push(top);
}

void reversStack(stack<int>& _stack) {
    if (_stack.empty()) {
        return;
    }
    int temp = _stack.top();
    _stack.pop();

    reversStack(_stack);

    addToBottomStack(_stack,temp);
}

void insertInSortedOrder(stack<int>& _stack,int x) {
    if (_stack.empty() || _stack.top() <= x) {
        _stack.push(x);
        return;
    }
    int top = _stack.top();
    _stack.pop();

    insertInSortedOrder(_stack,x);

    _stack.push(top);
}

void sortStackRecursive(stack<int>& _stack) {
    if (_stack.empty()) {
        return;
    }

    int top = _stack.top();
    _stack.pop();

    sortStackRecursive(_stack);

    insertInSortedOrder(_stack,top);
}
int main() {
    StackArray s1;

    for (int i = 0; i < 51; i++) {
        s1.push(i);
    }


    return 0;

}
