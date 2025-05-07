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
        delete[] adjMatrix;
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() // Must print MST edges and total weight
    {
        int weight = 0;
        std::vector<bool> visited(numVertices, false);
        std::vector<int> key(numVertices);
        std::vector<int> weights(numVertices);
        MinHeap min_heap(numVertices);
        visited[0] = true;
        key[0] = 0;
        weights[0] = 0;
        for (int k = 1; k < numVertices; k++) {
            for (int i = 0; i < numVertices-1; i++) {
                if (visited[i] == true) {
                    for (int j = 0; j < numVertices; j++) {
                        if (adjMatrix[i][j] != INT_MAX && visited[j] == false) {
                            min_heap.insert(j, adjMatrix[i][j]);
                        }
                    }
                }
            }
            weights[k] = min_heap.extractMinKey(0);
            key[k] = min_heap.extractMin();
            visited[key[k]] = true;
        }
        int total_weight = 0;
        for (int i = 0; i < numVertices; i++) {
            total_weight += weights[i];
            std::cout << "Vertex: "<<key[i] <<" Edge-Weight: "<< weights[i] << std::endl;
        }
        std::cout << "Total Weight: " << total_weight << std::endl;
    }




private:
    int** adjMatrix;
    int numVertices;
};

#endif