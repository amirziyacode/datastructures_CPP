//
// Created by amirziya on 12/12/25.
//

#include "Graph.h"

#include <iostream>
#include <queue>
#include <stack>


Graph::Graph(int size) {
    list = new Node*[size];
    num = size;
    for (int i=0; i<size; i++) {
        list[i] = nullptr;
    }
}

void Graph::addEdge(const int i,const int j) const {
    if (list[i] == nullptr) {
        list[i] = new Node(j);
    }else {
        Node *p = list[i];
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = new Node(j);
    }
}
int Graph::inDegree(const int j) const {
    int counter = 0;
    for (int i=0; i<num; i++) {
        const Node *ptr = list[i];
        while (ptr != nullptr) {
            if (ptr->value == j) {
                counter++;
            }
            ptr = ptr->next;
        }
    }
    return counter;
}
int Graph::outDegree(int j) const {
    for (int i = 0; i<num; i++) {
        if (list[i]->value == j) {
            int counter = 0;
            Node* ptr = list[i]->next;
            while (ptr != nullptr) {
                counter++;
                ptr = ptr->next;
            }
            return counter;
        }
    }
    return 0;
}

// TODO:Visited All elements in graph
void Graph::BSF(const int i) const {
    bool visited[num];
    for (int index = 0; index<num; index++) {
        visited[index] = false;
    }
    std::queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
        const int cur = q.front();
        q.pop();
        std::cout << cur <<std::endl;
        const Node *p = list[cur];
        while (p != nullptr) {
            if (!visited[p->value]) {
                visited[p->value] = true;
                q.push(p->value);
            }
            p = p->next;
        }
    }
}


void Graph::DSF(const int i) const {
    bool visited[num];
    for (int index = 0; index<num; index++) {
        visited[index] = false;
    }
    std::stack<int> st;
    st.push(i);
    visited[i] = true;
    while (!st.empty()) {
        int temp = st.top();
        st.pop();
        std::cout << temp << std::endl;
        const Node *p = list[temp];
        while (p != nullptr) {
            if (!visited[p->value]) {
                st.push(temp);
                visited[p->value] = true;
            }
            p = p->next;
        }
    }
}

