#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <ostream>

class MinHeap {
public:
    MinHeap(int capacity) {
        size = 0;
        this-> capacity = capacity;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (size == capacity) {
            std::cout << "Heap Is Full" << std::endl;
            return;
        }
        size++;
        int i = size - 1;
        heapArray[i] = vertex;
        position[vertex] = i;
        keyArray[vertex] = key;
        while (i != 0 && keyArray[heapArray[(i-1)/2]] > keyArray[heapArray[i]]) {
            int swap = heapArray[(i-1)/2];
            heapArray[(i-1)/2] = heapArray[i];
            heapArray[i] = swap;
            position[heapArray[i]] = i;
            position[heapArray[(i-1)/2]] = (i-1)/2;
            i = (i-1)/2;
        }
    }
    int extractMin() {
        if (size == 0) {
            std::cout << "Empty Heap" << std::endl;
            return -1;
        }
        int minVal = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        position[heapArray[0]] = 0;
        size--;
        minHeapify(0);
        return minVal;

    }
    int extractMinKey(int vertex) {
        return keyArray[heapArray[vertex]];
    }
    void decreaseKey(int vertex, int newKey) {
        keyArray[vertex] = newKey;
        int i = position[vertex];
        while (i != 0 && keyArray[heapArray[(i-1)/2]] > keyArray[heapArray[i]]) {
            int swap = heapArray[(i-1)/2];
            heapArray[(i-1)/2] = heapArray[i];
            heapArray[i] = swap;
            position[heapArray[i]] = i;
            position[heapArray[(i-1)/2]] = (i-1)/2;
            i = (i-1)/2;
        }


    }
    bool isInMinHeap(int vertex) {
        if (heapArray[position[vertex]] == vertex) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        if (size == 0) {
            return;
        }
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]]) {
            smallest = left;
        }
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]]) {
            smallest = right;
        }
        if (smallest != idx) {
            int swap = heapArray[smallest];
            heapArray[smallest] = heapArray[idx];
            heapArray[idx] = swap;
            position[heapArray[idx]] = idx;
            position[heapArray[smallest]] = smallest;
            minHeapify(smallest);
        }
    }
};

#endif