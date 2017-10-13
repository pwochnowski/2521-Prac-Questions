// Practice graph questions for Week 12 Prac Exam

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// graph representation (adjacency matrix)
typedef struct GraphRep {
   int   nV;    // #vertices
   int   nE;    // #edges
   int **edges; // matrix of booleans
} GraphRep;

// Write a function which takes in 
// g : a Graph
// s : a starting Vertex
// d : maximum distance from the starting Vertex
// vs : the address of an array of Vertex values
// and stores in vs all vertices which lie within a distance d of the
// start vertex, and returns a count of the number of Vertex values
// stored in the array.
// (Distance is measured in number of edges on the shortest path
// from the starting vertex)

int within(Graph g, Vertex s, int d, Vertex *vs) {

}


// Write a function which takes in a Graph g, and returns 1 if
// the graph has a cycle, 0 otherwise

int hasCycle(Graph g) {

}


// Write a function which takes in a Graph g and returns a 
// vertex-indexed connected components array
// e.g. a graph with the following adjacency matrix representation 
// 0 1 0 0
// 1 0 0 0
// 0 0 0 1
// 0 0 1 0
// would return the following array:
// [0, 0, 1, 1]
// i.e. vertices 0 and 1 are in the first connected component, and
// vertices 2 and 3 are in the second connected component

int *createComponents(Graph g) {

}
