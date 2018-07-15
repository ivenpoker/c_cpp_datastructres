//
// Created by deathshot on 7/4/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static QUEUE_TRAVERSAL_PROC_t traverse;
static QUEUE_TRAVERSAL_PROC_t destroy;

static const char *item_names_[] = {
        "hydrogen", "helium", "lithium", "beryllium", "boron",
        "carbon", "nitrogen", "oxygen", "fluorine", "neon"
};

int main(int argc, char **argv) {
    int            *data = NULL;
    QUEUE_ID_t     qid   = QUEUE_NULL_ID;
    QUEUE_ITEM_p_t item  = NULL;

    qid = QUEUE_create_queue("Queue test");
    for (int inx = 0; inx < CDA_CARD(item_names_); ++inx) {
        data = CDA_malloc(sizeof(int));
        *data = inx;
        item = QUEUE_create_item(item_names_[inx], data);
        QUEUE_append(qid, item);
    }
    QUEUE_traverse_queue(qid, traverse);
    for (int inx = 0; inx < CDA_CARD(item_names_) / 2; ++inx) {
        item = QUEUE_remove(qid);
        printf("Removing %s\n", item->item.name);
        CDA_free(item->data);
        QUEUE_destroy_item(item);
    }
    QUEUE_destroy_queue(qid, destroy);
    return EXIT_SUCCESS;
}

static void traverse(void *data) {
    int *i_data = data;
    printf("Traversing %d\n", *i_data);
}

static void destroy(void *data) {
    int *i_data = data;
    printf("Destroying %d\n", *i_data);
    CDA_free(i_data);
}