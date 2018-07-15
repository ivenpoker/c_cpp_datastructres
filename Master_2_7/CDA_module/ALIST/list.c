//
// Created by deathshot on 6/28/18.
//

#include "list_p.h"
#include "../cda.h"

LIST_ID_t ALIST_create_list(size_t max_list_size, size_t entry_size, const char *name) {
    LIST__CONTROL_p_t list = CDA_NEW(LIST__CONTROL_t);
    list->array      = CDA_calloc(max_list_size, entry_size);
    list->max_size   = max_list_size;
    list->entry_size = entry_size;
    list->next       = 0;
    list->name       = CDA_NEW_STR_IF(name);

    return list;
}

const void *ALIST_add_entry(LIST_ID_t list, const void *data) {
    LIST__ENTRY_p_t next_entry = list->array + list->next * list->entry_size;
    if (list->next >= (int) list->max_size)
        abort();
    memmove(next_entry, data, list->entry_size);
    ++list->next;
    return data;
}

size_t ALIST_get_list_size(LIST_ID_t list) {
    size_t rcode = (size_t) list->next;
    return rcode;
}

LIST_ID_t ALIST_traverse_list(LIST_ID_t list, LIST_TRAVERSAL_PROC_p_t traversal_proc) {
    LIST__ENTRY_p_t entry = list->array;
    for (int inx = 0; inx < list->next; ++inx) {
        if (traversal_proc != NULL)
            traversal_proc(entry);
        entry += list->entry_size;
    }
    return list;
}

LIST_ID_t ALIST_clear_list(LIST_ID_t list, LIST_DESTROY_PROC_p_t destroy_proc) {
    for (int inx = 0; inx < list->next; ++inx) {
        if (destroy_proc != NULL)
            destroy_proc(list->array + inx * list->entry_size);
    }
    list->next = 0;
    return list;
}