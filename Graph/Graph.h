//
// Created by amirziya on 12/12/25.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
#include "Node.h"


class Graph {
    private:
    Node** list;
    int num;
    public:
    Graph(int size);
    void addEdge(int,int) const;
    int inDegree(int) const;
    int outDegree(int) const;
    void BSF(int)const;
    void DSF(int)const;
};


#endif //UNTITLED_GRAPH_H