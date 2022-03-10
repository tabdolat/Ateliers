/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include "array.h"
//#define CAPACITY 5

/* struct array { */
/*   int a[CAPACITY];   // tableau d'entier */
/*   int * first;       // pointeur sur 1er élément */
/*   size_t size;       // nombre d'éléments stockés dans a */
/* }; */

/*
 * Retourne le nombre d'éléments stockés.
 **/
size_t array__size(struct array const * array)
{
  return array->size;
}

/* RAPPEL : un array ne peut contenir QUE des entiers positifs ou
   nuls. */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/* Mettre en œuvre les fonctions de array ci-dessous. */

/*
 * Initialise une structure array à vide.
 **/
void array__empty(struct array * array){
  array->size = 0;
}

/*
 * Ajoute x en tête,
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__push_front(struct array * array, int x){
  if(array->size == CAPACITY || x < 0 ){
    return -1;
  }

  else{
    for(int i = (int)array->size; i > 0; i--){
      array->a[i] = array->a[i-1];
    }
  }
  
  array->first = &(array->a[0]);
  
  array->a[0] = x;

  array->size++;
  
  return 0;
}

  
/*
 * Retourne l'élément en tête ou -1 en cas d'erreur.
 **/
int array__front(struct array const * array){
  if(array->size == 0){
    return -1;
  }
  return *(array->first);
}


/*
 * Retire l'élement en tête, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__pop_front(struct array * array){
  if( array->size == 0 ){
    return -1;
  }
  for(int i=0; i < (int)array->size -1 ; i++){
    array->a[i] = array->a[i+1];
  }
  array->first = array->a;
  array->size--;
  return 0;
}

/*
 * Ajoute x en queue, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__push_back(struct array * array, int x){
  if( array->size == CAPACITY || x < 0){
    return -1;
  }

  array->a[array->size] = x;

  array->size++;
  
  return 0;
  
}

/*
 * Retourne l'élément en queue ou -1 en cas d'erreur.
 **/
int array__back(struct array const * array){
  if(array->size == 0){
    return -1;
  }
  return array->a[(int)array->size-1];
}

/*
 * Retire l'élement en tête, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__pop_back(struct array * array){
  if( array->size == 0 ){
    return -1;
    }
  array->size--;
  return 0;
}
