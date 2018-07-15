//
// Created by deathshot on 7/15/18.
//

#ifndef MASTER_2_7_BTREE_H
#define MASTER_2_7_BTREE_H

#include "../cda.h"

#define BTREE_NULL_ID               (NULL)
#define BTREE_NULL_NODE_ID          (NULL)

typedef void BTREE_DESTROY_PROC_t(void *data);
typedef BTREE_DESTROY_PROC_t *BTREE_DESTROY_PROC_p_t;

typedef void BTREE_VISIT_PROC_t(void *data);
typedef BTREE_VISIT_PROC_t *BTREE_VISIT_PROC_p_t;

typedef struct btree__control_s *BTREE_ID_t;
typedef struct btree__node_s    *BTREE_NODE_ID_t;

typedef enum btree_traverse_order_e {
    BTREE_PREODER,
    BTREE_INORDER,
    BTREE_POSTORDER
} BTREE_TRAVERSE_ORDER_e_t;

/**
 * Function will create an emtpy binary tree and returns its ID.
 * @return ID for a newly created binary tree.
 * @exceptions: Throws <code>SIGBART</code> if tree cannot be created.
 */
BTREE_ID_t BTREE_create_tree(void);

/**
 * Function wil add the root node to a tree, the tree must not already
 * have a root node.
 * @param tree Tree to add a root node to.
 * @param data User data to be stored with the node
 * @exceptions: Throws <code>SIGABRT</code> if the node can't be created.
 * @notes: Tree must be empty when this routine is called.
 * @return ID to the newly create node.
 */
BTREE_NODE_ID_t BTREE_add_root(BTREE_ID_t tree, void *data);

/**
 * Function will add a left child to a node;  the node must not
 * already have a left child.
 * @param node ID of node to which to add
 * @param data User data to be associated with this node
 * @exceptions Throws <code>SIGABRT</code> if node cannot be created.
 * @notes The node must not already have a left child
 * @return ID of a new node (new left node).
 */
BTREE_NODE_ID_t BTREE_add_left(BTREE_NODE_ID_t node, void *data);

/**
 * Function will add a right child to a node; the node must not
 * already have a right child.
 * @param node ID of node to which to add
 * @param data User data to be associated with this node
 * @exceptions Throws <code>SIGABRT</code> if node cannot be created.
 * @notes The node must not already have a left child
 * @return ID of a new node (new right node).
 */
BTREE_NODE_ID_t BTREE_add_right(BTREE_NODE_ID_t node, void *data);

/**
 * Function will return the root node of a tree
 * @param tree Tree to get its root node.
 * @exceptions None
 * @Notes None
 * @return ID of root node; <code>BTREE_NODE_NULL</code> if tree is empty
 */
BTREE_NODE_ID_t BTREE_get_root(BTREE_ID_t tree);

/**
 * Function returns data held by a node.
 * @param node Node (its ID) to get associated data.
 * @return Node's data
 */
void *BTREE_get_data(BTREE_NODE_ID_t node);

/**
 * Function returns the left node associated with <code>node</code> passed
 * as parameter
 * @param node Node (its ID) to get its left node.
 * @return Left child associated with the node, returns <code>BTREE_NULL_NODE</code>
 *         if there is not relevant child.
 */
BTREE_NODE_ID_t BTREE_get_left(BTREE_NODE_ID_t node);

/**
 * Function returns the right node associated with <code>node</code> passed
 * as parameter
 * @param node Node (its ID) to get its right node.
 * @return Right child associated with the node, returns <code>BTREE_NULL_NODE</code>
 *         if there is not relevant child.
 */
BTREE_NODE_ID_t BTREE_get_right(BTREE_NODE_ID_t node);

/**
 * Returns true if the tree is empty. (Tree is empty if it has no root node
 * @param tree  ID of tree to test
 * @exceptions None.
 * @Notes None.
 * @return <code>CDA_TRUE</code> if tree is empty,
 *         <code>CDA_FALSE</code> otherwise.
 *
 */
CDA_BOOL_t BTREE_is_empty(BTREE_ID_t tree);

/**
 * Function will return true if a node is a leaf (ie. if the node has no
 * children).
 * @param node ID of node to test.
 * @exceptions: None.
 * @return <code>CDA_TRUE</code> if node is a leaf, <code>CDA_FALSE</code>
 *         otherwise.
 */
CDA_BOOL_t BTREE_is_leaf(BTREE_NODE_ID_t node);

/**
 * Function will traverse a tree (<code>tree</code>) in the order <code>order</code>
 * applying the procedure <code>visit_proc</code> to every node in the tree.
 * @param tree Tree to traverse
 * @param order Traversing order to use.
 * @param visit_proc Procedure to apply on each node during traversal
 * @exceptoins None.
 * @Notes 1. Order may be <code>BTREE_INORDER</code>, <code>BTREE_PREORDER</code> or
 *           <code>BTREE_POSTORDER</code>. <br/><br/>
 *        2. Each time <code>visit_proc</code> is called, the data associated with the node
 *           is passed.
 * @return <code>tree</code>
 */
BTREE_ID_t BTREE_traverse_tree(BTREE_ID_t tree, BTREE_TRAVERSE_ORDER_e_t order,
                               BTREE_VISIT_PROC_p_t visit_proc);

/**
 * Function will destroy a tree. Each node in tree is visited and freed. Prior to destroying
 * a node, the caller is given the opportunity to free resources associated with a node's
 * data via an optional destroy procedure.
 * @param tree Tree to destroy.
 * @param destroy_proc Procedure (optional) to use during destruction.
 * @notes: <code>NULL</code> may be passed in place of <code>destroy_proc</code>
 * @return <code>BTREE_destroy_tree</code> returns <code>BTREE_NULL_ID</code>
 */
BTREE_ID_t BTREE_destroy_tree(BTREE_ID_t tree, BTREE_DESTROY_PROC_p_t destroy_proc);

/**
 * Function will destroy a subtree. Each node in tree is visited and freed. Prior to
 * destroying a node, the caller is given the opportunity to free resources associated
 * with a node's data via an optional destroy procedure.
 * @exceptions: None.
 * @param node Root of subtree to destroy.
 * @param destroy_proc Procedure (optional) to use during destruction.
 * @return
 */
BTREE_ID_t BTREE_destroy_subtree(BTREE_NODE_ID_t node, BTREE_DESTROY_PROC_p_t destroy_proc);










#endif //MASTER_2_7_BTREE_H
