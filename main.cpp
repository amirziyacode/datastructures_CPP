

#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
#include <stack>

#include "BST/BST.h"
#include "BST/NodeTree.h"
#include "LinkedList/LinkedList.h"
#include "Stack/StackQueue.h"

using namespace std;

// algorithme
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

void reversQueueRecursive(queue<int>& _queue) {
    if (_queue.empty()) {
        return;
    }

    const int top = _queue.front();
    _queue.pop();

    reversQueueRecursive(_queue);

    _queue.push(top);
}

void traverseInOrder(NodeTree* root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->data << " ";
    traverseInOrder(root->right);
}

/// midSemester
int findClosingIndex(char *str, int opening_index)
{
    if (str == nullptr)
        return -1;

    int depth = 0;

    for (int i = opening_index; i < sizeof(str); i++) {
        if (str[i] == '(') {
            depth++;
        }else if (str[i] == ')') {
            depth--;
            if (depth == 0) {
                return i;
            }
        }
    }
    return -1;
}


int main(){
    LinkedList l1;
    l1.append(2);

    l1.removeEven();

    l1.print();
    return 0;

}
