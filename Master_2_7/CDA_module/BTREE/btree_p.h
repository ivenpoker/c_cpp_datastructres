//
// Created by deathshot on 7/15/18.
//

#ifndef MASTER_2_7_BTREE_P_H
#define MASTER_2_7_BTREE_P_H

#include "btree.h"
typedef struct btree__node_s    *BTREE__NODE_p_t;
typedef struct btree__control_s *BTREE__CONTROL_p_t;

typedef struct btree__node_s {
    void               *data;
    BTREE__CONTROL_p_t  tree;
    BTREE__NODE_p_t     parent;
    BTREE__NODE_p_t     left;
    BTREE__NODE_p_t     right;
} BTREE__NODE_t;

typedef struct btree__control_s {
    BTREE__NODE_p_t root;
} BTREE__CONTROL_t;

#endif //MASTER_2_7_BTREE_P_H
