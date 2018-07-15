//
// Created by deathshot on 6/24/18.
//

#ifndef MASTER_2_7_MAIN_LIST_H
#define MASTER_2_7_MAIN_LIST_H

#include <stddef.h>
#include "../cda.h"

#define LIST_NULL_ID            (NULL)
typedef struct list__control_s *LIST_ID_t;

typedef void LIST_DESTROY_PROC_t(void *);
typedef LIST_DESTROY_PROC_t *LIST_DESTROY_PROC_p_t;

typedef void LIST_TRAVERSAL_PROC_t(void *);
typedef LIST_TRAVERSAL_PROC_t *LIST_TRAVERSAL_PROC_p_t;


/**
 * Creates a List ADT.
 * @param max_list_size Maximum size for the list (a hint).
 * @param entry_size Maximum for an entry in list.
 * @param name Name for the list.
 * @return An ID for the new List created.
 * @exceptions Throws SIGABRT if the list can't be created.
 * @notes The caller is responsible for freeing the memory occupied
 *        by the list by calling <code>LIST_destroy_list</code><br/><br/>
 *        Following creation, the list is guaranteed to hold at least
 *        <code>max_list_size</code> entries; it may be able to hold
 *        more. See also <code>LIST_add_entry</code>.
 *
 */
LIST_ID_t LIST_create_list(size_t max_list_size, size_t entry_size, const char *name);

/**
 * Adds an entry to the end of the list.
 * @param list List to add entry at it's end.
 * @param data Data to be appended to list tail.
 * @return data
 * @exceptions Throws <code>SIGABRT</code> if the new entry can't be created.
 * @Notes The data argument must point to a block of memory equal in size to
 *        entry size as specified in LIST_create_list. A new entry is created
 *        for the list and the data is COPIED INTO IT.
 */
LIST_ID_t LIST_add_entry(LIST_ID_t list, const void *data);

/**
 * Traverses the list in order, calling the user's traversal proc at each node.
 * @param list ID of a previously created list
 * @param traversal_proc Function to call for each node
 * @return list
 * @exception None
 * @notes For consistency with other modules and methods, the traversal proc may be
 *        <code>NULL</code>.
 */
LIST_ID_t LIST_traverse_list(LIST_ID_t list, LIST_TRAVERSAL_PROC_p_t traversal_proc);


/**
 * Determines whether a list is empty. Returns boolean.
 * @param list List to check if it's empty
 * @return <code>CDA_TRUE</code> if the list is empty, <code>CDA_FALSE</code> otherwise
 * @exceptons None
 * @Notes None
 */
CDA_BOOL_t LIST_is_list_empty(LIST_ID_t list);

/**
 * Returns a Boolean value indicating whether a list is full.
 * @param list ID of a previously created list.
 * @return <code>CDA_TRUE</code> if list is full, <code>CDA_FALSE</code> otherwise.
 * @exceptoins None
 * @notes None
 */
CDA_BOOL_t LIST_is_list_full(LIST_ID_t list);

/**
 * Returns a list to its initial, empty state, destroying each node in the process.
 * If a destroy proc is specified, it will be called for each node in the list
 * prior to destroying the node.
 * @param list ID of a previously created list
 * @param destroy_proc function to call for each node.
 * @return List
 * @exceptions None
 * @notes If not needed, the destroy proc may be <code>NULL</code>
 */
LIST_ID_t LISt_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_t destroy_proc);

/**
 * Function will first clear list (see <code>LIST_clear_list</code>) and then destroy the list
 * itself. If a destroy proc is specified, it will be called for each node in the list
 * prior to destroying the node.
 * @param list
 * @param destroy_proc
 * @return <code></code>
 * @exceptions None
 * @notes If not needed, the destroy proc may be <code>NULL</code>
 */
LIST_ID_t  LIST_destroy_list(LIST_ID_t list, LIST_DESTROY_PROC_t destroy_proc);

#endif //MASTER_2_7_LIST_H



















































































