#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"


// Practice graph questions for Week 12 Prac Exam
// Written by Paul Wochnowski and Brittany Evat

/* --------------- README --------------
 * A quick note before you begin these questions,
 * it's very strongly recommended that you work these out on pen and paper
 * before actually coding, figure out what edge cases there are, and just
 * work through some of those logically on paper.
 * These questions (tree questions) in particular are typical interview questions.
 * If you're into role playing (or not), try and practice speaking out your thoughts
 * the whole time as you're doing these questions on paper/coding. This is what
 * the interviewer wants to see, your thinking process. It'll also help you maintain
 * focus and pick up errors which you would otherwise miss.
 *
 * https://en.wikipedia.org/wiki/Rubber_duck_debugging is pretty legit
 *
 * glhf
 */


// graph representation for you to play around with (adjacency matrix)
typedef struct GraphRep {
   int   nV;    // #vertices
   int   nE;    // #edges
   int **edges; // matrix of booleans
} GraphRep;

/* 
 * Easy/Medium Questions 
 * - Likely to be asked in a prac exam 
 */

// write a function that takes an undirected Graph g, a vertex v, and returns
// the total number of nodes connected to that vertex
// a node is "connected" if it is reachable from the source vertex v

int bfsConnected(Graph g, int v) {
    return 0;
}

// write a function that takes a graph, a source vertex and a
// destination vertex and finds the number of unique paths 
// (that don't contain a cycle) from the source to the destination
int numPaths(Graph g, int src, int dest) {
    return 0;
}

// (13s1 final exam question)
// write a function that takes a graph and returns the number of components
int numComponents(Graph g) {
    return 0;
}


/*
 * Cycle detection.
 *
 * Write a function which takes in an undirected Graph g, and returns 1 if
 * the graph has a cycle, 0 otherwise
 *
 */

int hasCycle(Graph g) {

  return 0;
}

/*
 *
 * Given a unweighted/undirected graph, a starting vertex and a distance, return an array which contains all the vertices that are at most that distance away. 
 * The vertices in the array should be in order of increasing distance, and for vertices that are the same distance away, ordered from smallest to largest. 
 * You should also include the initial vertex in the array and also store the number of vertices in the array you returned in size*.
 *
 *  0 -> 1 -> 2
 *  |
 *  v
 *  3
 *  within(g,0,1,&n) ==> [0, 3, 1], n == 3
 */
int* within(Graph g, int s, int d, int *size) {

  return NULL;
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
// i.e. vertices 0 and 1 are in the first connected component (represented by 0 in the array), and
// vertices 2 and 3 are in the second connected component (represented by 1)

int *components(Graph g) {

  return NULL;
}


/*
 * Hard Questions
 * - Unlikely to be asked in a prac exam
 */

/* 
  Create a bipartition of the graph.

  Determine whether it is possible to split the vertices of a graph into two lists L1 and L2, such that no pair of vertices in the same list are connected by an edge in the graph. 
  If this is possible, return 1 and store the two partitions seperately in either L1 or L2. There will usually be multiple valid partitions, in this case you may return any valid answer. 
  If it is not possible, return 0.

  For example consider the following graph:

  1  -> 2  -> 5
              ^
  |           |
  v           v
  4 <-> 3  -> 6
  bipartation(G, l1, l2) == 1,
  one possible example of a bipartition for G is L1 = [1, 5, 3], L2 = [2, 4, 6]


  1 <-> 2 <-> 3 <---\
        ^           |
        |           |
        v           v 
        4 <-> 6 <-> 7 
  bipartition(G, l1, l2) == 0

*/

int bipartition(Graph g, List l1, List l2) {

  return 1;
}


/*
 * =============================================
 * END OF QUESTIONS 
 * ============================================
 */


/*
   You can ignore these methods below, unless you want examples of using the  graph 
   */

// check validity of Vertex 
int validV(Graph g, int v)
{
  return (g != NULL && v >= 0 && v < g->nV);
}

// make an edge
Edge mkEdge(Graph g, int v, int w)
{
  assert(g != NULL && validV(g,v) && validV(g,w));
  Edge new = {v,w}; // struct assignment
  return new;
}

// insert a bidirectional edge from v to w
// - sets (v,w) and (w,v)
void insertBEdge(Graph g, int v, int w, int wt)
{
  insertEdge(g,v,w,wt);
  insertEdge(g,w,v,wt);
}

//insert an edge from v to w
// - sets (v,w)
void insertEdge(Graph g, int v, int w, int wt)
{
  assert(g != NULL && validV(g,v) && validV(g,w));
  if (g->edges[v][w] == 0) {
    g->edges[v][w] = wt;
    g->nE++;
  }
}
// remove an Edge
// - unsets (v,w) and (w,v)
void removeEdge(Graph g, int v, int w)
{
  assert(g != NULL && validV(g,v) && validV(g,w));
  if (g->edges[v][w] != 0) {
    g->edges[v][w] = 0;
    g->nE--;
  }
}

// create an empty graph
Graph newGraph(int nV)
{
  assert(nV > 0);
  int v, w;
  Graph new = malloc(sizeof(GraphRep));
  assert(new != 0);
  new->nV = nV; new->nE = 0;
  new->edges = malloc(nV*sizeof(int *));
  assert(new->edges != 0);
  for (v = 0; v < nV; v++) {
    new->edges[v] = malloc(nV*sizeof(int));
    assert(new->edges[v] != 0);
    for (w = 0; w < nV; w++)
      new->edges[v][w] = 0;
  }
  return new;
}

// free memory associated with graph
void dropGraph(Graph g)
{
  assert(g != NULL);
  int v;
  for (v = 0; v < g->nV; v++) {
    free(g->edges[v]);
  }
  free(g->edges);
  free(g);

}

// display graph, using names for vertices
void showGraph(Graph g, char **names)
{
  assert(g != NULL);
  printf("#vertices=%d, #edges=%d\n\n",g->nV,g->nE);
  int v, w;
  for (v = 0; v < g->nV; v++) {
    printf("%d %s\n",v,names[v]);
    for (w = 0; w < g->nV; w++) {
      if (g->edges[v][w]) {
        printf("\t%s (%d)\n",names[w],g->edges[v][w]);
      }
    }
    printf("\n");
  }
}

int adjacent(Graph g, int v, int u) {
  return !!g->edges[v][u] || !!g->edges[u][v];
}
