//
// Created by deathshot on 6/28/18.
//

#ifndef MASTER_2_7_ALIST_H
#define MASTER_2_7_ALIST_H

#include <stddef.h>
#include "../LIST/list.h"
typedef struct list__control_s *LIST_ID_t;

/**
 * An array list implementation of a list data structure.
 * @param max_list_size Maximum elements the list can contain
 * @param entry_size Size of an entry in list.
 * @param name Name for the list.
 * @return An ID that can be used to manipulate the list
 */
LIST_ID_t ALIST_create_list(size_t max_list_size, size_t entry_size, const char *name);

/**
 * Add data into list
 * @param list List ID to add data to
 * @param data Data to add to list
 * @return The data passed
 */
const void *ALIST_add_entry(LIST_ID_t list, const void *data);

/**
 * Returns the size of the list.
 * @param list
 * @return
 */
size_t ALIST_get_list_size(LIST_ID_t list);

/**
 * Traverse a list while applying <code>traversal_proc</code> to the data
 * found in the list.
 * @param list List to traverse
 * @param traversal_proc Function to call with data in each List item.
 * @return ID of the List after applying <code>traversal_proc</code>
 */
LIST_ID_t ALIST_traverse_list(LIST_ID_t list, LIST_TRAVERSAL_PROC_p_t traversal_proc);

/**
 * Clear the list by applying user defined procedure <code>destroy_proc</code> to each node
 * in the list.
 * @param list List to clear
 * @param destroy_proc Procedure to apply to list (clearing procedure).
 * @return
 */
LIST_ID_t ALIST_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc);


#endif //MASTER_2_7_LIST_H
