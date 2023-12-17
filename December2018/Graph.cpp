#include <iostream>
using namespace std;

struct Edge {
    int dest;
    int weight;
    Edge* nextEdge;
};

struct Vertex {
    int ID;
    int colour;
    Edge* firstEdge;
};

struct Graph {
    int numVertices;
    Vertex vertices[100];
};

int edgeWeight(Graph* graph, int i, int j) {
    if (i < 0 || i >= graph->numVertices || j < 0 || j >= graph->numVertices || i == j)
        return -1;

    Edge* edge = graph->vertices[i].firstEdge;
    while (edge != NULL) {
        if (edge->dest == j)
            return edge->weight;
        edge = edge->nextEdge;
    }

    return -1;
}

int minCostVertex(Graph* graph, int u) {
    int minWeight = INT8_MAX;
    int minVertex = -1;

    Edge* edge = graph->vertices[u].firstEdge;
    while (edge != NULL) {
        int weight = edgeWeight(graph, u, edge->dest);
        if (weight != -1 && weight < minWeight) {
            minWeight = weight;
            minVertex = edge->dest;
        }
        edge = edge->nextEdge;
    }

    return minVertex;
}

int main() {
    Graph* graph = new Graph;
    graph->numVertices = 3;

    graph->vertices[0].firstEdge = new Edge{1, 2, nullptr};
    graph->vertices[1].firstEdge = new Edge{2, 3, nullptr};
    graph->vertices[2].firstEdge = nullptr;

    int weight = edgeWeight(graph, 0, 1);

    if (weight != -1)
        cout << "The weight of the edge between vertex 0 and 1 is " << weight << endl;
    else
        cout << "There is no edge between vertex 0 and 1" << endl;

    int minVertex = minCostVertex(graph, 0);

    if (minVertex != -1)
        cout << "The vertex with the minimum edge cost from vertex 0 is " << minVertex << endl;
    else
        cout << "There is no edge from vertex 0" << endl;

    return 0;
}
