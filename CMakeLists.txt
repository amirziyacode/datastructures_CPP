cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        LinkedList/Node.cpp
        LinkedList/Node.h
        LinkedList/CycleLinkedList.cpp
        LinkedList/CycleLinkedList.h
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Stack/Stack.cpp
        Stack/Stack.h
        Stack/StackArray.cpp
        Stack/StackArray.h
)
