#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"

static void test_node__initialize(void){
  printf("%s", __func__);
  struct node_t * empty = malloc(sizeof(*empty));//node__empty();
  empty->_data = 2;
  /* empty->_children[1]->_data = 10; */
  /* empty->_children[2]->_data = 20; */

  node__initialize(empty, 23);

  assert(empty->_data == 23);
  assert(node__is_empty(empty->_children[0]));
  assert(node__is_empty(empty->_children[1]));
  
  free(empty);
  
  printf("\t Ok\n");
  
}

static void test_node__link(void){
  printf("%s", __func__);

  struct node_t * first = malloc(sizeof(*first));
   
  struct node_t n1 = {._data = 10, ._children[0] = NULL, ._children[1] = NULL};
  
  assert(node__link(&n1, first, 0) == NULL);
  assert(n1._children[0] == first);
  
  free(first);
  
  printf("\t Ok!\n");
}

static void test_node__unlink(void){
  printf("%s", __func__);

  struct node_t * removed = malloc(sizeof(* removed));

  struct node_t n1 = {._data = 10, ._children[0] = NULL, ._children[1] = removed};

  assert(node__unlink(&n1, 1) == removed);

  free(removed);
  
  printf("\t Ok\n");
}


int main(void){
  test_node__initialize();
  test_node__link();
  test_node__unlink();
  return 0;
}
