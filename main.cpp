

#include <algorithm>
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

string reversePrefix(string word, char ch) {
    int id = -1;


    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ch) {
            id = i;
            break;
        }
    }

    if (id == -1) return word;

    reverse(word.begin(), word.begin() + id + 1);

    return word;


}
// problem 1700 leetcode
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> stu;
    queue<int> sand;
    int failedCycle = 0;
    for (int i:students) stu.push(i);
    for (int j:sandwiches) sand.push(j);


    while (!stu.empty() && failedCycle < stu.size()) {
        if (stu.front() == sand.front()) {
            stu.pop();
            sand.pop();
            failedCycle = 0;
        }else {
            stu.push(stu.front());
            stu.pop();
            failedCycle++;
        }
    }

    return  stu.size();


}

int main(){
    string reverse_prefix = reversePrefix("abbcd", 'b');

    cout << reverse_prefix;
    return 0;

}
