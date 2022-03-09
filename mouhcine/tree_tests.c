#include <stdio.h>

#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "ntree.h"

static void test_ntree__empty(void){
  printf("%s", __func__);
  
  struct ntree_t * empty = ntree__empty();

  assert(node__is_empty(empty->root));

  ntree__free(empty);

  printf("\t Ok\n");
  
}

static void test_ntree__free(void){
  printf("%s", __func__);

  struct ntree_t * tree = ntree__empty();

  struct node_t * root = malloc(sizeof(*root));

  struct node_t * n1 = malloc(sizeof(struct node_t *));
  struct node_t * n2 = malloc(sizeof(struct node_t *));
  struct node_t * n3 = malloc(sizeof(struct node_t *));
  struct node_t * n4 = malloc(sizeof(struct node_t *));

  node__initialize(root, 0);
  node__initialize(n1, 1);
  node__initialize(n2, 2);
  node__initialize(n3, 3);
  node__initialize(n4, 4);

  tree->root = root;

  node__link(root, n1, FIRST_CHILD);
  node__link(root, n2, NEXT_SIBLING);
  node__link(n1, n3, FIRST_CHILD);
  node__link(n2, n4, FIRST_CHILD);

  
  ntree__free(tree);
  

  printf("\t Ok \n");
}


int main(void){
  test_ntree__empty();
  test_ntree__free();
  return 0;
}
