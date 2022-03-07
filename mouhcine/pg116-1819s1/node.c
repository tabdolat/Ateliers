#include <assert.h>
#include <stdlib.h>

#include "node.h"

struct node_t * node__empty(void)
{
  return NULL;
}


int node__is_empty(struct node_t const * n)
{
  return (n == NULL);
}


int node__data(struct node_t const * n)
{
  assert( ! node__is_empty(n) );
  return n->_data;
}


struct node_t * node__child(struct node_t const * n, unsigned d)
{
  assert( ! node__is_empty(n) );
  assert( d < 2 );
  return n->_children[d];
}
