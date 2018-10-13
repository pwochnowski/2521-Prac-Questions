#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BST.h"


/* --------------- README --------------
 * These are the BST solutions!
 * Only look here once you've given up on the question.
 * That's the point where you're convinced that your fists or
 * face would probably write better code than your hands, no sooner
 */


// Tree struct you have to play with
struct tree {
  Tree right, left;
  int val;
};

/* 
 * Easy Questions 
 */
// Check if a value is in the tree
// Should return 1 if it finds it, otherwise 0
int findValue(Tree t, int v) {
  // Our base case, where t our tree is empty (NULL)
  if (t == NULL) return 0;

  // If we have our value in the current root we're looking at,
  // return 1
  if (t->val == v) {
    return 1;
  }

  // Otherwise, continue to look down the left and right children
  // Remember that an || in this case will yield 1 if either value
  // is 1, so if the left tree found the value, then we'd get:
  // (1 || 0) == 1
  return findValue(t->left, v) || findValue(t->right, v);
}

//Helper function (should probably be static) 
int isActuallyBST(Tree, int, int);

// Check to see if the given tree is actually a BST
// The rule is that from some arbitrary root, the left child's value must be
// smaller than the root, and the right child bigger
// return 0 if it isn't a BST, 1 if it is
int isBST(Tree t) {
  int inf = 23151346; //close enough to infinity for our purposes
  return isActuallyBST(t,-inf, inf);
}

int isActuallyBST(Tree t, int lo, int hi) {
  // Base case, if our tree is empty, return that it is a BST
  if (t == NULL) return 1;

  // We check our immediate root to see if they meet the BST property 
  if (t->val <= lo || t->val >= hi) return 0;
  

  // Check to see if our left and right subtrees also maintain the BST invariant
  int leftBranch = isActuallyBST(t->left, lo, t->val);
  int rightBranch = isActuallyBST(t->right,t->val, hi);
  return (leftBranch && rightBranch);
}


/*
 * Medium Questions
 */

/*
 * Given a pointer to a node in the tree, return the value of its in order successor node in the tree, that is the smallest value belonging to a node in the tree that is larger than the given one.
 */

//Helper function 1
Tree min(Tree t) {
  return (t->left) ? min(t->left) : t;
}

//Helper function 2
Tree succ(Tree t, int v) {
  Tree res = NULL;
  if (v < t->val) {
    res = succ(t->left, v);
    //If we haven't found a successor then the current node must be the successor since it's bigger than v
    //and no nodes smaller than it are the successor
    if (res == NULL) res = t;
  } else if (v > t->val) {
    res = succ(t->right, v);
  }
  return res;
}

//The successor is either the smallest node in the right subtree or the last node on the path from the root to target where we turned left.
Tree successor(Tree t, Tree target) {
  return (target->right) ? min(target->right) : succ(t, target->val);
}
/* 
   You are given a Tree (t), and two pointers.
   k is a pointer to the 'kth' smallest value you should go to
    E.g. for *k == 0, it should return the smallest value
         for *k == 4, it should return the 5th smallest value
   v is a pointer to an int pointer, the function should finish by pointing to the value
    E.g. You found the kth smallest value, there should be some code which says
         *v = &(t->val)
    Initially, v is set to point to NULL
  
    You can assume the tree is a BST with at least one element and no duplicates 
    and that 0 <= k < n where n is the number of nodes in the tree
*/
void getKthSmallest(Tree t, int* k, int** v) {
  // If the tree is empty, or we've found our value, return
  if (t == NULL || *v != NULL) {
    return;
  }

  // First, go down as far left as we can
  getKthSmallest(t->left, k, v);

  // The return will place us as far left as we can go
  // We use 'k' as a countdown to see if we've hit the kth smallest
  // value
  // In here we check if k == 0, if it is, we set our v
  if (*k <= 0 && *v == NULL) {
    *v = &(t->val);
  }
  // Next time we will meet the next smallest value, so decrement
  *k = *k - 1;

  // We have traversed down as far left as we can, go one step right,
  // then go down as far left as we can again (we start at the top of this
  // function)
  getKthSmallest(t->right, k, v);


  // Notice that this is just an infix operation
}

/* Find the lowest common ancestor between the noes with values v1 and v2.
   You are guaranteed that both these values exist in your BST
   The lowest common ancestor is defined as the first node which each of
   v1 and v2 share, as they go up the tree. I.e. the root of the whole tree is
   the highest common ancestor. For the following tree:
           
            4
          /   \
         2     7
        / \   /
       1   3 6
      /
     0 
   If v1 == 3, and v2 == 7, then their lowest common ancestor is 4
   If v1 == 3, and v2 == 0, then their lowest common ancestor is 2
*/
Tree lowestCommonAnc(Tree t, int v1, int v2) {
  // Keep in mind what information you have; the key here is that you have
  // a BST, and you are guaranteed that the nodes exist
  // There is no need to find the actual nodes

  // Base case
  if (t == NULL) return NULL;

  // Check to see where v1 and v2 lie relative to the current tree
  // We recurse down until they diverge
  if (t->val < v1 && t->val < v2) {
    return lowestCommonAnc(t->right, v1, v2);
  } else if (t->val > v1 && t->val > v2) {
    return lowestCommonAnc(t->left, v1, v2);
  }

  // If it failed both the above conditions, that means that v1 and v2
  // diverge down different branches, and we have found their lowest common
  // ancestor
  return t;
}


/*

   You can ignore these methods below, unless you want examples of using the tree

*/
Tree createTree() {
  return NULL;
}

void destroyTree(Tree t) {
  if (t == NULL) return;
  destroyTree(t->right);
  destroyTree(t->left);
  free(t);
}

Tree insert(Tree t, int v) {
  if (t == NULL) {
    t = malloc(sizeof(struct tree));
    t->val = v;
    t->right = NULL;
    t->left = NULL;
  } else {
    if (t->val < v) {
      t->right = insert(t->right, v);
    } else if (t->val > v) {
      t->left = insert(t->left, v);
    }
  }
  return t;
}

Tree randInsert(Tree t, int v) {
  if (t == NULL) {
    t = malloc(sizeof(struct tree));
    t->val = v;
    t->right = NULL;
    t->left = NULL;
  } else {
    if (rand() % 2) {
      t->right = randInsert(t->right, v);
    } else {
      t->left = randInsert(t->left, v);
    }
  }
  return t;
}

int getRootVal(Tree t) {
  assert(t != NULL);
  return t->val;
}

Tree buildTree(Tree t, int* vals, int n, Tree (*f)(Tree, int)) {
  int i = 0;
  for (i = 0; i < n; ++i) {
    t = f(t, vals[i]);
  }
  return t;
}


Tree newNode(int v) {
  Tree n = malloc(sizeof(struct tree));
  n->val = v;
  n->left = NULL;
  n->right = NULL;
  return n;
}


Tree buildInvalidTree(int c) {
  Tree t = newNode(10); 
  switch (c) {
    case(0) :
      t->left = newNode(5);
      break;
    case(1) :
      t->right = newNode(5);
      break;
    case(2) :
      t->left = newNode(5);
      t->left->right = newNode(7);
      break;
    case(3) :
      t->left = newNode(5);
      t->left->right = newNode(15);
      break;
    case(4) :
      t->left = newNode(5);
      t->left->right = newNode(7);
      break;
    case(5) :
      t->left = newNode(5);
      t->left->right = newNode(15);
      break;
    case(6) :
      t->left = newNode(5);
      t->left->right = newNode(7);
      t->left->right->left = newNode(6);
      break;
    case(7) :
      t->left = newNode(5);
      t->left->right = newNode(7);
      t->left->right->left = newNode(6);
      t->left->right->left->right = newNode(16);
      break;
  } 
  return t;
}




