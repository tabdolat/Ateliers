/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "ntree.h"
//#include "children.h"

/* As a reminder, the following definitions are provided in "ntree.h" :

   struct ntree_t {
     struct node_t * _root;
   };

   enum direction_t {
                  FIRST_CHILD=0,   // premier fils
                  NEXT_SIBLING,    // frère suivant
   };

   And the following definitions are provided in "children.h" :

   struct children_t {
     struct node_t * _current;
   };
*/

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/**
 * PARAM children : a sequence of child nodes
 * PRECOND children is not NULL, and children is not empty
 * RETURN the node pointed by children
 */
struct node_t * children__current(struct children_t const * children)
{
  return children->_current;
}

/**
 * PARAM children : a sequence of child nodes
 * PRECOND children is not NULL
 * RETURN 0 if children is an empty sequence of nodes, another value
 * otherwise
 */
int children__is_empty(struct children_t const * children)
{
  return node__is_empty(children->_current);
}

/**
 * PARAM children : a sequence of child nodes
 * PRECOND children is not NULL, and children is not empty
 * POSTCOND either children is empty, or children points to the next node
 * in the sequence
 */
void children__next(struct children_t * children)
{
  assert( children != NULL && !children__is_empty(children) );
  children->_current = children->_current->_children[NEXT_SIBLING];  
}

/*
  if( node__is_empty(children->_current->_children[NEXT_SIBLING]) )
  {
    children->_current = NULL; ->_children[NEXT_SIBLING]*/
  
  

/**
 * PARAM n : a node
 * PRECOND n is not NULL, and n is not empty
 * RETURN the sequence of child nodes of n
 */
struct children_t ntree__children(struct node_t * n)
{
  struct children_t child;
  if ( !node__is_empty(n->_children[FIRST_CHILD]) )
  {
    child._current = n->_children[FIRST_CHILD];
  } 
  return child;
}