#ifndef NTREE_H
#define NTREE_H

#include "node.h"

#include <stdlib.h>
#include <stdio.h>

struct ntree_t { 
   struct node_t * _root; 
}; 

struct children_t {
  struct node_t * _current;
};

enum direction_t {
                  FIRST_CHILD=0,   // premier fils
                  NEXT_SIBLING,    // frère suivant
};

/* RETURN an empty n-tree
 */
struct ntree_t * ntree__empty(void);

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * RETURN 0 if t is not an empty n-tree, another value otherwise
 */
int ntree__is_empty(struct ntree_t const * t);

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * POSTCOND the memory allocated for the tree t and all its subtree
 * has been freed
 */
void ntree__free(struct ntree_t * t);

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * RETURN the root node of t
 */
struct node_t * ntree__root(struct ntree_t * t);

/* PARAM n : a node
 * PRECOND n is not NULL, and n is not empty
 * RETURN the sequence of child nodes of n
 */
struct children_t ntree__children(struct node_t * n);

/* PARAM children : a sequence of child nodes
 * PRECOND children is not NULL, and children is not empty
 * RETURN the node pointed by children
 */
struct node_t * children__current(struct children_t const * children);

/* PARAM children : a sequence of child nodes
 * PRECOND children is not NULL
 * RETURN 0 if children is an empty sequence of nodes, another value
 * otherwise
 */
int children__is_empty(struct children_t const * children);

/* PARAM children : a sequence of child nodes
 * PRECOND children is not NULL, and children is not empty
 * POSTCOND either children is empty, or children points to the next node
 * in the sequence
 */
void children__next(struct children_t * children);

/* PARAM n : a node
 * PRECOND n is not NULL, and n is not empty
 * RETURN the degree of node n
 */
size_t ntree__degree(struct node_t * n);

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * RETURN the depth (height) of tree t
 */
size_t ntree__depth(struct ntree_t * t);

/* PARAM x : a value
 * PARAM nodes : an array of nodes
 * PARAM size : the size of nodes
 * PRECOND the nodes have no sibling
 * RETURN the tree with root x and children nodes in the same order
 * as in nodes
 */
struct ntree_t * ntree__build(int x, struct node_t * nodes[], size_t size);

#endif // NTREE_H
