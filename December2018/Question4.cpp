#include <iostream>
using namespace std;

// Flatten the matrix lala pick an upper or lower triangle
const int n = 20;
int B[n];

int calculateIndex(int i, int j) {
    return (i * (i - 1)) / 2 + j;
}

int edgeWeight(int i, int j) {
    if (i == j || i < 0 || i > n || j < 0 || j > n)
        return -1;

    if (i < j)
        swap(i, j);

    int index = calculateIndex(i, j);
    return B[index];
}

int minCostVertex(int u) {
    if (u < 0 || u >= n)
        return -1;

    int minCost = INT8_MAX;
    int minVertex = -1;

    for (int v = 0; v < n; v++) {
        if (u != v) {
            int weight = edgeWeight(u, v);
            if (weight < minCost) {
                minCost = weight;
                minVertex = v;
            }
        }
    }

    return minVertex;
}

int main() {
    // Sample data for the upper triangular part of the adjacency matrix
    int sampleData[n][n] = {
        {20, 1, 2, 3, 4},
        {20, 20, 5, 6, 7},
        {20, 20, 20, 8, 9},
        {20, 4, 4, 4, 10},
        {12, 12, 12, 12, 12}};

    // Flatten the matrix and store in array B
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int index = calculateIndex(i, j);
            B[index] = sampleData[i][j];
        }
    }

    // Test edgeWeight function
    cout << "Edge Weight between vertex 2 and vertex 3: " << edgeWeight(2, 3) << endl;

    // Test minCostVertex function
    int vertex = 2;
    int minCostVert = minCostVertex(vertex);

    if (minCostVert != -1) {
        cout << "Vertex with minimum cost from vertex " << vertex << ": " << minCostVert << endl;
    } else {
        cout << "No outgoing edge from vertex " << vertex << endl;
    }

    return 0;
}