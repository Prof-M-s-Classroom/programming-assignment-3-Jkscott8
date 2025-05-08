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
        int weight = 0;
        std::vector<bool> visited(numVertices, false);
        std::vector<int> parent(numVertices);
        std::vector<int> mst(numVertices);
        std::vector<int> weights(numVertices, INT_MAX);
        MinHeap min_heap(numVertices);
        visited[0] = true;
        mst[0] = 0;
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
            int weight =  min_heap.extractMinKey(0);
            int vertex = min_heap.extractMin();
            if (visited[vertex] == true) {
                k--;
                continue;
            }
            weights[k] = weight;
            mst[k] = vertex;
            visited[mst[k]] = true;
        }
        for (int i = 1; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[mst[i]][j] == weights[i]) {
                    parent[i] = j;
                }
            }
        }
        int total_weight = 0;
        for (int i = 1; i < numVertices; i++) {
            total_weight += weights[i];
            std::cout << "Edge: "<< parent[i] <<'-'<< mst[i] <<" Edge-Weight: "<< weights[i] << std::endl;
        }
        std::cout << "Total Weight: " << total_weight << std::endl;
    }




private:
    int** adjMatrix;
    int numVertices;
};

#endif