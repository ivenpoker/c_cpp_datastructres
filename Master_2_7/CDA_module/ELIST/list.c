//
// Created by deathshot on 6/28/18.
//

#include "list_p.h"


LIST_ID_t ELIST_create_list(size_t max_list_size, size_t entry_size, const char *name) {
    LIST__CONTROL_p_t list = CDA_NEW(LIST__CONTROL_t);
    list->anchor     = ENQ_create_list(name);
    list->max_size   = max_list_size;
    list->entry_size = entry_size;
    list->name       = CDA_NEW_STR_IF(name);
    return list;
}

const void *ELIST_add_entry(LIST_ID_t list, const void *data) {
    LIST__ENTRY_p_t entry = (LIST__ENTRY_p_t) ENQ_create_item(NULL, sizeof(LIST__ENTRY_t));

    entry->data = CDA_malloc(list->entry_size);
    memmove(entry->data, data, list->entry_size);
    ENQ_add_tail(list->anchor, (ENQ_ITEM_p_t) entry);

    return data;
}

size_t ELIST_get_list_size(LIST_ID_t list) {
    size_t      rcode = 0;
    ENQ_ITEM_p_t item = ENQ_GET_HEAD(list->anchor);
    while (item != list->anchor) {
        ++rcode;
        item = ENQ_GET_NEXT(item);
    }
    return rcode;
}

LIST_ID_t ELIST_traverse_list(LIST_ID_t list, LIST_TRAVERSAL_PROC_p_t traversal_proc) {
    ENQ_ITEM_p_t item = ENQ_GET_HEAD(list->anchor);
    while (item != list->anchor) {
        LIST__ENTRY_p_t entry = (LIST__ENTRY_p_t) item;
        if (traversal_proc != NULL)
            traversal_proc(entry->data);
        item = ENQ_GET_NEXT(item);
    }
    return list;
}

LIST_ID_t ELIST_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc) {
    while (!ENQ_is_list_empty(list->anchor)) {
        LIST__ENTRY_p_t entry = (LIST__ENTRY_p_t) ENQ_deq_head(list->anchor);
        if (destroy_proc != NULL)
            destroy_proc(entry->data);
        CDA_free(entry->data);
        ENQ_destroy_item((ENQ_ITEM_p_t) entry);
    }
    return list;
}