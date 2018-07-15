//
// Created by deathshot on 6/23/18.
//

#ifndef MASTER_2_7_DOUBLY_LINKED_LIST_H
#define MASTER_2_7_DOUBLY_LINKED_LIST_H

#include <stddef.h>
#include "../cda.h"

typedef struct enq_item_s {
    struct enq_item_s *flink;
    struct enq_item_s *blink;
    char              *name;
} ENQ_ITEM_t, *ENQ_ITEM_p_t;

typedef ENQ_ITEM_t ENQ_ANCHOR_t, *ENQ_ANCHOR_p_t;

#define ENQ_GET_HEAD(list)              ((list)->flink)
#define ENQ_GET_TAIL(list)              ((list)->blink)
#define ENQ_GET_NEXT(item)              ((item)->flink)
#define ENQ_GET_LIST_NAME(list)         ((const char *)((list)->name))
#define ENQ_GET_ITEM_NAME(item)         ((const char *)((item)->name))

/**
 * Dynamically allocate the space for a new list anchor, and return its
 * address to the caller. The caller is responsible for ultimately freeing
 * the memory by calling <code>ENQ_destroy_list</code> when the list is no
 * longer needed.
 * @param name Name for new list to be created.
 * @return Pointer (Anchor pointer) to the list created.
 */
ENQ_ANCHOR_p_t ENQ_create_list(const char *name);

/**
 * Create an enqueable item and returning it. The caller is responsible for
 * freeing the memory occupied by the item by calling ENQ_destroy_item.
 * @param name Name of the item
 * @param size Size of the item required.
 * @return Size of the item
 */
ENQ_ITEM_p_t  ENQ_create_item(const char *name, size_t size);

/**
 * Determines whether an item is enqueued in a list
 * @param item Item to determine if it's enqueued
 * @return <code>true</code> if it's enqueued else <code>false</code>
 */
CDA_BOOL_t ENQ_is_item_enqued(ENQ_ITEM_p_t item);

/**
 * Determines whether a list is empty.
 * @param list List to verify
 * @return <code>true</code> if list is empty else <code>false</code>
 */
CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t list);

/**
 * This method inserts an item at the head of a list
 * @param list List to insert item at its head
 * @param item Item to be inserted at the head of the list
 * @return Address of the enqueued item.
 */
ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);

/**
 * This method inserts an item at the tail of a list.
 * @param list List to which item is inserted at the tail.
 * @param item Item to insert at the tail of the list.
 * @return Address of the enqueued item.
 */
ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item);

/**
 * Adds an item before a previously enqueued item.
 * @param item Item to add before another item (item passed as second
 *        parameter to this function).
 * @param before Item to which first parameter item is added before.
 * @return Address of enqueued item.
 */
ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before);

/**
 * This function will remove an item from a list and return its address.
 * @param item Item to be removed from a list
 * @return The removed item.
 */
ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item);

/**
 * This function removes the head item of a list and returns its address.
 * @param list List to remove its head.
 * @return Address of the head item removed.
 */
ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list);

/**
 * This function removes the tail item of a list and returns its address.
 * @param list List to remove its tail.
 * @return Address of the tail item removed.
 */
ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list);

/**
 * Function will free the memory associated with the item (parameter).
 * If the item is enqueued it will dequeued before freeing.
 * @param item Item to destroy
 * @return NULL (explicitly)
 */
ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t item);

/**
 * Function will remove all items from a list, and destroy them, leaving
 * the list empty.
 * @param list List to destroy all items (if it has).
 * @return The Address of the list.
 * @Notes All items in the list will be destroyed.
 */
ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list);

/**
 * Function will empty the list, then free the memory occupied by the
 * list anchor.
 * @param list List to destroy
 * @return NULL (this is explicit).
 */
ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list);

#endif //MASTER_2_7_DOUBLY_LINKED_LIST_H








































