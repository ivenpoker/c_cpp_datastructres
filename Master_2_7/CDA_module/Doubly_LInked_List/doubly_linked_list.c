//
// Created by deathshot on 6/23/18.
//

#include <stdlib.h>
#include <stddef.h>
#include "doubly_linked_list_p.h"
#include "../cda.h"


void *DLL_malloc(size_t size) {
    void *mem = malloc(size);
    if (mem == NULL && size > 0)
        abort();
    return mem;
}

void DLL_free(void *mem) {
    if (mem != NULL)
        free(mem);
}

// Notes the List name is copied into a private buffer
// which is freed when the list is destroyed.

ENQ_ANCHOR_p_t ENQ_create_list(const char *name) {
    ENQ_ANCHOR_p_t list = CDA_NEW(ENQ_ANCHOR_t);
    CDA_ASSERT(list != NULL);

    list->flink = list;
    list->blink = list;
    list->name  = CDA_NEW_STR_IF(name);

    return list;
}

ENQ_ITEM_p_t  ENQ_create_item(const char *name, size_t size) {
    ENQ_ITEM_p_t item = (ENQ_ITEM_p_t)CDA_malloc(size);
    CDA_ASSERT(size >= sizeof(ENQ_ITEM_t));

    item->flink = item;
    item->blink = item;
    item->name  = CDA_NEW_STR_IF(name);
    return item;
}

CDA_BOOL_t ENQ_is_item_enqued(ENQ_ITEM_p_t item) {
    CDA_BOOL_t rcode = (item->flink == item ? CDA_FALSE : CDA_TRUE);
    return rcode;
}

CDA_BOOL_t ENQ_is_list_empty(ENQ_ANCHOR_p_t list) {
    CDA_BOOL_t rcode = (list->flink == list ? CDA_TRUE : CDA_FALSE);
    return rcode;
}


ENQ_ITEM_p_t ENQ_add_head(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item) {
    CDA_ASSERT(!ENQ_is_item_enqued(item));
    CDA_ASSERT(list != NULL);

    item->flink = list->flink;
    item->blink = list;
    list->flink->blink = item;
    list->flink = item;

    return item;
}

ENQ_ITEM_p_t ENQ_add_tail(ENQ_ANCHOR_p_t list, ENQ_ITEM_p_t item) {
    CDA_ASSERT(!ENQ_is_item_enqued(item));
    CDA_ASSERT(list != NULL);

    item->blink = list->blink;
    list->blink->flink = item;
    item->flink = list;
    list->blink = item;

    return item;
}

ENQ_ITEM_p_t ENQ_add_before(ENQ_ITEM_p_t item, ENQ_ITEM_p_t before) {
    CDA_ASSERT(!ENQ_is_item_enqued(item));
    CDA_ASSERT(ENQ_is_item_enqued(before));

    item->flink   = before;
    before->blink->flink = item;
    item->blink = before->blink;
    before->blink = item;

    return item;
}

ENQ_ITEM_p_t ENQ_deq_item(ENQ_ITEM_p_t item) {
    item->blink->flink = item->flink;
    item->flink->blink = item->blink;
    item->flink = item;
    item->blink = item;
    return item;
}

ENQ_ITEM_p_t ENQ_deq_head(ENQ_ANCHOR_p_t list) {
    CDA_ASSERT(list != NULL);
    ENQ_ITEM_p_t head_item = list->flink;
    if (head_item == NULL || head_item == list) return NULL;

    head_item->flink->blink = head_item->blink;
    head_item->blink->flink = head_item->flink;
    head_item->flink = head_item;
    head_item->blink = head_item;

    return head_item;
}

ENQ_ITEM_p_t ENQ_deq_tail(ENQ_ANCHOR_p_t list) {
    CDA_ASSERT(list != NULL);
    ENQ_ITEM_p_t tail_item = list->blink;
    if (tail_item == NULL || tail_item == list) return NULL;

    tail_item->blink->flink = tail_item->flink;
    tail_item->flink->blink = tail_item->blink;
    tail_item->flink = tail_item;
    tail_item->blink = tail_item;

    return tail_item;
}

ENQ_ITEM_p_t ENQ_destroy_item(ENQ_ITEM_p_t item) {
    ENQ_deq_item(item);     // remove item from list
    CDA_free(item->name);   // free item's name
    CDA_free(item);         // free item

    return NULL;
}

ENQ_ANCHOR_p_t ENQ_empty_list(ENQ_ANCHOR_p_t list) {
    while (!ENQ_is_list_empty(list))
        ENQ_destroy_item(list->flink);
    return list;
}

ENQ_ANCHOR_p_t ENQ_destroy_list(ENQ_ANCHOR_p_t list) {
    ENQ_empty_list(list);
    CDA_free(list->name);
    CDA_free(list);

    return NULL;
}













