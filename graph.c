#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BST.h"


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


// Tree struct you have to play with
struct tree {
  Tree right, left;
  int val;
};

/* 
 * Easy Questions 
 */


/*
 * Medium Questions
 */
/* 
  Create a bipartition of the graph.

  Determine whether it is possible to split the vertices of a graph into two lists L1 and L2, such that no pair of vertices in each list is conntected by an edge.  
  If this is possible, return 1 and store the two partitions seperately in either L1 or L2. 
  If it is not possible, return 0.

*/

int bipartition(Graph g, List l1, List l2) {

  return 0;
}


/*
   You can ignore these methods below, unless you want examples of using the tree
*/

