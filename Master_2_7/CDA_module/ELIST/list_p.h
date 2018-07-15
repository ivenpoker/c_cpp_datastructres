//
// Created by deathshot on 6/28/18.
//

#ifndef MASTER_2_7_LIST_P_H
#define MASTER_2_7_LIST_P_H

#include "list.h"
#include "../Doubly_LInked_List/doubly_linked_list.h"
#include "../cda.h"
#include <stddef.h>

typedef struct list__control_s {
    ENQ_ANCHOR_p_t anchor;
    size_t         max_size;
    size_t         entry_size;
    char           *name;
} LIST__CONTROL_t, *LIST__CONTROL_p_t;

typedef struct list__entry_s {
    ENQ_ITEM_t item;
    void       *data;
} LIST__ENTRY_t, *LIST__ENTRY_p_t;

#endif //MASTER_2_7_LIST_P_H
