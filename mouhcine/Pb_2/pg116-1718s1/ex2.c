
/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>

struct dequeue {
  struct link * l;
};

/* RAPPEL : la dequeue ne peut contenir QUE des entiers positifs ou
   nuls. */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/* Mettre en œuvre les fonctions de la dequeue ci-dessous, utilisant
   UNIQUEMENT les fonctions de `struct link` et `struct array`. */

/**
 * Retourne une dequeue vide.
 **/
struct dequeue * dequeue__empty()
    ;

/**
 * Retourne vraie si dequeue est vide sinon faux.
 **/
int dequeue__is_empty(struct dequeue const * dequeue)
    ;

/**
 * Retourne l'élément en tête de dequeue et -1 en cas d'erreur.
 **/
int dequeue__front(struct dequeue const * dequeue)
    ;

/**
 * Retourne le nombre d'éléments stockés.
 **/
size_t dequeue__size(struct dequeue const * dequeue)
    ;

/**
 * Libère la mémoire allouée pour la dequeue.
 **/
void dequeue__free(struct dequeue * dequeue)
    ;

/**
 * Ajoute x en tête de la dequeue,
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int dequeue__push_front(struct dequeue * dequeue, int x)
    ;


