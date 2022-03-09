#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ntree.h"

static void test_children__current(void){
  printf("%s", __func__);

  struct children_t * children  = malloc(sizeof(*children));

  struct node_t * current = malloc(sizeof(*current));

  current->_data = 23;

  current->_children[FIRST_CHILD] = node__empty();
  current->_children[NEXT_SIBLING] = node__empty();

  children->_current = current;
  
  assert(children__current(children)->_data == 23);

  free(children);
  free(current);

  printf("\t Ok\n");
}


static void test_children__next(void){
  printf("%s", __func__);

  struct children_t * children  = malloc(sizeof(*children));

  struct node_t * current = malloc(sizeof(*current));

  struct node_t * first_brother = malloc(sizeof(*first_brother));

  struct node_t * second_brother = malloc(sizeof(*second_brother));
  
  current->_data = 10;

  first_brother->_data = 20;

  second_brother->_data = 30;

  current->_children[NEXT_SIBLING] = first_brother;
  current->_children[NEXT_SIBLING]->_children[NEXT_SIBLING] = second_brother;

  children->_current = current;

  children__next(children);

  assert( children->_current->_data == 20 );

  children__next(children);

  assert( children->_current->_data == 30 );

  free(children);
  free(current);
  free(first_brother);
  free(second_brother);
  
  printf("\t Ok\n");
}



static void test_ntree__children(void){
  printf("%s", __func__);

  struct node_t * node = malloc(sizeof(*node));

  struct node_t * first_children = malloc(sizeof(*first_children));

  struct node_t * second_children = malloc(sizeof(*second_children));
  struct node_t * third_children = malloc(sizeof(*third_children));

  node->_data = 10;

  first_children->_data = 20;

  second_children->_data = 30;

  third_children->_data = 40;

  node->_children[FIRST_CHILD] = first_children;

  first_children->_children[NEXT_SIBLING] = second_children;

  second_children->_children[NEXT_SIBLING] = third_children;

  assert(ntree__children(node)._current->_data == 20);

  struct children_t childs;

  childs._current = NULL;

  assert(children__is_empty(&childs));

  childs = ntree__children(node);


  
  children__next(&childs);


  
  assert(childs._current->_data == 30);

  children__next(&childs);

  assert(childs._current->_data == 40);

  free(node);
  free(first_children);
  free(second_children);
  free(third_children);
  
  printf("\t Ok \n");
}


int main(void){

  test_children__current();
  test_children__next();
  test_ntree__children();

  return 0;
}
