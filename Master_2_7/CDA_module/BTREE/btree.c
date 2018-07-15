//
// Created by deathshot on 7/15/18.
//

#include "btree_p.h"

BTREE_ID_t BTREE_create_tree(void) {
    BTREE__CONTROL_p_t tree = CDA_NEW(BTREE__CONTROL_t);
    tree->root = NULL;
    return tree;
}

BTREE_NODE_ID_t BTREE_add_root(BTREE_ID_t tree, void *data) {
    BTREE__NODE_p_t node = CDA_NEW(BTREE__NODE_t);
    CDA_ASSERT(tree->root == NULL);

    node->data   = data;
    node->tree   = tree;
    node->parent = NULL;
    node->left   = NULL;
    node->right  = NULL;
    tree->root   = node;

    return node;
}

BTREE_NODE_ID_t BTREE_add_left(BTREE_NODE_ID_t node, void *data) {
    BTREE__NODE_p_t left = CDA_NEW(BTREE__NODE_t);
    CDA_ASSERT(node->left == NULL);
    CDA_ASSERT(left != NULL);

    left->data   = data;
    left->tree   = node->tree;
    left->parent = node;
    left->left   = NULL;
    left->right  = NULL;
    node->left   = left;

    return left;
}

BTREE_NODE_ID_t BTREE_add_right(BTREE_NODE_ID_t node, void *data) {
    BTREE__NODE_p_t right = CDA_NEW(BTREE__NODE_t);
    CDA_ASSERT(node->right == NULL);
    CDA_ASSERT(right != NULL);

    right->data   = data;
    right->tree   = node->tree;
    right->parent = node;
    right->left   = NULL;
    right->right  = NULL;
    node->right   = right;

    return right;
}

BTREE_NODE_ID_t BTREE_get_root(BTREE_ID_t tree) {
    return tree->root;
}

void *BTREE_get_data(BTREE_NODE_ID_t node) {
    return node->data;
}

BTREE_NODE_ID_t BTREE_get_left(BTREE_NODE_ID_t node) {
    return node->left;
}

BTREE_NODE_ID_t BTREE_get_right(BTREE_NODE_ID_t node) {
    return node->right;
}

CDA_BOOL_t BTREE_is_empty(BTREE_ID_t tree) {
    return tree->root == NULL ? CDA_TRUE : CDA_FALSE;
}

CDA_BOOL_t BTREE_is_leaf(BTREE_NODE_ID_t node) {
    return (node->left == NULL && node->right == NULL) ? CDA_TRUE : CDA_FALSE;
}

BTREE_ID_t BTREE_traverse_tree(BTREE_ID_t tree, BTREE_TRAVERSE_ORDER_e_t order,
                               BTREE_VISIT_PROC_p_t visit_proc) {

}

BTREE_ID_t BTREE_destroy_tree(BTREE_ID_t tree, BTREE_DESTROY_PROC_p_t destroy_proc) {
    BTREE_destroy_subtree(tree->root, destroy_proc);
    CDA_free(tree);
    return BTREE_NULL_ID;
}

BTREE_ID_t BTREE_destroy_subtree(BTREE_NODE_ID_t node, BTREE_DESTROY_PROC_p_t destroy_proc) {
    if (node->left != NULL)
        BTREE_destroy_subtree(node->left, destroy_proc);

    if (node->right != NULL)
        BTREE_destroy_subtree(node->right, destroy_proc);

    if (destroy_proc != NULL)
        destroy_proc(node->data);

    if (node == node->tree->root)
        node->tree->root = NULL;
    else if (node == node->parent->left)
        node->parent->left = NULL;
    else if (node == node->parent->right)
        node->parent->right = NULL;
    else
        CDA_ASSERT(CDA_FALSE);          // uh.... something fishy is going here...!! debug now...

    CDA_free(node);
    return BTREE_NULL_NODE_ID;
}


















