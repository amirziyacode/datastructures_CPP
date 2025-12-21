//
// Created by amirziya on 12/21/25.
//

#include "GraphMatrix.h"
GraphMatrix::GraphMatrix(int n_nodes) {
    m = new int*[n_nodes];

    for (int i = 0; i < n_nodes; i++) {
        m[i] = new int[n_nodes];
    }
}

GraphMatrix GraphMatrix::Warshall() {
    GraphMatrix res(*this);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.m[i][j] = res.m[i][j] || (res.m[i][k] && res.m[k][j]);
            }
        }
    }

    return res;
}