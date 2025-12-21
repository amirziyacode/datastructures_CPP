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
        Queue/Queue.cpp
        Queue/Queue.h
        Queue/QueueStack.cpp
        Queue/QueueStack.h
        Stack/StackQueue.cpp
        Stack/StackQueue.h
        BST/NodeTree.cpp
        BST/NodeTree.h
        BST/BST.cpp
        BST/BST.h
        Queue/QueueArray.cpp
        Queue/QueueArray.h
        d.cpp
        AVLTREE/AVLNode.cpp
        AVLTREE/AVLNode.h
        AVLTREE/AVLTree.cpp
        AVLTREE/AVLTree.h
        Graph/Graph.cpp
        Graph/Graph.h
        Graph/Node.cpp
        Graph/Node.h
        Graph/GraphMatrix.cpp
        Graph/GraphMatrix.h
)
