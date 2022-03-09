#include "node.h"
#include "ntree.h"
#include <stdio.h>
#include <assert.h>


/* Exercice 1 */

void test_node__initialize(void)
{
    printf("%s", __func__);
    
    struct node_t *n = malloc(sizeof(struct node_t));

    node__initialize(n, 5);

    assert(n->_data == 5);

    free(n);
    
    printf("\tOK\n");
}

void test_node__link(void)
{
    printf("%s", __func__);

    struct node_t *n1 = malloc(sizeof(struct node_t));
    struct node_t *n2 = malloc(sizeof(struct node_t));

    node__initialize(n1, 5);
    node__initialize(n2, 10);

    node__link(n1, n2, 1);

    assert(n1->_children[1] == n2);

    free(n1);
    free(n2);

    printf("\tOK\n");
}

void test_node__unlink(void)
{
    printf("%s", __func__);

    struct node_t *n1 = malloc(sizeof(struct node_t));
    struct node_t *n2 = malloc(sizeof(struct node_t));
    struct node_t *n3 = malloc(sizeof(struct node_t));


    node__initialize(n1, 5);
    node__initialize(n2, 10);
    node__initialize(n3, 15);

    node__link(n1, n2, 1);
    node__link(n1, n3, 0);

    assert(n1->_children[1] == n2);
    assert(n1->_children[0] == n3);

    node__unlink(n1, 0);

    assert(n1->_children[0] != n3);    

    free(n1);
    free(n2);  
    free(n3);  

    printf("\tOK\n");
}

/* Exercice 2 */

void test_ntree__empty(void)
{
    printf("%s", __func__);

    struct ntree_t * tree = ntree__empty();

    assert(node__is_empty(tree->_root));

    ntree__free(tree);

    printf("\tOK\n");
}


void test_ntree__free(void)
{
    printf("%s", __func__);

    struct ntree_t * tree = ntree__empty();

    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *n2 = malloc(sizeof(struct node_t));
    struct node_t *n3 = malloc(sizeof(struct node_t));
    struct node_t *n4 = malloc(sizeof(struct node_t));
    struct node_t *n5 = malloc(sizeof(struct node_t));
    struct node_t *n6 = malloc(sizeof(struct node_t));
    struct node_t *n7 = malloc(sizeof(struct node_t));

    node__initialize(root, 1);
    node__initialize(n2, 11);
    node__initialize(n3, 22);
    node__initialize(n4, 33);
    node__initialize(n5, 44);
    node__initialize(n6, 55);
    node__initialize(n7, 66);

    tree->_root = root;

    node__link(root, n2, FIRST_CHILD);
    node__link(n2, n3, FIRST_CHILD);
    node__link(n2, n4, NEXT_SIBLING);
    node__link(n3, n5, FIRST_CHILD);
    node__link(n3, n6, NEXT_SIBLING);
    node__link(n5, n7, FIRST_CHILD);

    ntree__free(tree);    

    printf("\tOK\n");
}

/* Exercice 03 */
void test_children__next(void)
{
    printf("%s", __func__);

    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *n2 = malloc(sizeof(struct node_t));
    struct node_t *n3 = malloc(sizeof(struct node_t));
    struct node_t *n4 = malloc(sizeof(struct node_t));

    node__initialize(root, 1);
    node__initialize(n2, 11);
    node__initialize(n3, 22);
    node__initialize(n4, 33);

    node__link(root, n2, 0);
    node__link(n2, n3, 1);
    node__link(n3, n4, 1);

    struct children_t *child = malloc(sizeof(*child));
    child->_current = n2;

    children__next(child);

    assert(child->_current == n3);

    free(root);
    free(n2);
    free(n3);
    free(n4);
    free(child);

    printf("\tOK\n");
}

void test_ntree__children(void)
{
    printf("%s", __func__);

    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *n2 = malloc(sizeof(struct node_t));
    struct node_t *n3 = malloc(sizeof(struct node_t));
    struct node_t *n4 = malloc(sizeof(struct node_t));

    node__initialize(root, 1);
    node__initialize(n2, 11);
    node__initialize(n3, 22);
    node__initialize(n4, 33);

    node__link(root, n2, 0);
    node__link(n2, n3, 1);
    node__link(n3, n4, 1);

    struct children_t child = ntree__children(root);

    assert(child._current == n2);
    assert(child._current->_children[NEXT_SIBLING] == n3);
    
    free(root);
    free(n2);
    free(n3);
    free(n4);

    printf("\tOK\n");
}

int main()
{
    test_node__initialize();

    test_node__link();

    test_node__unlink();

    test_ntree__free();

    test_children__next();

    test_ntree__children();

    return 0;
}