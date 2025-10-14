#include <iostream>
#include <vector>
#include  "Stack/Stack.h"
#include "LinkedList/CycleLinkedList.h"
#include "DoublyLinkedList.h"
#include "LinkedList/LinkedList.h"

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

int main() {
    Stack s1;
    stack<int> s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(1);
    s2.push(5);
    s2.push(6);

    s1.removeByKey(1,s2);


    return 0;

}
