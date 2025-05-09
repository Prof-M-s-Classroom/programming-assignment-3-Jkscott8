[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jackson Scott

## Description
This program is made to output the minimum spanning tree(mst) using prims algorithm given the edges and vertices. It does this using a min heap and graph classes.
The graph creates and adjacency matrix with all the edge weights, then the min heap stores all the vertices then and pulls the minimum vertex and updates the edge weights of the unvisited neighbors. 
It then stores the weight and vertex till it has visited all the vertices in the graph. To make sure the min value is being returned the heap uses 'heapify', doing so moves around the smallest vertex key in the heap until it's at index 0, then when returning the min it always returns index 0 then repeats the process.  
Once it has visited all vertices it outputs the vertices, edge weights, and total weights.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log v)        |
| Extract Min          | O(log v) / O(1) |
| Decrease Key         | O(log v)        |
| Prim’s MST Overall   | O(V^2)          |

Insert O(log v): 
The insert operation has this run-time because the tree isn't sorted beyond the min being at the root, and the new vertex starts at the bottom of the tree everytime. So the max swaps needed will be the height of the tree, this being log(n) so the big 0 is log(n). But I do think that since in this case for the MST it will be O(1) since it inserts 0 as the first element so it's automatically min, and the rest are MAX_INT so there's no up heaping needed. 

Extract Min O(log v):
The operation of returning the min itself is O(1) because it is just giving the value at the root index(0), but after doing so it has to "heapify", this causes the run time to be log(n) because similar to insert the worst case is the new smallest value is at the bottom so it has to swap at every level of the tree. 

Decrease Key O(log v): 
Similar to the last one the operation of decreasing the key takes O(1), but then if the key being decreased isn't at the root and it is now the smallest one it would take up to log(n) swaps. I may have not understood what min key was supposed to be honestly, but mine runs to log(n).

Prim's MST (V^2): 
The main part of my prims MST runs to V^2 because there is 2 nested loops that run V(number of vertices) and V-1 times so multiplying those together gets you V^2, the first loop is extracting each vertex and the second is finding the min path, and that is the biggest time operation in the prim mst. This isn't great runtime, but with a max of 10 vertices it isn't too bad.  

## Test Case Description
Assumptions:
My program assumes that the tree is connected every time since you said that is the case. 

The first test-case I used was the one in main.cpp since that's the one the code is supposed to return the MST for.

Input:

g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

Output:

Edge: 0-1 Edge-Weight: 2 
Edge: 1-2 Edge-Weight: 3
Edge: 1-4 Edge-Weight: 5
Edge: 0-3 Edge-Weight: 6


Total Weight: 16

I did a second one just to verify

Input:

Graph g(6);
g.addEdge(0, 1, 4);
g.addEdge(0, 2, 1);
g.addEdge(1, 2, 2);
g.addEdge(1, 3, 5);
g.addEdge(2, 3, 8);
g.addEdge(2, 4, 10);
g.addEdge(3, 4, 3);
g.addEdge(3, 5, 6);
g.addEdge(4, 5, 7);

Output: 

Edge: 2-1 Edge-Weight: 2
Edge: 0-2 Edge-Weight: 1
Edge: 1-3 Edge-Weight: 5
Edge: 3-4 Edge-Weight: 3
Edge: 3-5 Edge-Weight: 6
Total Weight: 17

Challenges Faced:
I started the assignment before the tuesday class so it was a little confusing trying to figure out how everything was supposed to work, I was able to implement everything except the primMST before the class because W3 Schools had some good resources explaining it. I also had some trouble with the arrays in C++ because my into class was in Python not Java, so I was new to handling those. 
I surprisingly didn't really get errors, but I did have a lot of trouble with the primMST function because it kept giving me the same vertex multiple times, it also sometimes gave me not the min edge weight, but after your walkthrough I realized my methodology was wrong, and I was able to make it more like yours, and it seems to be working well. 