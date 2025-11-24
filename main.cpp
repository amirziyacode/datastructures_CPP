

#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <vector>
#include <stack>
#include <math.h>
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
int findClosingIndex(string str, int opening_index)
{
    int starter = 0;
    int counter = 0;
    stack<char> st;

    // find open
    for (int  i = 0;i < str.length(); i++) {
        if (counter == opening_index) {
            starter = i;
            break;
        }
        if (str[i] == '(') {
            counter++;
        }
    }

    for (int i = starter; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push(str[i]);
        }
        else if (str[i] == ')') {
            if (!st.empty()) {
                st.pop();
            }else {
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

string infixToPostfix(string s) {
    stack<char> num;
    stack<char> op;
    string result ;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            num.push(s[i]);
        }else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op.push(s[i]);
        }
    }
    while (!num.empty() || !op.empty()) {
        result += op.top();
        op.pop();
        if (!num.empty()) {
            result += num.top();
            num.pop();
        }
        if (!num.empty()) {
            result += num.top();
            num.pop();
        }
    }


    reverse(result.begin(), result.end());

    return result;
}

//190 leetcode
int reverseBits(int n) {
    int bits[32] = {};
    int count = 0;
    int result = 0;
    int power = 31;

    while (n != 0) {
        bits[count] = n % 2;
        n /= 2;
        count++;
    }

    for (int i = 0;i < 32; i++) {
        result += bits[i] * pow(2,power);
        power--;
    }


    return result;
}



int main(){


    cout << reverseBits(43261596);

    return 0;

}
