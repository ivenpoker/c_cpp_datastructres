//
// Created by deathshot on 6/23/18.
//

#include <stdio.h>
#include "../../cda.h"
#include "../doubly_linked_list.h"
#include "tips_p.h"

#define NOT_FOUND           (0)
#define FOUND_EXACT         (1)
#define FOUND_GREATER       (2)

typedef struct receipts_s {
    ENQ_ITEM_p_t item;
    double       check_total;
    double       tip_total;
    int          num_receipts;
} RECEIPTS_t, *RECEIPTS_p_t;

static const char *tips_list_name = "TIP Queue";
static ENQ_ANCHOR_p_t anchor = NULL;

void TIPS_init(void) {
    CDA_ASSERT(anchor == NULL);
    anchor = ENQ_create_list(tips_list_name);
}

void TIPS_add_receipt(const char *wait_person, double check, double tips) {
    RECEIPTS_p_t receipts = NULL;
    RECEIPTS_p_t bucket   = NULL;
    int          results  = NOT_FOUND;
    int          compare  = 0;

    CDA_ASSERT(anchor != NULL);

    receipts = (RECEIPTS_p_t) ENQ_GET_HEAD(anchor);
    while ((results == NOT_FOUND) && ((ENQ_ANCHOR_p_t) receipts != anchor)) {
        compare = strcmp(wait_person, ENQ_GET_ITEM_NAME((ENQ_ITEM_p_t) receipts));
        if (compare == 0) results = FOUND_EXACT;
        else if (compare < 0) results = FOUND_GREATER;
        else results = (RECEIPTS_p_t) ENQ_GET_NEXT((ENQ_ITEM_p_t) receipts);
    }
    switch (results) {

        case FOUND_EXACT:
            receipts->check_total += check;
            receipts->tip_total   += tips;
            ++receipts->num_receipts;
            break;

        case FOUND_GREATER:
            bucket = (RECEIPTS_p_t) ENQ_create_item(wait_person, sizeof(RECEIPTS_p_t));
            bucket->check_total  = check;
            bucket->tip_total    = tips;
            bucket->num_receipts = 1;
            ENQ_add_before((ENQ_ITEM_p_t) bucket, (ENQ_ITEM_p_t) receipts);
            break;

        case NOT_FOUND:
            bucket = (RECEIPTS_p_t) ENQ_create_item(wait_person, sizeof(RECEIPTS_p_t));
            bucket->check_total  = check;
            bucket->tip_total    = tips;
            bucket->num_receipts = 1;
            ENQ_add_tail(anchor, (ENQ_ITEM_p_t) bucket);
            break;

        default:
            CDA_ASSERT(CDA_FALSE);
            break;
    }
}

void TIPS_print_receipts(void) {

    RECEIPTS_p_t receipts = NULL;
    CDA_ASSERT(anchor != NULL);

    receipts = (RECEIPTS_p_t) ENQ_GET_HEAD(anchor);
    while (receipts != (RECEIPTS_p_t) anchor) {
        printf("%s\n", ENQ_GET_ITEM_NAME((ENQ_ITEM_p_t) receipts));
        printf("Total receipts: %.2f (Average: %.2f)\n",
                    receipts->check_total,
                    receipts->check_total / receipts->num_receipts);
        printf("Total tips: %.2f (Average: %.2f)\n",
                    receipts->tip_total,
                    receipts->tip_total / receipts->num_receipts);
        printf("\n");
        receipts = (RECEIPTS_p_t) ENQ_GET_NEXT((ENQ_ITEM_p_t) receipts);
    }
}

void TIPS_close(void) {

    CDA_ASSERT(anchor != NULL);
    ENQ_destroy_list(anchor);
    anchor = NULL;
}



























