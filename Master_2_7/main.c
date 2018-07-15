#include <stdio.h>
#include "CDA_module/QUEUE/queue.h"

//static char *reverse_chars(char *string);
//
//int main(void) {
//    QUEUE_ID_t queue1 = QUEUE_create_queue("Names of persons");
//    QUEUE_append(queue1, QUEUE_create_item("ivenstein", "ivenstein"));
//    QUEUE_append(queue1, QUEUE_create_item("deathshot", "deathshot"));
//    QUEUE_append(queue1, QUEUE_create_item("killshot", "killshot"));
//    QUEUE_append(queue1, QUEUE_create_item("jonathan smith", "jonathan smith"));
//    QUEUE_append(queue1, QUEUE_create_item("kingdom", "person"));
//    QUEUE_append(queue1, QUEUE_create_item("happi", "happi"));
//    QUEUE_append(queue1, QUEUE_create_item("testing", "testing"));
//    QUEUE_append(queue1, QUEUE_create_item("walking", "tinskd"));
//
//    QUEUE_traverse_queue(queue1, reverse_chars);
//
//    int i = 0;
//    QUEUE_ITEM_p_t item;
//    while (!QUEUE_is_queue_empty(queue1)) {
//        item = QUEUE_retrieve(queue1);
//        printf("Data %02d: %s\n", i, item->item.name);
//        ++i;
//        if (i == 13) break;
//    }
//    if (QUEUE_is_queue_empty(queue1)) {
//        printf("\n\nThe queue is now empty!");
//    } else {
//        printf("\n\nThe queue is not empty!");
//    }
//}
//
//static char *reverse_chars(char *string) {
//    char *temp = string;
//    char stack[50];
//    char *sptr = stack;
//    while (*temp != '\000')
//        *sptr++ = *temp++;
//    temp = string;
//    while (sptr != stack)
//        *temp++ = *--sptr;
//    return string;
//}