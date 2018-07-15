//
// Created by deathshot on 6/28/18.
//

#ifndef MASTER_2_7_LIST_P_H
#define MASTER_2_7_LIST_P_H

#include "list.h"
#include <stddef.h>

typedef char *LIST__ENTRY_p_t;
typedef struct list__control_s {
    LIST__ENTRY_p_t array;
    size_t          max_size;
    size_t          entry_size;
    int             next;
    char            *name;
} LIST__CONTROL_t, *LIST__CONTROL_p_t;

#endif //MASTER_2_7_LIST_P_H
