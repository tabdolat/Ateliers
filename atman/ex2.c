/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "node.h"
#include "ntree.h"

/* struct ntree_t { */
/*   struct node_t * _root; */
/* }; */

/* enum direction_t { */
/*                   FIRST_CHILD=0,   // premier fils */
/*                   NEXT_SIBLING,    // frère suivant */
/* }; */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/**
 * RETURN an empty n-tree
 */
struct ntree_t * ntree__empty()
    ;

/**
 * PARAM t : a n-tree
 * PRECOND t is not NULL
 * POSTCOND the memory allocated for the tree t and all its subtree
 * has been freed but for the empty nodes
 */
void ntree__free(struct ntree_t * t)
    ;
