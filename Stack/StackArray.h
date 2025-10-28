//
// Created by amirziya on 10/28/25.
//

#ifndef UNTITLED_STACKARRAY_H
#define UNTITLED_STACKARRAY_H


class StackArray {
    private:
    int arr[50];
    int size = 50;
    int top = -1;
    public:
    void push(int ele);
    void pop();
    bool isEmpty();
    bool isFull();
    int peek();
};


#endif //UNTITLED_STACKARRAY_H