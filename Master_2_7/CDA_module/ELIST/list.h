//
// Created by deathshot on 6/28/18.
//

#ifndef MASTER_2_7_ELIST_H
#define MASTER_2_7_ELIST_H

#include <stddef.h>
#include "../LIST/list.h"

typedef struct list__control_s *LIST_ID_t;

/**
 * Creates a List.
 * @param max_list_size Maximum size for the list.
 * @param entry_size    Size of an entry in the list.
 * @param name          Name of the list.
 * @return An ID that can be used to manipulate the list.
 */
LIST_ID_t ELIST_create_list(size_t max_list_size, size_t entry_size, const char *name);

const void *ELIST_add_entry(LIST_ID_t list, const void *data);

size_t ELIST_get_list_size(LIST_ID_t list);

LIST_ID_t ELIST_traverse_list(LIST_ID_t list, LIST_TRAVERSAL_PROC_p_t traversal_proc);

/**
 * Clear the list by applying user defined procedure <code>destroy_proc</code> to each node
 * in the list.
 * @param list List to clear
 * @param destroy_proc Procedure to apply to list (clearing procedure).
 * @return
 */
LIST_ID_t ELIST_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc);

#endif //MASTER_2_7_LIST_H
