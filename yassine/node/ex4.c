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
;

/* PARAM n : a node
 * PRECOND n is not NULL, and n is not empty
 * RETURN the degree of node n
 */
size_t ntree__degree(struct node_t * n)
;

/* PARAM t : a n-tree
 * PRECOND t is not NULL
 * RETURN the depth (height) of tree t
 */
size_t ntree__depth(struct ntree_t * t)
;
