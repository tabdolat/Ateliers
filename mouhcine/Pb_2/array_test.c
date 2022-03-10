#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"


static void test_array__size(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));

  array__empty(array);

  assert(array->size == 0);
  array->size = 3;

  assert(array__size(array) == 3);

  free(array);
  
  printf("\t Ok \n");
}

static void test_array__push_front(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));

  array__empty(array);

  array__push_front(array, 3);

  assert(array->a[0] == 3);
  assert(array->size == 1);

  assert(array->first == array->a);

  //printf("\t array + sizeof(int) = %p \n array->first = %p \n", array->a + sizeof(int), array->first);
  
  //printf("\t &array = %p \t &first = %p\n", array->a, array->first);
  
  array__push_front(array, 22);

  assert(array->a[0] == 22);
  assert(array->a[1] == 3);
  assert(array->size == 2);
  
  //printf("\t &array = %p \t &first = %p\n", array->a, array->first);
  
  array__push_front(array, -3);
  
  assert(array->a[0] == 22);
  assert(array->size == 2);
  //  assert(array->first == array->a + 2*sizeof(int)); 

  
  free(array);
  
  printf("\t Ok \n");
}


static void test_array__front(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));

  array__empty(array);

  array__push_front(array, 3);  


  free(array);

  printf("\t Ok \n");
}


static void test_array__pop_front(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));

  array__empty(array);


  array__push_front(array, 10);


  
  array__push_front(array, 20);
  array__push_front(array, 30);
  array__push_front(array, 40);

  //  printf("\t Front = %d \t \n", array__front(array));
  
  size_t size = array->size;
  int * begining = array->first;


  
  assert(array__pop_front(array) == 0);
  assert(array->size == size - 1);
  assert( array__front(array) == 30);

  size = array->size;
  


  assert(array__pop_front(array) == 0);
  assert(array->size == size - 1);
  assert( array__front(array) == 20);


  size = array->size;
  
  assert(array__pop_front(array) == 0);
  assert(array->size == size - 1);
  assert( array__front(array) == 10);



  size = array->size;
  
  assert(array__pop_front(array) == 0);
  assert(array->size == size - 1);
  assert(array__pop_front(array) == -1);
  


  free(array);
  
  printf("\t Ok \n");
}


static void test_array__push_back(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));

  array__empty(array);

  array__push_front(array, 10);

  array__push_back(array, 20);

  assert(array->size == 2);

  assert(array->a[0] == 10 && array->a[1] == 20);

  array__push_back(array, 30);
  array__push_back(array, 40);
  array__push_back(array, 50);

  assert(array->a[2] == 30 && array->a[3] == 40 && array->a[4] == 50);

  assert(array__push_back(array, 60) == -1);
  assert(array__push_back(array, -3) == -1);


  free(array);
  
  printf("\t Ok \n");
}

static void test_array__back(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));
  array__empty(array);

  array__push_front(array, 10);
  array__push_front(array, 20);
  array__push_back(array, 30);  

  assert(array__back(array) == 30);

  array__pop_front(array);

  assert(array__back(array) == 30);
  
  free(array);
  printf("\t Ok \n");
}

static void test_array__pop_back(void){
  printf("%s", __func__);

  struct array * array = malloc(sizeof(*array));
  array__empty(array);

  array__push_front(array,10);
  array__push_front(array,20);
  array__push_front(array,30);
  
  assert(array__pop_back(array) == 0);
  assert(array->size == 2);

  assert(array__pop_back(array) == 0);
  assert(array->size == 1);

  assert(array__pop_back(array) == 0);
  assert(array->size == 0);

  assert(array__pop_back(array) == -1);
  assert(array->size == 0);

  free(array);
  printf("\t Ok \n");
}

int main(void){
  test_array__size();
  test_array__push_front();
  test_array__front();
  test_array__pop_front();
  test_array__push_back();
  test_array__back();
  test_array__pop_back();
  return 0;
}
