//
// Created by amirziya on 12/12/25.
//

#include "Graph.h"

#include <iostream>
#include <queue>


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
// TODO:Visited All elements in graph
void Graph::BSFC(const int i) const {
    bool visited[num];
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

