/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "ntree.h"

/* As a reminder, these definitions are inside 'ntree.h'

struct ntree_t {
  struct node_t * _root;
};

enum direction_t {
                  FIRST_CHILD=0,   // premier fils
                  NEXT_SIBLING,    // frère suivant
};
*/


/********** FIN DU CODE A NE PAS MODIFIER ***********************/

int ntree__is_empty(struct ntree_t const * t)
{
  return node__is_empty(t->_root);
}

/* PARAM n : a node
 * PRECOND n is not NULL, and n is not empty
 * RETURN the degree of node n
 */
size_t ntree__degree(struct node_t * n)
{
  size_t i = 0;
  struct children_t *child = malloc(sizeof(*child));
  child->_current = n->_children[FIRST_CHILD];
  while ( !children__is_empty(child) )
  {
    i++;
    children__next(child);
  }
  free(child);
  return i;
}

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * RETURN the depth (height) of tree t
 */
int max(int a, int b)
{
  return a < b ? b: a;
}

size_t ntree__depth(struct ntree_t * t)
{
  if ( ntree__is_empty(t) )
  {
    return 0;
  }
  else
  {
    if ( node__is_empty(t->_root->_children[NEXT_SIBLING]) )
    {
      struct ntree_t *tmp_tree = ntree__empty();
      tmp_tree->_root = t->_root->_children[FIRST_CHILD];
      return 1 + ntree__depth(tmp_tree);
    }
    else if ( node__is_empty(t->_root->_children[FIRST_CHILD]) )
    {
      struct ntree_t *tmp_tree2 = ntree__empty();
      tmp_tree2->_root = t->_root->_children[NEXT_SIBLING];
      return ntree__depth(tmp_tree2);
    }
    struct ntree_t *tmp_tree = ntree__empty();
    struct ntree_t *tmp_tree2 = ntree__empty();  
    tmp_tree->_root = t->_root->_children[FIRST_CHILD];
    tmp_tree2->_root = t->_root->_children[NEXT_SIBLING];
  
    return 1 + max(ntree__depth(tmp_tree), ntree__depth(tmp_tree2));
  }
}
