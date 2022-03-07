/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "node.h"
#include "ntree.h"

/* struct ntree_t { */
/*   struct node_t * root; */
/* }; */

/* enum direction_t { */
/*                   FIRST_CHILD=0,   // premier fils */
/*                   NEXT_SIBLING,    // frère suivant */
/* }; */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/*
 * RETURN an empty n-tree
 */
struct ntree_t * ntree__empty(){
  struct ntree_t * empty = malloc(sizeof(*empty));
  empty->root = node__empty();
  return empty;
}
/*
 * PARAM t : a n-tree
 * PRECOND t is not NULL
 * POSTCOND the memory allocated for the tree t and all its subtree
 * has been freed but for the empty nodes
 */
void ntree__free(struct ntree_t * t){

  if(node__is_empty(t->root)){
    free(t);
  }
  else{
    if(node__is_empty(t->root->_children[NEXT_SIBLING])){
      struct node_t * tmp = t->root->_children[FIRST_CHILD];
      free(t->root);
      t->root = tmp;
      ntree__free(t);      
    }
    else{
      struct ntree_t * first = ntree__empty();
      struct ntree_t * second = ntree__empty();

      struct node_t * first_child = t->root->_children[FIRST_CHILD];
      struct node_t * second_child = t->root->_children[NEXT_SIBLING];
      
      free(t->root);
      first->root = first_child;
      second->root = second_child;

      ntree__free(first);
      ntree__free(second);
      free(t);
    }    
  }
}
