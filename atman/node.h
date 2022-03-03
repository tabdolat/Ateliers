#ifndef NODE_H
#define NODE_H

struct node_t {
  int _data;
  struct node_t * _children[2];
};

/* RETURN an empty node
 */
struct node_t * node__empty(void);

/* PARAM n : a node
 * PARAM x : a data
 * PRECOND n is not empty
 * POSTCOND n has been initialized with data x and empty child nodes
 */
void node__initialize(struct node_t * n, int x);

/* PARAM n : a node
 * RETURN 0 if n is not an empty node, non-0 otherwise
 */
int node__is_empty(struct node_t const * n);

/* PARAM n : a node
 * PRECOND n is not an empty node
 * RETURN the data stored in node n
 */
int node__data(struct node_t const * n);

/* PARAM n : a node
 * PARAM d : a direction (0 or 1)
 * PRECOND n is not an empty node, and d is either 0 or 1
 * RETURN the child of node n at direction d
 */
struct node_t * node__child(struct node_t const * n, unsigned d);

/* PARAM n1 : a node
 * PARAM n2 : a node
 * PARAM d : a direction (0 or 1)
 * PRECOND : n1 is not an empty node, and d is either 0 or 1
 * POSTCOND : n2 is the child of n1 at direction d
 * RETURN the previous child of n1 at direction d
 */
struct node_t * node__link(struct node_t * n1, struct node_t * n2, unsigned d);

/* PARAM n : a node
 * PARAM d : a direction (0 or 1)
 * PRECOND : n is not an empty node, and d is either 0 or 1
 * POSTCOND : the child of n at direction d is an empty node
 * RETURN the previous child of n at direction d
 */
struct node_t * node__unlink(struct node_t * n, unsigned d);

#endif //  NODE_H
