//
// Created by deathshot on 6/30/18.
//

#ifndef MASTER_2_7_QUEUE_H
#define MASTER_2_7_QUEUE_H

#define QUEUE_NULL_ID            (NULL)
#include "../Doubly_LInked_List/doubly_linked_list.h"

typedef struct que__control_s *QUEUE_ID_t;
typedef struct que_item_s {
    ENQ_ITEM_t item;
    void       *data;
} QUEUE_ITEM_t, *QUEUE_ITEM_p_t;

typedef void QUEUE_DESTROY_PROC_t(void *);
typedef QUEUE_DESTROY_PROC_t *QUEUE_DESTROY_PROC_p_t;

typedef void QUEUE_TRAVERSAL_PROC_t(void *);
typedef QUEUE_TRAVERSAL_PROC_t *QUEUE_TRAVERSAL_PROC_p_t;


/**
 * Creates a new queue, and returns the user and ID to use in
 * future operations.
 * @param name Name for the new queue.
 * @return ID of the newly created queue.
 * @throws Throws <code>SIGABRT</code> if the queue cannot be created.
 */
QUEUE_ID_t QUEUE_create_queue(const char *name);

/**
 * Creates a queue item containing the user's data.
 * @param name Name of the item to create; may be <code>NULL</code>
 * @param data user's data
 * @return Address of queue item
 * @exceptions: Throws <code>SIGABRT</code> if the item cannot be created
 */
QUEUE_ITEM_p_t QUEUE_create_item(const char *name, void *data);

/**
 * Destroys all the items in a queue, leaving the queue empty
 * @param qid ID of the queue to clear.
 * @param destroy_proc Address of procedure <code>destroy_proc</code>; may be NULL
 * @return Queue ID
 * @notes:   If the data contained in the queue items requires cleanup, the
 *           caller should pass the address of a clean up function as the
 *           destroy proc argument. If non-NULL, the clean up function will be
 *           called once for each item in the queue, passing the data from the
 *           item.
 */
QUEUE_ID_t QUEUE_clear_queue(QUEUE_ID_t qid, QUEUE_DESTROY_PROC_p_t destroy_proc);

/**
 * Appends <code>item</code> to the queue (at the end).
 * @param queue Queue to append <code>item</code> to (this is the queue's ID)
 * @param item Item to append at the end of the queue.
 * @return Address of the newly append item in the queue.
 */
QUEUE_ITEM_p_t QUEUE_append(QUEUE_ID_t queue, QUEUE_ITEM_p_t item);

/**
 * Checks if the queue <code>queue</code> is emtpy.
 * @param queue Queue to check if its empty.
 * @return <code>CDA_TRUE</code> if the Queue is empty else, <code>CDA_FALSE</code>
 */
CDA_BOOL_t QUEUE_is_queue_empty(QUEUE_ID_t queue);

/**
 * Checks if the queue is full
 * @param queue Queue to check if it's full
 * @return Always return <code>CDA_FALSE</code>
 */
CDA_BOOL_t QUEUE_is_queue_full(QUEUE_ID_t queue);

/**
 * Destroys an item (<code>item</code>) from the Queue.
 * @param item Item to destroy form queue.
 * @return <code>NULL</code>
 */
QUEUE_ITEM_p_t QUEUE_destroy_item(QUEUE_ITEM_p_t item);

/**
 * Destroys a queue, by applying <code>destroy_proc</code> to each data
 * found within the queue.
 * @param qid ID of the queue to destroy
 * @param destroy_proc Function (or procedure) to call on each data found in queue.
 * @return ID of the destroyed queue.
 */
QUEUE_ID_t QUEUE_destroy_queue(QUEUE_ID_t qid, QUEUE_DESTROY_PROC_p_t destroy_proc);

/**
 * Removes and returns the first item in the queue.
 * @param queue
 * @return First item in the queue.
 */
QUEUE_ITEM_p_t  QUEUE_remove(QUEUE_ID_t queue);

/**
 * Returns, without removing the first item in the queue.
 * @param queue Queue to get the first item.
 * @return First item in queue, without removing the item.
 */
QUEUE_ITEM_p_t QUEUE_retrieve(QUEUE_ID_t queue);

/**
 * Traverses the queue using and for each item in the queue,
 * calls the <code>traverse_proc</code>.
 * @param queue
 * @param traverse_proc
 * @return ID for the queue that has been traversed.
 */
QUEUE_ID_t QUEUE_traverse_queue(QUEUE_ID_t queue, QUEUE_TRAVERSAL_PROC_p_t traverse_proc);

#endif //MASTER_2_7_QUEUE_H














































