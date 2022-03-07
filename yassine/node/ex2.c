/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "node.h"
#include "ntree.h"



/* enum direction_t { */
/*                   FIRST_CHILD=0,   // premier fils */
/*                   NEXT_SIBLING,    // frère suivant */
/* }; */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/**
 * RETURN an empty n-tree
 */
struct ntree_t * ntree__empty()
{
    struct ntree_t *t = malloc(sizeof(struct ntree_t));
    t->_root = node__empty();
    return t;
}

/**
 * PARAM t : a n-tree
 * PRECOND t is not NULL
 * POSTCOND the memory allocated for the tree t and all its subtree
 * has been freed but for the empty nodes
 */
void ntree__free(struct ntree_t * t)
{
    if ( node__is_empty(t->_root) )
    {
        free(t);
    }
    else
    {
        if ( node__is_empty(t->_root->_children[NEXT_SIBLING]) )
        {
            struct node_t *tmp = t->_root->_children[FIRST_CHILD];
            free(t->_root);     
            t->_root = tmp;
            ntree__free(t);
        }
        else
        {
            struct ntree_t *tree_child0 = ntree__empty();
            struct ntree_t *tree_child1 = ntree__empty();
            struct node_t *tmp_child0 = t->_root->_children[FIRST_CHILD];
            struct node_t *tmp_child1 = t->_root->_children[NEXT_SIBLING];
            free(t->_root);  
            tree_child0->_root = tmp_child0;
            tree_child1->_root = tmp_child1;
            ntree__free(tree_child0);
            ntree__free(tree_child1); 
            free(t);
        }
    }
}