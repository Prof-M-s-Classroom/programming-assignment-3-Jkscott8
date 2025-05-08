#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = INT_MAX;
            }
        }
    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() // Must print MST edges and total weight
    {
        MinHeap min_heap = MinHeap(numVertices);
        std::vector<bool> visited(numVertices, false);
        std::vector<int> parent(numVertices);
        std::vector<int> weights(numVertices, INT_MAX);
        min_heap.insert(0,0);
        visited[0] = true;
        for (int i = 1; i < numVertices; i++) {
            min_heap.insert(i, INT_MAX);
        }
        for (int j = 1; j < numVertices; j++) {
            int min = min_heap.extractMin();
            visited[min] = true;
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[min][i] < weights[i] && adjMatrix[min][i] != INT_MAX && visited[i] == false) {
                    min_heap.decreaseKey(i, adjMatrix[min][i]);
                    parent[i] = min;
                    weights[i] = adjMatrix[min][i];
                }
            }
        }
        int total_weight = 0;
        for (int i = 1; i < numVertices; i++) {
            int weight = adjMatrix[parent[i]][i];
            total_weight += weight;
            std::cout << "Edge: "<< parent[i] <<'-'<< i <<" Edge-Weight: "<< weight << std::endl;
        }
        std::cout << "Total Weight: " << total_weight << std::endl;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif