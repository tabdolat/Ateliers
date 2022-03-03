#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node_t * node__empty(void){
    struct node_t *nd=malloc(sizeof(struct node_t));
    nd->_data=0;
    nd->_children=NULL;
}

void node__initialize(struct node_t * n, int x){
    if(node__is_empty(n)){
        n->_data=x;
        n->_children=NULL;
    }
}

int node__is_empty(struct node_t const * n){
    return n->_children==NULL;
}

int node__data(struct node_t const * n){
    return n->_data;
}

struct node_t * node__child(struct node_t const * n, unsigned d){
    if (node__is_empty(n) || d > 1 ){
        return NULL;
    }
    return n->_children[d];
}

struct node_t * node__link(struct node_t * n1, struct node_t * n2, unsigned d){
    if (node__is_empty(n1) || d > 1 ){
        return NULL;
    }
    struct node_t *n=n1->_children[d];
    n1->_children[d]=n2;
    return n; 
}

struct node_t * node__unlink(struct node_t * n, unsigned d){
    if (node__is_empty(n) || d > 1 ){
        return NULL;
    }
    struct node_t *nd=n->_children[d];
    n->_children[d]=node__empty();
    return nd;
}
