/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <assert.h>
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
  
/* PARAM x : a value
 * PARAM nodes : an array of nodes
 * PARAM size : the size of nodes
 * PRECOND the nodes have no sibling
 * RETURN the tree with root x and children nodes in the same order
 * as in nodes
 */
struct ntree_t * ntree__build(int x, struct node_t * nodes[], size_t size)
{
  struct ntree_t *tree = ntree__empty();
  tree->_root = malloc(sizeof(struct node_t));
  tree->_root->_data = x;
  if ( size == 0 )
  {
    return tree;
  } 
  tree->_root->_children[FIRST_CHILD] = nodes[0];
  for(size_t i = 0; i < size - 1; i++)
  {
    nodes[i]->_children[NEXT_SIBLING] = nodes[i+1];
  }
  return tree;
}