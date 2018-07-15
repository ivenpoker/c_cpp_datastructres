//
// Created by deathshot on 6/30/18.
//

#include "queue_p.h"

QUEUE_ID_t QUEUE_create_queue(const char *name) {
    QUE__CONTROL_p_t qid = CDA_NEW(QUE__CONTROL_t);
    qid->anchor = ENQ_create_list(name);
    return qid;
}

QUEUE_ITEM_p_t QUEUE_create_item(const char *name, void *data) {
    QUEUE_ITEM_p_t item = (QUEUE_ITEM_p_t) ENQ_create_item(name, sizeof(QUEUE_ITEM_t));
    item->data = data;
    return item;
}

QUEUE_ID_t QUEUE_clear_queue(QUEUE_ID_t qid, QUEUE_DESTROY_PROC_p_t destroy_proc) {
    QUEUE_ITEM_p_t item = NULL;
    while (!ENQ_is_list_empty(qid->anchor)) {
        item = (QUEUE_ITEM_p_t) ENQ_GET_HEAD(qid->anchor);
        if (destroy_proc != NULL)
            destroy_proc(item);
        QUEUE_destroy_item(item);
    }
    return qid;
}

QUEUE_ITEM_p_t QUEUE_append(QUEUE_ID_t queue, QUEUE_ITEM_p_t item) {
    ENQ_add_tail(queue->anchor, (ENQ_ITEM_p_t) item);
    return item;
}

CDA_BOOL_t QUEUE_is_queue_empty(QUEUE_ID_t queue) {
    return ENQ_is_list_empty(queue->anchor);
}

CDA_BOOL_t QUEUE_is_queue_full(QUEUE_ID_t queue) {
    return CDA_FALSE;
}

QUEUE_ITEM_p_t QUEUE_destroy_item(QUEUE_ITEM_p_t item) {
    ENQ_destroy_item((ENQ_ITEM_p_t) item);
    return NULL;
}

QUEUE_ID_t QUEUE_destroy_queue(QUEUE_ID_t qid, QUEUE_DESTROY_PROC_p_t destroy_proc) {
    QUEUE_clear_queue(qid, destroy_proc);
    ENQ_destroy_list(qid->anchor);
    CDA_free(qid);
    return QUEUE_NULL_ID;
}

QUEUE_ITEM_p_t QUEUE_remove(QUEUE_ID_t queue) {
    if (QUEUE_is_queue_empty(queue)) return NULL;
    QUEUE_ITEM_p_t rcode = (QUEUE_ITEM_p_t) ENQ_deq_head(queue->anchor);
    return rcode;
}

QUEUE_ITEM_p_t QUEUE_retrieve(QUEUE_ID_t queue) {
    if (QUEUE_is_queue_empty(queue)) return NULL;
    QUEUE_ITEM_p_t tmp_item = (QUEUE_ITEM_p_t) ENQ_GET_HEAD(queue->anchor);
    return tmp_item;
}

QUEUE_ID_t QUEUE_traverse_queue(QUEUE_ID_t queue, QUEUE_TRAVERSAL_PROC_p_t traverse_proc) {
    ENQ_ITEM_p_t item =  ENQ_GET_HEAD(queue->anchor);
    while (item !=  queue->anchor) {
        QUEUE_ITEM_p_t entry = (QUEUE_ITEM_p_t) item;
        if (traverse_proc != NULL)
            traverse_proc(entry->data);
    }
    return queue;
}






















































