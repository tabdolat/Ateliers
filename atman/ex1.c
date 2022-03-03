/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "node.h"

/* As a reminder, the following functions are provided in "node.h" :

   struct node_t {
     int _data;
     struct node_t * _children[2];
   };

   struct node_t * node__empty();
   int node__is_empty(struct node_t const * n);
   int node__data(struct node_t const * n);
   struct node_t * node__child(struct node_t const * n, unsigned d);
*/


/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/**
 * PARAM n : a node
 * PARAM x : a data
 * PRECOND n is not empty
 * POSTCOND n has been initialized with data x and empty child nodes
 */
void node__initialize(struct node_t * n, int x){
    if(node__is_empty(n)){
        n->_data=x;
        n->_children=node__empty();
    }
}

/**
 * PARAM n1 : a node
 * PARAM n2 : a node
 * PARAM d : a direction (0 or 1)
 * PRECOND : n1 is not an empty node, and d is either 0 or 1
 * POSTCOND : n2 is the child of n1 at direction d
 * RETURN the previous child of n1 at direction d
 **/
struct node_t * node__link(struct node_t * n1, struct node_t * n2, unsigned d){
    if (node__is_empty(n1) || d > 1 ){
        return NULL;
    }
    struct node_t *n=n1->_children[d];
    n1->_children[d]=n2;
    return n; 
}

/**
 * PARAM n : a node
 * PARAM d : a direction (0 or 1)
 * PRECOND : n is not an empty node, and d is either 0 or 1
 * POSTCOND : the child of n at direction d is an empty node
 * RETURN the previous child of n at direction d
 **/
struct node_t * node__unlink(struct node_t * n, unsigned d){
    if (node__is_empty(n) || d > 1 ){
        return NULL;
    }
    struct node_t *nd=n->_children[d];
    n->_children[d]=node__empty();
    return nd;
}
