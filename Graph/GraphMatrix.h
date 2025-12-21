//
// Created by amirziya on 12/21/25.
//

#ifndef UNTITLED_GRAPHMATRIX_H
#define UNTITLED_GRAPHMATRIX_H


class GraphMatrix {
private:
    int **m;
    int n;
    public:
    GraphMatrix(int);
    GraphMatrix Warshall();
};


#endif //UNTITLED_GRAPHMATRIX_H