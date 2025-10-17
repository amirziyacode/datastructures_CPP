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
    Stack s;
    string temp = "level";

   if ( s.isPalindrome(temp)) {
       cout << "true" << endl;
   };


    return 0;

}
