#include <iostream>
#include <vector>

using namespace std;

struct GEdge {
    int child;
    int weight;
    GEdge* next;
};

struct GNode {
    char id;
    int colour;
    int parent;
    GEdge* first;
};

void outputGraph(GNode G[], int n) {
    for (int i = 1; i <= n; ++i) {
        cout << "Node " << G[i].id << " Edges: ";
        GEdge* edge = G[i].first;
        while (edge != NULL) {
            cout << "(" << G[edge->child].id << ", " << edge->weight << ") ";
            edge = edge->next;
        }
        cout << endl;
    }
}

void DFS(GNode G[], int S) {
    G[S].colour = 1;
    cout << "Visited Node " << G[S].id << endl;
    GEdge* edge = G[S].first;
    while (edge != NULL) {
        int child = edge->child;
        if (G[child].colour == 0) {
            G[child].parent = S;
            DFS(G, child);
        }
        edge = edge->next;
    }
}

void depthFirstTraversal(GNode G[], int n, char nodeName) {
    for (int i = 1; i <= n; ++i)
        if (G[i].id == nodeName)
            DFS(G, i);
}

int main() {
    const int n = 5;
    GNode G[n + 1];

    G[1] = {'A', 0, 0, NULL};
    G[2] = {'B', 0, 0, NULL};
    G[3] = {'C', 0, 0, NULL};
    G[4] = {'D', 0, 0, NULL};
    G[5] = {'E', 0, 0, NULL};

    G[1].first = new GEdge{2, 1, NULL};
    G[1].first->next = new GEdge{3, 2, NULL};
    G[2].first = new GEdge{4, 3, NULL};
    G[3].first = new GEdge{5, 4, NULL};

    cout << "Graph Representation:" << endl;
    outputGraph(G, n);
    depthFirstTraversal(G, n, 'A');

    return 0;
}
