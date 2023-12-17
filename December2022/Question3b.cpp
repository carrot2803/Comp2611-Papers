#include <iostream>
#include <string>

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

int findVertex(Graph* graph, int X_ID) {
    for (int i = 0; i < graph->numVertices; i++)
        if (graph->vertices[i].ID == X_ID)
            return i;
    return -1;
}

bool hasVertex(Graph* graph, int X_ID) {
    return findVertex(graph, X_ID) != -1;
}

bool hasEdge(Graph* g, int u, int v) {
    int sourceLocation = findVertex(g, u);
    int destLocation = findVertex(g, v);
    if (sourceLocation == -1 || destLocation == -1) {
        cout << "Vertex does not exist";
        return false;
    }

    Edge* edge = g->vertices[sourceLocation].firstEdge;

    while (edge != NULL) {
        if (edge->dest == v)
            return true;
        edge = edge->nextEdge;
    }

    return false;
}

int inDegree(Graph* g, int v) {
    if (!hasVertex(g, v)) return -1;
    int count = 0;
    for (int i = 0; i < g->numVertices; i++) {
        if (hasEdge(g, g->vertices[i].ID, v))
            count++;
    }
    return count;
}

int main() {
    Graph* graph = new Graph();
    graph->numVertices = 3;
    graph->vertices[0] = {1, 0, nullptr};
    graph->vertices[1] = {2, 0, nullptr};
    graph->vertices[2] = {3, 0, nullptr};
    graph->vertices[0].firstEdge = new Edge{2, 1, nullptr};
    graph->vertices[1].firstEdge = new Edge{3, 2, nullptr};

    cout << "Vertex 2 exists: " << (hasVertex(graph, 2) ? "true" : "false") << endl;
    cout << "Edge from 1 to 2 exists: " << (hasEdge(graph, 1, 2) ? "true" : "false") << endl;
    cout << "In-degree of vertex 3: " << inDegree(graph, 3) << endl;

    return 0;
}
