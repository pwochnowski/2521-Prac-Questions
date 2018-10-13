// BST ADT
// Don't touch this bit please

typedef struct tree* Tree;

int findValue(Tree t, int v);
int isBST(Tree t);
void getKthSmallest(Tree t, int* k, int** v);
Tree lowestCommonAnc(Tree t, int v1, int v2);
Tree successor(Tree t, Tree target);

Tree find(Tree t, int v);
int getValue(Tree t);
Tree createTree();
void destroyTree(Tree t);
int getRootVal(Tree t);
Tree insert(Tree t, int v);
Tree randInsert(Tree t, int v);
Tree buildTree(Tree t, int* vals, int n, Tree (*f)(Tree, int));
Tree buildInvalidTree(int);
